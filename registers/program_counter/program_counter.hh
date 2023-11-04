#ifndef __PROGRAM_COUNTER_HH__
#define __PROGRAM_COUNTER_HH__

#include "params/ProgramCounter.hh"
#include "sim/sim_object.hh"

namespace gem5
{

class ProgramCounter : public SimObject
{
    private:
        uint16_t pc;
        const uint16_t size_mask;

    public:
        ProgramCounter(const ProgramCounterParams &params);
        void setValue(uint16_t val);
        void increment();
        void clear();
        uint16_t getValue();

};

} // namespace gem5

#endif // __PROGRAM_COUNTER_HH__
