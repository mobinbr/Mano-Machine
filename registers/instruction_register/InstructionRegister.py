from m5.params import *
from m5.SimObject import SimObject

class InstructionRegister(SimObject):
    type = 'InstructionRegister'
    cxx_header = "CAProject/registers/instruction_register/instruction_register.hh"
    cxx_class = "gem5::InstructionRegister"

    inst = Param.UInt16(0, "Instruction stored in the register")
