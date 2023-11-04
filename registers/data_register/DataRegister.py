from m5.params import *
from m5.SimObject import SimObject

class DataRegister(SimObject):
    type = 'DataRegister'
    cxx_header = "CAProject/registers/data_register/data_register.hh"
    cxx_class = "gem5::DataRegister"

    data = Param.UInt16(0, "Data stored in the register")
