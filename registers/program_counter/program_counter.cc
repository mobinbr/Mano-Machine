#include "CAProject/registers/program_counter/program_counter.hh"

namespace gem5
{

ProgramCounter::ProgramCounter(const ProgramCounterParams &params) : 
    SimObject(params),
    pc(params.pc),
    size_mask((1 << 12) - 1)
{
}

void
ProgramCounter::setValue(uint16_t val)
{
    pc = val & size_mask;
}

void
ProgramCounter::increment()
{
    pc++;
    pc &= size_mask;
}

void
ProgramCounter::clear()
{
    pc = 0;
}

uint16_t
ProgramCounter::getValue()
{
    return pc;
}

} // namespace gem5
