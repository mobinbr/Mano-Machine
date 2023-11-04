from m5.params import *
from m5.SimObject import SimObject

class ManoMachine(SimObject):
    type = 'ManoMachine'
    cxx_header = "CAProject/mano_machine/mano_machine.hh"
    cxx_class = "gem5::ManoMachine"


    cycle_time = Param.Latency("500ns", "the Latency between clock pulses")

    mem = Param.ManoMemory("")
    ar = Param.AddressRegister("")
    pc = Param.ProgramCounter("")
    dr = Param.DataRegister("")
    alu = Param.ManoALU("")
    ac = Param.ACRegister("")
    inpr = Param.INPRegister("")
    ir = Param.InstructionRegister("")
    tr = Param.TempRegister("")
    outr = Param.OUTRegister("")