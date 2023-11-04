#ifndef __OUT_REGISTER_HH__
#define __OUT_REGISTER_HH__

#include "params/OUTRegister.hh"
#include "sim/sim_object.hh"

namespace gem5
{

class OUTRegister : public SimObject
{
    private:
        uint8_t out;

    public:
        OUTRegister(const OUTRegisterParams &params);
        void setValue(uint8_t val);
        uint8_t getValue();

};

} // namespace gem5

#endif // __OUT_REGISTER_HH__
