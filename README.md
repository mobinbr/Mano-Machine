# Mano-Machine

In this project, we aim to implement the Mano Machine computer as a simple multi-cycle processor in the gem5 environment using functional and behavioral approaches.

Important Notes:
This implementation is based on the design and concepts presented in the third edition of the "Computer Architecture: A Quantitative Approach" book by John L. Hennessy and David A. Patterson.

The required components of this design are implemented in a modular manner, including registers, the memory unit, and the ALU unit. They are designed and implemented as new SimObjects.

To store data in registers, the appropriate data types based on their sizes are used. For example, data in 16-bit registers are stored as uint16_t, and data in 8-bit registers are stored as uint8_t. The reason for using unsigned data types is that the design of the Mano Machine is based on working with positive numbers, and negative numbers are not considered.

Since there is no 12-bit data type available, a combination of uint16_t and a 12-bit bitmask is used for 12-bit registers. The bitmask ensures that only the least significant 12 bits of int16_t are used.

The clocking process of the system is designed in an event-driven manner. Each clock pulse is treated as an event that occurs in a defined tick. The necessary operations are executed based on the conditions in each event, and if necessary, the event for the next clock pulse is enqueued.

Due to the functional nature of the implementation and the event-based clock pulse, there is no separate component for the control unit. Control operations are performed by calling the implemented functions for the modules within the clock event.

Implementation of Units:
In this section, the SimObject design for each unit, as described in the Modifying/Extending section of the gem5.org website, is explained.

General Notes:
For each unit, a Python SimObject description file (.py) is defined, which includes information about the class of that unit and the required parameters for its constructor.
Each unit has two corresponding C++ files, one for the header and the other for the source code of the unit. The header file contains information about the class, and the source code file contains the implementation in C++.
At the end, after implementing these files for the components, there is a SConscript file in which the added modules are introduced to the SCons tool to build them and add them to gem5.

Registers:
For each register, a specific uintX_t data type is determined based on its width (as explained in the "Important Notes" section). For each register, functions corresponding to the control signals required for that register are implemented. These functions include:
    setValue for the LD control signal.
    getValue to retrieve information from the register.
    increment for the INR control signal.
    clear for the CLR control signal.

ALU Unit:
The ALU unit in the Mano Machine can take 3 input sources: DR, AC, and INPR. These sources are connected to the ALU as inputs. The result of the computations should be stored in the AC register, which has been implemented. The ALU unit should support the following operations: ADD, AND, Load DR to AC (transfer), Load INPR to AC, SHR, SHL, COMPLEMENT. All these operations are designed and implemented in the ALU.

The E flip-flop is also included as an input to be used in shift operations (since the shift in the Mano Machine is a circular shift).

Memory Unit:
The memory in the Mano Machine is used to store data and instructions, and it is a 4096 * 16 memory (using a 12-bit AR register).
To implement this memory in our machine, we use an int16_t array with a length of 4096 (each word is represented by one array element).

The write operation for this memory is implemented in a way that takes data as input and stores it at the specified address determined by AR.

For this unit, two inputs, AR and meminit, are considered. AR determines the register address from which the memory address is obtained, and meminit contains a set of initial values to initialize the memory. This allows us to load a program into memory if needed and then execute the computer's operation.

Assembling the Computer:
Now, using the defined and implemented components, we can implement the Mano Machine.

In the ManoMachine class, we will have one of each of the constructed components as a required part of our device. When configuring the components, these components will be passed as parameters to the base ManoMachine class. We need to define them in the SimObject definition file of the Mano Machine.

In addition to the components as parameters, there is a cycle_time parameter that determines the time interval between two clock pulses.

In addition to the components that are passed as parameters, the implemented basic computer has some FFs and additional flags. Considering the high-level and functional nature of the implementation, the FFs are also treated as booleans and flags, and if our components require them (such as ALU requiring E), their references are passed to the respective component to ensure synchronous changes in the system.

The base computer also requires information such as D and T (where in our implementation, T replaces the SC counter in the physical implementation). These numbers are added as part of the ManoMachine.

In addition to the mentioned descriptions, this class should have an event and an event process corresponding to it.
The latency variable represents the time interval determined by the cycle_time parameter.

Explanation of the Mano Machine's processEvent:
At the beginning of each processEvent, we check the power status of the machine. Then, we do the following:
    By checking the value of R, we determine whether to proceed with the instruction cycle or the interrupt cycle.

Instruction Cycle:
First, we perform the fetch and decode stages in T0, T1, and T2. At the end of each stage, we increment T and return to terminate the current clock operations.
We know that the Mano Machine has three instruction formats. Based on the given instruction format we understand its format.

We proceed to the necessary instructions to execute it. Since Input-Output and Register-reference instructions are performed in one clock, we initially set T to 0 to move on to the next cycle after completing this clock. Then, using a switch case and based on the instruction, we execute the required operations.

If the processed instruction is of type Memory-reference, we need to perform the required operations over multiple clocks.

Interrupt Cycle:
We have implemented the necessary instructions in the specified three clocks to execute interrupt cycle, and finally, by setting T to 0, we move on to the next instruction.

there is also a script written for this mano machine in order to test it.
In the provided script we tested ADD operation (5+10) in following steps:
    initialize the required components and meminit in order to define the ADD operation.
    set up the root SimObject and start the simulation
    create an instantiation of the simobject we created
    instantiate all of the objects we've created before