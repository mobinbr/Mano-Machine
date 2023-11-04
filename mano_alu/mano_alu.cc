#include "CAProject/mano_alu/mano_alu.hh"

namespace gem5
{

ManoALU::ManoALU(const ManoALUParams& params) :
    SimObject(params),
    EFlag_(params.e),
    DR_(*params.dr), 
    AC_(*params.ac), 
    INPR_(*params.inpr) 
{
}

void
ManoALU::performADD()
{
    AC_.setValue(AC_.getValue() + DR_.getValue());
}

void
ManoALU::performAND()
{
    AC_.setValue(AC_.getValue() & DR_.getValue());
}

void
ManoALU::loadDRtoAC()
{
    AC_.setValue(DR_.getValue());
}

void
ManoALU::loadINPRtoAC()
{
    AC_.setValue(static_cast<uint16_t>(INPR_.getValue()));
}

void
ManoALU::shiftRightAC()
{
    uint16_t tmp = AC_.getValue();

    AC_.setValue((tmp >> 1) | (EFlag_ << 15));
    EFlag_ = tmp & 0x0001;
}

void
ManoALU::shiftLeftAC()
{
    uint16_t tmp = AC_.getValue();

    AC_.setValue(tmp << 1 | EFlag_);
    EFlag_ = tmp >> 15;
}

void
ManoALU::complementAC()
{
    AC_.setValue(~AC_.getValue());
}

} // namespace gem5
