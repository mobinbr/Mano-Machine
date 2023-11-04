import m5
from m5.objects import *


mem = ManoMemory(meminit=[0x1003, 0x1004, 0x7001, 0x0005, 0x000A])
ar = AddressRegister()
pc = ProgramCounter()
dr = DataRegister()
alu = ManoALU()
ac = ACRegister()
inpr = INPRegister()
ir = InstructionRegister()
tr = TempRegister()
outr = OUTRegister()

mem.ar = ar

alu.dr = dr
alu.ac = ac
alu.inpr = inpr


# set up the root SimObject and start the simulation
root = Root(full_system=False)

# Create an instantiation of the simobject you created
root.mano = ManoMachine()

root.mano.mem = mem
root.mano.ar = ar
root.mano.pc = pc
root.mano.dr = dr
root.mano.alu = alu
root.mano.ac = ac
root.mano.inpr = inpr
root.mano.ir = ir
root.mano.tr = tr
root.mano.outr = outr


# instantiate all of the objects we've created above
m5.instantiate()

print("Beginning simulation!")
exit_event = m5.simulate()
print("Exiting @ tick %i because %s" % (m5.curTick(), exit_event.getCause()))