In this lab, we will configure the in-build ADC of our board to measure analog voltage. 

Task 1 requires the construction of a simple photoresistor + 220 ohm resistor series combination on a breadboard, after which we supply a 3V from the board and send the voltage at the junction between the components to a GPIO pin. We then use the 12-bit ADC to print the value (though keep in mind the value we obtain will not be the actual voltage, and just an integer from 0 to 4096) using UART. Finally, we display the value using a 7-segment display, which requires division of the value obtained.

Task 2 is very similar to Task 1; the only difference is that we use a potentiometer instead of the previous circuit.

Task 3 takes the output of Task 2 and uses it to control the brightness of an in-build LED.

The following connections are used:
1. Measured value at PC1
2. RXD of UART to PD5
3. 3V and GND as labeled on the board

WORK IN PROGRESS
