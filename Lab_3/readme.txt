Use the stm32f3xx_it.c for all your tasks. You will not need it for some of them, but to save your time you can add it in the beginning and forget about it later.
The tasks themselves require nothing more than copying main.c files. 7-segment display connections are PB3 to a, PB4 to b, and so on. 
For the external button in Task 3, connect a push button in series with a 10k ohm resistor. Then, connect the non-resistor end of the button to 3V, the resistor end to GND, and the node between the resistor and the button to PB1.
