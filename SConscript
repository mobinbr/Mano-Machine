Import('*')

SimObject('registers/ac_register/ACRegister.py',
          sim_objects=['ACRegister'])
Source('registers/ac_register/ac_register.cc')

SimObject('registers/address_register/AddressRegister.py',
          sim_objects=['AddressRegister'])
Source('registers/address_register/address_register.cc')

SimObject('registers/data_register/DataRegister.py',
          sim_objects=['DataRegister'])
Source('registers/data_register/data_register.cc')

SimObject('registers/inp_register/INPRegister.py',
          sim_objects=['INPRegister'])
Source('registers/inp_register/inp_register.cc')

SimObject('registers/instruction_register/InstructionRegister.py',
          sim_objects=['InstructionRegister'])
Source('registers/instruction_register/instruction_register.cc')

SimObject('registers/out_register/OUTRegister.py',
          sim_objects=['OUTRegister'])
Source('registers/out_register/out_register.cc')

SimObject('registers/program_counter/ProgramCounter.py',
          sim_objects=['ProgramCounter'])
Source('registers/program_counter/program_counter.cc')

SimObject('registers/temp_register/TempRegister.py',
          sim_objects=['TempRegister'])
Source('registers/temp_register/temp_register.cc')


SimObject('mano_alu/ManoALU.py', sim_objects=['ManoALU'])
Source('mano_alu/mano_alu.cc')

SimObject('mano_memory/ManoMemory.py', sim_objects=['ManoMemory'])
Source('mano_memory/mano_memory.cc')

SimObject('mano_machine/ManoMachine.py', sim_objects=['ManoMachine'])
Source('mano_machine/mano_machine.cc')


DebugFlag('ManoDebug')