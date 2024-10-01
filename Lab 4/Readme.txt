In this lab we will be using an ultrasonic for distance measuring.
We will be using timer 3 for this task
The trig pin of the ultrasonic sensor is connected to PB0
The echo pin of the ultrasonic sensor is connected to PB1

We re then generating a pulse of the sonar sensor to measure the time it takes to for a pulse to be detected by sonar.
Then we applied the distance formula to find out the distance in cm. Please note that there might be some variations due to garbage values of sonar.

The printing is bein done using UART as defined in the previous labs.

For the tasks where we need output of the LEDs, we are using the built-in LEDs of STM32F3. In our case, LED3, LED4 and lED7