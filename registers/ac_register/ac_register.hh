#ifndef __AC_REGISTER_HH__
#define __AC_REGISTER_HH__

#include "params/ACRegister.hh"
#include "sim/sim_object.hh"

namespace gem5
{

class ACRegister : public SimObject
{
    private:
        uint16_t ac;

    public:
        ACRegister(const ACRegisterParams &params);
        void setValue(uint16_t val);
        void increment();
        void clear();
        uint16_t getValue();

};

} // namespace gem5

#endif // __AC_REGISTER_HH__
