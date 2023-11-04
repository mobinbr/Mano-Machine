#ifndef __MANO_MEMORY_HH__
#define __MANO_MEMORY_HH__

#include "params/ManoMemory.hh"
#include "sim/sim_object.hh"

#include "CAProject/registers/address_register/address_register.hh"

namespace gem5
{

    class ManoMemory : public SimObject
    {
    public:
        ManoMemory(const ManoMemoryParams &params);
        void Write(uint16_t data);
        uint16_t Read();

    private:
        std::array<uint16_t, 4096> ManoMemory_;
        AddressRegister& AR;
    };

} // namespace gem5

#endif // __MANO_MEMORY_HH__