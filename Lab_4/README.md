In this lab, we will be using an ultrasonic sensor for measuring distance. We will be using timer 3 for this task.
The TRIG pin of the ultrasonic sensor will be connected to PB0 and the ECHO pin to PB1.

We will record a pulse to measure the time it takes for a pulse to be detected by sonar,
then apply a formula to calculate the distance in cm. Please note that there might be some variations due to garbage values.

The printing is done using UART as defined in the previous labs.

For the tasks where we need output of the LEDs, we use the built-in LEDs of STM32F3 (in our case, those would be LED3, LED4 and LED7).
