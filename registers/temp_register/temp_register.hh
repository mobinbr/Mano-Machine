#ifndef __TEMP_REGISTER_HH__
#define __TEMP_REGISTER_HH__

#include "params/TempRegister.hh"
#include "sim/sim_object.hh"

namespace gem5
{

class TempRegister : public SimObject
{
    private:
        uint16_t temp;

    public:
        TempRegister(const TempRegisterParams &params);
        void setValue(uint16_t val);
        void increment();
        void clear();
        uint16_t getValue();

};

} // namespace gem5

#endif // __TEMP_REGISTER_HH__
