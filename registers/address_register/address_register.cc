#include "CAProject/registers/address_register/address_register.hh"

namespace gem5
{

AddressRegister::AddressRegister(const AddressRegisterParams &params) : 
    SimObject(params),
    addr(params.addr),
    size_mask((1 << 12) - 1)
{
}

void
AddressRegister::setValue(uint16_t val)
{
    addr = val & size_mask;
}

void
AddressRegister::increment()
{
    addr++;
    addr &= size_mask;
}

void
AddressRegister::clear()
{
    addr = 0;
}

uint16_t
AddressRegister::getValue()
{
    return addr;
}

} // namespace gem5
