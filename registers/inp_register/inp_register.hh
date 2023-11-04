#ifndef __INP_REGISTER_HH__
#define __INP_REGISTER_HH__

#include "params/INPRegister.hh"
#include "sim/sim_object.hh"

namespace gem5
{

class INPRegister : public SimObject
{
    private:
        uint8_t inp;

    public:
        INPRegister(const INPRegisterParams &params);
        void setValue(uint8_t val);
        uint8_t getValue();

};

} // namespace gem5

#endif // __INP_REGISTER_HH__
