#include "CAProject/registers/ac_register/ac_register.hh"

namespace gem5
{

ACRegister::ACRegister(const ACRegisterParams &params) : 
    SimObject(params),
    ac(params.ac)
{
}

void
ACRegister::setValue(uint16_t val)
{
    ac = val;
}

void
ACRegister::increment()
{
    ac++;
}

void
ACRegister::clear()
{
    ac = 0;
}

uint16_t
ACRegister::getValue()
{
    return ac;
}

} // namespace gem5
