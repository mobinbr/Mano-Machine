#ifndef __DATA_REGISTER_HH__
#define __DATA_REGISTER_HH__

#include "params/DataRegister.hh"
#include "sim/sim_object.hh"

namespace gem5
{

class DataRegister : public SimObject
{
    private:
        uint16_t data;

    public:
        DataRegister(const DataRegisterParams &params);
        void setValue(uint16_t val);
        void increment();
        void clear();
        uint16_t getValue();

};

} // namespace gem5

#endif // __DATA_REGISTER_HH__
