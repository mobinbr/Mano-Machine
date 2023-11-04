from m5.params import *
from m5.SimObject import SimObject

class ProgramCounter(SimObject):
    type = 'ProgramCounter'
    cxx_header = "CAProject/registers/program_counter/program_counter.hh"
    cxx_class = "gem5::ProgramCounter"

    pc = Param.UInt16(0, "Address stored in the register")
