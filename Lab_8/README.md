This lab is for driving DC motors to rotate wheels. In the old manual, we have:
1. Speed control of motor using PWM using Energia
2. Speed control of motor using analogWrite();
3. Direction control using push button
4. Motor speed and direction control on Keil
5. Straight line motion for diff. drive robot
1 and 2 are not possible for our device. Meanwhile, task 4 incorporates task 3 and 5, so we uploaded only a singular project. Once uploaded and USER button pushed, the wheels will rotate both forward, then with a click of the push button, a wheel will change direction.

Connections: 
Left motor: (to driver)
Blue: OUT1
Orange: OUT2

Right motor: (to driver)
Blue: OUT3
Orange: OUT4 

Driver:
ENA: PC8
N1: PA15
N2: PA14
N3: PD8
N4: PD9
ENB: PC6
