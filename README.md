# Designing and Implementation of a Multi-Cycle Processor in gem5

## Description

This project focuses on the design and implementation of a multi-cycle processor using the gem5 simulator. The Mano Machine, a simple computer architecture, has been chosen as the basis for this implementation. By utilizing gem5, we aim to simulate the execution of instructions and evaluate the behaviour of the Mano Machine inside gem5 environment.

Using this project, you can simulate running a program that is designed for the Mano Machine ISA, and see what steps the machine goes through in order to achieve the execution of the defined program.

## Features

- Implementation of the required components and the machine itself as SimObjects including: (You can find the SimObject names in the SConscript file.)

    - Registers (such as ACRegister, AddressRegister, etc.)
    - ManoALU
    - ManoMemory
    - ManoMachine (which represents the functionality of the control unit)
- Simulation of various possible instructions and their performance analysis
- Observation of the processor's instruction execution route behaviour given a Program


## How to Use
If you need to know about the parameters of each class, make sure to check out the SimObject definition files before proceeding.

Then to use this project, follow these steps:

1. Make sure you have an installation of gem5 simulator (preferably the latest version) following the official documentation.

1. Clone the project repository on your local machine.

1. Build the project files according to your host system ISA, using the following command: (within the root of the gem5 directory)

    ```bash
        scons build/{ISA}/gem5.opt -j$(nproc)
    ```
   
1. Make the modifications you need in the configuration script file (run_mano.py), such as changing the program for the machine through changing the meminit parameter of the memory.\
\
You can also initialize registers with values other than 0, such as initializing the PC register with 2, while you would want to allow for an implementation of an interrupt cycle routine. (as you would need to leave the 2  first cells of memory for that)
 

1. Using the gem5.opt binary you just built, you can run the script; If you want to see the debug messages, you should use the debug flag **ManoDebug**. 

    ```bash
        {pathToBinary}/gem5.opt [--debug-flag=ManoDebug] {pathToConfig}/run_mano.py
    ```