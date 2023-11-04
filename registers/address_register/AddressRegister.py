from m5.params import *
from m5.SimObject import SimObject

class AddressRegister(SimObject):
    type = 'AddressRegister'
    cxx_header = "CAProject/registers/address_register/address_register.hh"
    cxx_class = "gem5::AddressRegister"

    addr = Param.UInt16(0, "Address stored in the register")
