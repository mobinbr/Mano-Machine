#ifndef __ADDRESS_REGISTER_HH__
#define __ADDRESS_REGISTER_HH__

#include "params/AddressRegister.hh"
#include "sim/sim_object.hh"

namespace gem5
{

class AddressRegister : public SimObject
{
    private:
        uint16_t addr;
        const uint16_t size_mask;

    public:
        AddressRegister(const AddressRegisterParams &params);
        void setValue(uint16_t val);
        void increment();
        void clear();
        uint16_t getValue();

};

} // namespace gem5

#endif // __ADDRESS_REGISTER_HH__
