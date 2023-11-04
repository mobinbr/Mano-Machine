from m5.params import *
from m5.SimObject import SimObject

class ManoMemory(SimObject):
    type = 'ManoMemory'
    cxx_header = "CAProject/mano_memory/mano_memory.hh"
    cxx_class = "gem5::ManoMemory"

    ar = Param.AddressRegister("The Address Register connected to the memory")
    meminit = VectorParam.UInt16("Some data to initialize the memory")
