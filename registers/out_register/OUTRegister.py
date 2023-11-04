from m5.params import *
from m5.SimObject import SimObject

class OUTRegister(SimObject):
    type = 'OUTRegister'
    cxx_header = "CAProject/registers/out_register/out_register.hh"
    cxx_class = "gem5::OUTRegister"

    out = Param.UInt8(0, "Output stored in the register")
