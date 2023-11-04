#ifndef __MANO_ALU_HH__
#define __MANO_ALU_HH__

#include <iostream>
#include <string>

#include "params/ManoALU.hh"
#include "sim/sim_object.hh"

#include "CAProject/registers/data_register/data_register.hh"
#include "CAProject/registers/ac_register/ac_register.hh"
#include "CAProject/registers/inp_register/inp_register.hh"
#include "CAProject/mano_alu/mano_alu.hh"

namespace gem5
{

class ManoALU : public SimObject
{
    public:
        ManoALU(const ManoALUParams &params);
        void operate(std::string command);
        void performADD();
        void performAND();
        void loadDRtoAC();
        void loadINPRtoAC();
        void shiftRightAC();
        void shiftLeftAC();
        void complementAC();
        bool EFlag_;

    private:
        DataRegister& DR_;
        ACRegister& AC_;
        INPRegister& INPR_;

};

} // namespace gem5

#endif // __MANO_ALU_HH__
