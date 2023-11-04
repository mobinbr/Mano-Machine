from m5.params import *
from m5.SimObject import SimObject

class ACRegister(SimObject):
    type = 'ACRegister'
    cxx_header = "CAProject/registers/ac_register/ac_register.hh"
    cxx_class = "gem5::ACRegister"

    ac = Param.UInt16(0, "AC stored in the register")
