from m5.params import *
from m5.SimObject import SimObject

class TempRegister(SimObject):
    type = 'TempRegister'
    cxx_header = "CAProject/registers/temp_register/temp_register.hh"
    cxx_class = "gem5::TempRegister"

    temp = Param.UInt16(0, "Temporary data stored in the register")
