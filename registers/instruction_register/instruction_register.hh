#ifndef __INSTRUCTION_REGISTER_HH__
#define __INSTRUCTION_REGISTER_HH__

#include "params/InstructionRegister.hh"
#include "sim/sim_object.hh"

namespace gem5
{

class InstructionRegister : public SimObject
{
    private:
        uint16_t inst;

    public:
        InstructionRegister(const InstructionRegisterParams &params);
        void setValue(uint16_t val);
        uint16_t getValue();

};

} // namespace gem5

#endif // __INSTRUCTION_REGISTER_HH__
