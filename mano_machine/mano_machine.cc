#include "CAProject/mano_machine/mano_machine.hh"
#include "mano_machine.hh"

#include "base/trace.hh"
#include "debug/ManoDebug.hh"
#include "sim/sim_exit.hh"

namespace gem5
{

ManoMachine::ManoMachine(const ManoMachineParams &params) :
    SimObject(params),
    event([this]{ processEvent(); }, name() + ".event"),
    latency(params.cycle_time),
    AR_(*params.ar),
    PC_(*params.pc),
    DR_(*params.dr),
    AC_(*params.ac),
    INPR_(*params.inpr),
    IR_(*params.ir),
    TR_(*params.tr),
    OUTR_(*params.outr),
    Memory_(*params.mem),
    alu_(*params.alu),
    E(alu_.EFlag_),
    T(0),
    D(0),
    S(true),
    I(false),
    R(false),
    FGI(false),
    FGO(false),
    IEN(false)
{
}

void
ManoMachine::startup()
{
    schedule(event, latency);
}

void
ManoMachine::processEvent()
{
    if (!S)
    {
        exitSimLoop("Computer halted");
        return;
    }

    schedule(event, curTick() + latency);

    if (!R) // Instruction Cycle
    {
        // Fetch instruction from memory
        if (T == 0)
        {
            DPRINTF(ManoDebug, "Fetch - T0\n");

            AR_.setValue(PC_.getValue());

            T++;
            return;
        }
        if (T == 1)
        {
            DPRINTF(ManoDebug, "Fetch - T1\n");

            IR_.setValue(Memory_.Read());
            PC_.increment();

            T++;
            return;
        }
        // End of Fetch

        // Decode instruction
        if (T == 2)
        {
            DPRINTF(ManoDebug, "Decode - T2\n");

            uint16_t ir = IR_.getValue();
            AR_.setValue(ir);
            
            ir >>= 12;
            D = ir & 7;
            I = ir >> 3;

            T++;
            return;
        }
        // End of Decode

        if (IEN && (FGI || FGO))
        {
            DPRINTF(ManoDebug, "Interrupt Cycle flag R set\n");

            R = true;
        }

        if (D == 7)
        {
            if (I)  // Input Output
            {
                T = 0;

                uint16_t ir = IR_.getValue() & 0x0FFF;

                switch (ir)
                {
                case 1 << 6: //B6
                    DPRINTF(ManoDebug, "IOF - T3\n");
                    IEN = false;
                    break;
                case 1 << 7: //B7
                    DPRINTF(ManoDebug, "ION - T3\n");
                    IEN = true;
                    break;
                case 1 << 8: //B8
                    DPRINTF(ManoDebug, "SKO - T3\n");
                    if (FGO) PC_.increment();
                    break;
                case 1 << 9: //B9
                    DPRINTF(ManoDebug, "SKI - T3\n");
                    if (FGI) PC_.increment();
                    break;
                case 1 << 10: //B10
                    DPRINTF(ManoDebug, "OUT - T3\n");
                    OUTR_.setValue((uint8_t) AC_.getValue() & 0xFF);
                    FGO = false;
                    break;
                case 1 << 11: //B11
                    DPRINTF(ManoDebug, "INP - T3\n");
                    AC_.setValue(INPR_.getValue());
                    FGI = false;
                    break;
                
                default:
                    break;
                }
            }
            else    // Register Reference 
            {
                T = 0;

                uint16_t ir = IR_.getValue() & 0x0FFF;

                switch (ir)
                {
                case 1 << 0: //B0
                    DPRINTF(ManoDebug, "HLT - T3\n");
                    S = false;
                    break;
                case 1 << 1: //B1
                    DPRINTF(ManoDebug, "SZE - T3\n");
                    if (E)
                    {
                        PC_.increment();
                    }
                    break;
                case 1 << 2: //B2
                    DPRINTF(ManoDebug, "SZA - T3\n");
                    if (AC_.getValue() == 0)
                    {
                        PC_.increment();
                    }
                    break;
                case 1 << 3: //B3
                    DPRINTF(ManoDebug, "SNA - T3\n");
                    if (((AC_.getValue() >> 15) & 0X0001) == 1)
                    {
                        PC_.increment();
                    }
                    break;
                case 1 << 4: //B4
                    DPRINTF(ManoDebug, "SPA - T3\n");
                    if (((AC_.getValue() >> 15) & 0X0001) == 0)
                    {
                        PC_.increment();
                    }
                    break;
                case 1 << 5: //B5
                    DPRINTF(ManoDebug, "INC - T3\n");
                    AC_.increment();
                    break;
                case 1 << 6: //B6
                    DPRINTF(ManoDebug, "CIL - T3\n");
                    alu_.shiftLeftAC();
                    break;
                case 1 << 7: //B7
                    DPRINTF(ManoDebug, "CIR - T3\n");
                    alu_.shiftRightAC();
                    break;
                case 1 << 8: //B8
                    DPRINTF(ManoDebug, "CME - T3\n");
                    E = !E;
                    break;
                case 1 << 9: //B9
                    DPRINTF(ManoDebug, "CMA - T3\n");
                    alu_.complementAC();
                    break;
                case 1 << 10: //B10
                    DPRINTF(ManoDebug, "CLE - T3\n");
                    E = false;
                    break;
                case 1 << 11: //B11
                    DPRINTF(ManoDebug, "CLA - T3\n");
                    AC_.clear();
                    break;
                
                default:
                    break;
                }
            }
        }
        else        // Memory Reference
        {
            if (T == 3) // Handle Indirect operand
            {
                DPRINTF(ManoDebug, "Memory-reference handling direct/indirect - T3\n");
                
                if (I)
                {
                    AR_.setValue(Memory_.Read());
                }
                
                T++;
                return;
            }

            switch (D)
            {
            case 0: // AND
                if (T == 4)
                {
                    DPRINTF(ManoDebug, "AND - T4\n");

                    DR_.setValue(Memory_.Read());

                    T++;
                    return;
                }
                if (T == 5)
                {
                    DPRINTF(ManoDebug, "AND - T5\n");

                    alu_.performAND();

                    T = 0;
                    return;
                }
                break;
            case 1: // ADD
                if (T == 4)
                {
                    DPRINTF(ManoDebug, "ADD - T4    AC is currently %d\n",
                            AC_.getValue());

                    DR_.setValue(Memory_.Read());
                    
                    DPRINTF(ManoDebug, "ADD - T4    going to add %d to it\n",
                            DR_.getValue());
                    T++;
                    return;
                }
                if (T == 5)
                {
                    alu_.performADD();
                    
                    DPRINTF(ManoDebug, "ADD - T5    Adding done, AC is now %d\n",
                            AC_.getValue());

                    T = 0;
                    return;
                }
                break;
            case 2: // LDA
                if (T == 4)
                {
                    DPRINTF(ManoDebug, "LDA - T4\n");
                    
                    DR_.setValue(Memory_.Read());

                    T++;
                    return;
                }
                if (T == 5)
                {
                    DPRINTF(ManoDebug, "LDA - T5\n");
                    
                    alu_.loadDRtoAC();

                    T = 0;
                    return;
                }
                break;
            case 3: // STA
                if (T == 4)
                {
                    DPRINTF(ManoDebug, "STA - T4\n");
                    
                    Memory_.Write(AC_.getValue());
                
                    T = 0;
                    return;
                }
                break;
            case 4: // BUN
                if (T == 4)
                {
                    DPRINTF(ManoDebug, "BUN - T4\n");
                    
                    PC_.setValue(AR_.getValue());
                
                    T = 0;
                    return;
                }
                break;
            case 5: // BSA
                if (T == 4)
                {
                    DPRINTF(ManoDebug, "BSA - T4\n");
                    
                    Memory_.Write(PC_.getValue());
                    AR_.increment();

                    T++;
                    return;
                }
                if (T == 5)
                {
                    DPRINTF(ManoDebug, "BSA - T5\n");
                    
                    PC_.setValue(AR_.getValue());

                    T = 0;
                    return;
                }
                break;
            case 6: // ISZ
                if (T == 4)
                {
                    DPRINTF(ManoDebug, "ISZ - T4\n");
                    
                    DR_.setValue(Memory_.Read());

                    T++;
                    return;
                }
                if (T == 5)
                {
                    DPRINTF(ManoDebug, "ISZ - T5\n");
                    
                    DR_.increment();

                    T++;
                    return;
                }
                if (T == 6)
                {
                    DPRINTF(ManoDebug, "ISZ - T6\n");
                    
                    Memory_.Write(DR_.getValue());
                    if (DR_.getValue() == 0)
                    {
                        PC_.increment();
                    }

                    T = 0;
                    return;
                } 
                break;
            
            default:
                break;
            }
        }
    }
    else    // Interrupt Cycle
    {
        if (T == 0)
        {
            DPRINTF(ManoDebug, "Interrupt - T0\n");

            AR_.clear();
            TR_.setValue(PC_.getValue());

            T++;
            return;
        }

        if (T == 1)
        {
            DPRINTF(ManoDebug, "Interrupt - T1\n");

            Memory_.Write(TR_.getValue());
            PC_.clear();

            T++;
            return;
        }

        if (T == 2)
        {
            DPRINTF(ManoDebug, "Interrupt - T2\n");

            T = 0;

            PC_.increment();
            IEN = false;
            R = false;
        }
    }
}

} // namespace gem5
