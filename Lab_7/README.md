In this lab, we will configure the in-build ADC of our board to measure analog voltage. 

Task 1 requires the construction of a simple photoresistor + 220 ohm resistor series combination on a breadboard, after which we supply 3V from the board and send the voltage at the junction between the components to a GPIO pin. We then use the 12-bit ADC to print the value (though keep in mind the value we obtain will not be the actual voltage, and just an integer from 0 to 4096) using a 7-segment display, which requires division of the value obtained.

Task 2 is very similar to Task 1; the only difference is that we use a potentiometer instead of the previous circuit and print the voltage itself in UART.

Task 3 takes the output of Task 2 and uses it to control the brightness of an in-build LED. Hence, instead of providing Task 2's code separately, I have only given Task 3's code, since it is sufficient for both tasks.

The following connections are used:
1. Measured value at PC1
2. RXD of UART to PD5
3. 3V and GND as labeled on the board
4. Same 7-seg connections as before (PB3 to PB9, inclusive, as well as 3V to common anode)
