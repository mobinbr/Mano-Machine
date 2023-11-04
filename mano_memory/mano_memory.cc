#include "CAProject/mano_memory/mano_memory.hh"
#include <array>

namespace gem5
{

ManoMemory::ManoMemory(const ManoMemoryParams &params) : 
    SimObject(params),
    ManoMemory_(),
    AR(*params.ar)
{
    std::vector<uint16_t> init_values = params.meminit;
    for (size_t i = 0; i < init_values.size() && i < ManoMemory_.size(); i++)
    {
        ManoMemory_[i] = init_values[i];
    }
}

void
ManoMemory::Write(uint16_t data)
{
    uint16_t address = AR.getValue();
    ManoMemory_[address] = data;
}

uint16_t
ManoMemory::Read()
{
    return ManoMemory_[AR.getValue()];
}

} // namespace gem5
