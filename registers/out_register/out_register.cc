#include "CAProject/registers/out_register/out_register.hh"

namespace gem5
{

OUTRegister::OUTRegister(const OUTRegisterParams &params) : 
    SimObject(params),
    out(params.out)
{
}

void
OUTRegister::setValue(uint8_t val)
{
    out = val;
}

uint8_t
OUTRegister::getValue()
{
    return out;
}

} // namespace gem5
