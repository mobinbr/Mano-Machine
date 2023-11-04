#include "CAProject/registers/inp_register/inp_register.hh"

namespace gem5
{

INPRegister::INPRegister(const INPRegisterParams &params) : 
    SimObject(params),
    inp(params.inp)
{
}

void
INPRegister::setValue(uint8_t val)
{
    inp = val;
}

uint8_t
INPRegister::getValue()
{
    return inp;
}

} // namespace gem5
