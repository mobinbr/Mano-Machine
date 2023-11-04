from m5.params import *
from m5.SimObject import SimObject

class ManoALU(SimObject):
    type = 'ManoALU'
    cxx_header = "CAProject/mano_alu/mano_alu.hh"
    cxx_class = "gem5::ManoALU"

    dr = Param.DataRegister("")
    ac = Param.ACRegister("")
    inpr = Param.INPRegister("")
    e = Param.Bool(False, "")
