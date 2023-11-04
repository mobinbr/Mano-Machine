#include "CAProject/registers/data_register/data_register.hh"

namespace gem5
{

DataRegister::DataRegister(const DataRegisterParams &params) : 
    SimObject(params),
    data(params.data)
{
}

void
DataRegister::setValue(uint16_t val)
{
    data = val;
}

void
DataRegister::increment()
{
    data++;
}

void
DataRegister::clear()
{
    data = 0;
}

uint16_t
DataRegister::getValue()
{
    return data;
}

} // namespace gem5
