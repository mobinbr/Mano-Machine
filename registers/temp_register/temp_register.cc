#include "CAProject/registers/temp_register/temp_register.hh"

namespace gem5
{

TempRegister::TempRegister(const TempRegisterParams &params) : 
    SimObject(params),
    temp(params.temp)
{
}

void
TempRegister::setValue(uint16_t val)
{
    temp = val;
}

void
TempRegister::increment()
{
    temp++;
}

void
TempRegister::clear()
{
    temp = 0;
}

uint16_t
TempRegister::getValue()
{
    return temp;
}

} // namespace gem5
