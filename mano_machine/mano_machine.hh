#ifndef __MANO_MACHINE_HH__
#define __MANO_MACHINE_HH__

#include "params/ManoMachine.hh"
#include "sim/sim_object.hh"

#include "CAProject/registers/ac_register/ac_register.hh"
#include "CAProject/registers/address_register/address_register.hh"
#include "CAProject/registers/data_register/data_register.hh"
#include "CAProject/registers/inp_register/inp_register.hh"
#include "CAProject/registers/instruction_register/instruction_register.hh"
#include "CAProject/registers/out_register/out_register.hh"
#include "CAProject/registers/program_counter/program_counter.hh"
#include "CAProject/registers/temp_register/temp_register.hh"
#include "CAProject/mano_memory/mano_memory.hh"
#include "CAProject/mano_alu/mano_alu.hh"

namespace gem5
{

class ManoMachine : public SimObject
{
    private:
        void processEvent();
        EventFunctionWrapper event;

        Tick latency;
        AddressRegister& AR_;
        ProgramCounter& PC_;
        DataRegister& DR_;
        ACRegister& AC_;
        INPRegister& INPR_;
        InstructionRegister& IR_;
        TempRegister& TR_;
        OUTRegister& OUTR_;
        ManoMemory& Memory_;
        ManoALU& alu_;
        bool& E;
        int16_t T;
        int16_t D;
        bool S;
        bool I;
        bool R;
        bool FGI;
        bool FGO;
        bool IEN;

    public:
        ManoMachine(const ManoMachineParams &params);
        void startup();
};

} // namespace gem5

#endif // __MANO_MACHINE_HH__
