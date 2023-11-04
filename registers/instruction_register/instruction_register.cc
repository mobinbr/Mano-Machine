#include "CAProject/registers/instruction_register/instruction_register.hh"

namespace gem5
{

InstructionRegister::InstructionRegister(const InstructionRegisterParams &params) : 
    SimObject(params),
    inst(params.inst)
{
}

void
InstructionRegister::setValue(uint16_t val)
{
    inst = val;
}

uint16_t
InstructionRegister::getValue()
{
    return inst;
}

} // namespace gem5
