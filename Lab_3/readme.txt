Lab 3 teaches how to interface a 7-segment display using the board.
The tasks themselves require nothing more than copying main.c files. 7-segment display connections are PB3 to a, PB4 to b, and so on. Task 1 is to display every hexadecimal digit separated with a 2 second delay. Task 2 displays each digit of a student ID using the USER push button on the board. Task 3 uses a USER button to increment the index and an external button to decrement. Task 4 is the same as Task 2, except to display a random number from 1 to 6 inclusive.
For the external button in Task 3, connect a push button in series with a 10k ohm resistor. Then, connect the non-resistor end of the button to 3V, the resistor end to GND, and the node between the resistor and the button to PB1.
Use the stm32f3xx_it.c for all your tasks. You will not need it for some of them, but to save your time you can add it in the beginning and forget about it later.

