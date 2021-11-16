In Cortex M4 processor, a function can use register R4 through R11 for its own purpose. So when func2() inititalizes 5 variables they are stored into R4 through R8 register. 
When func2() calls a func1(), register R0 through R3 are available for callee function and register R4 through R11 are available for calle function. 
Register R0 is a scratchpad hence its data along with R5 are pushed on to the stack. The each register value is added to with the help of R0 scratchpad register. 
Register Upon return to calle function, the register R5 is popped and dat is saved for next instruction.
