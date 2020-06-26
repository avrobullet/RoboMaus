# RoboMaus

<img src="https://mdrakos.github.io/images/roboMaus-teaser.png" width="728" height="440">

<a href="https://www.youtube.com/watch?v=7UpjE0antww" target="_blank">Click this link to view the RoboMaus in action</a>

The roboMaus project was used to explore hardware programming, data structures, and concurrency.

The idea was to see if independent treads of a tank could be controlled via software rather than a gear system. In order to implement and test this idea our team had to develop hardware drivers for each physical component, software to populate data structures with path information and facilitate communication amongst the hardware components.

## Hardware

The main hardware used for this project:

**SAM4SD32 Microcontroller**

<img src="https://mdrakos.github.io/images/sam4s.png" width="300" height="250">

* This is the brain of the project.
* Code is flashed and stored on the ROM
* Extension pins allow for connection to all other hardware components

**ATMEL OLED1 Xplained Pro**

<img src="https://mdrakos.github.io/images/oled.png" width="350" height="250">

* Used to initialize the program via a button push
* Display statistics (number of rotations) on OLED display

**L298 H-Bridge Dual Bidirectional Motor Driver**

<img src="https://mdrakos.github.io/images/hbridge.png" width="300" height="250">

* Used to initialize the program via a button push
* Display statistics (number of rotations) on OLED display

**Hall effect sensors**

<img src="https://mdrakos.github.io/images/hall-sensor.png" width="300" height="250">

* Used to measure distance by counting wheel rotations

**Brushless Motors with 1:10 Gear Reduction**

<img src="https://mdrakos.github.io/images/motor.png" width="300" height="250">

**Included Kit Treads**

<img src="https://mdrakos.github.io/images/treads.png" width="300" height="250">

**..and a 14V RC battery pack!**

## 3D Printing and Modelling
The chassis was an opportunity to explore 3D printing using a [Tinkerine DittoPro 3D Printer](https://store.tinkerine.com/products/ditto-pro). Two prototypes were developed before finalizing the chassis. All three are shown below:

*Prototype Chassis 1*

<img src="https://mdrakos.github.io/images/chassisv1.png" width="500" height="350">

* The first prototype was built to confirm the dimensions of the chassis were printed accurately

*Prototype Chassis 2*

<img src="https://mdrakos.github.io/images/chassisv2.png" width="500" height="350">

* The second prototype was built to determine the fitment of the motors, tread and tread axels, and battery pack
* This chassis also indicated a need to create a separate layer to host the computing hardware

*Final Chassis*

<img src="https://mdrakos.github.io/images/chassisv3.png" width="500" height="350">

## Data Structures
Each tread is controlled independently. Instructions for are stored in two separate stacks for each tread as a ‘tick’ value. These values represent the number of ticks we want to receive from a hall effect sensor.

A path is populated into each stack via ‘tick’ instructions. As instructions are popped off the stack they are sent to the tread drivers which then sends the instruction to the tread. Once feedback that the instruction was executed is received from the hall effect sensors, the next instruction is popped off until no instructions remain.

## Concurrency
Each hall effect sensor is connected to independent GPIO pins. This means that the signals are being sent at the same time. To compensate for this we implemented a pseudo-concurrent solution using boolean values. Each sensor has a boolean value associated with it to determine if it should still count ‘ticks’ or not. Unless both of the boolean values tell the program to stop counting, we prevent the next instruction from being popped off the instruction stack.

While not a true concurrent solution, we found it to work within our expectations. Each boolean value is being updated concurrently and this solution solved our problem without having to attempt implementing a monitor, semaphore, or other complex concurrent solution in C.

## Challenges
Working with hardware was more difficult than anyone on our team imagined it would be. Countless hours were spent consulting documentation, making wires, testing voltages, and rewriting driver software.

This project was also my first experience with the C programming language. Coming from Java this was difficult at first to pick up and I spent a long time getting comfortable.

### Future improvements
Originally, we had planned to experiment how different data structures affected performance however due to time constraints we were limited to only using a stack though various other data structures were on our list.

## Special Thanks
A huge part of this project is built on top of MiniOS, an operating system built for the SAM4S micro controller by [Rafael Roman Otero](http://embedntks.com/author/romanot/).
