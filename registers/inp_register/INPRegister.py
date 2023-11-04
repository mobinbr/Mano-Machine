from m5.params import *
from m5.SimObject import SimObject

class INPRegister(SimObject):
    type = 'INPRegister'
    cxx_header = "CAProject/registers/inp_register/inp_register.hh"
    cxx_class = "gem5::INPRegister"

    inp = Param.UInt8(0, "Input stored in the register")
