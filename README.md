#Reaction game for Raspberry Pi

The aim of the game is to hit the target when the LED column reaches it. The game starts by blinking the target LED three times, then the LED column will light up and down. The player can press the button to stop the column, hoping to stop on the target. If the player hits the target the then green LEDs will blink 3 times, if the player misses then the red LEDs will blink. The game will then restart.

##Setup

The game uses 12 standard LEDs (ideally 3 sets of 4 coloured LEDS, with a red and green sets) and a button, a Raspberry Pi and the WiringPi GPIO library. The LEDs should be positioned in column in a colour pattern (e.g. white, red, green, yellow) with each grounded via a resistor (in this case I'm using a 5mm LED with a 1000&#8486; resistor). A button should be placed below the last LED and connected to ground. Then connect each LED and button to the Raspberry Pi's GPIO pins using the table below:

|          | WiringPi Pin  | rPi Header Pin  |
|----------|---------------|-----------------|
| LED 1    | 0             | 11              |
| LED 2    | 1             | 12              |
| LED 3    | 2             | 13              |
| LED 4    | 3             | 15              |
| LED 5    | 4             | 16              |
| LED 6    | 5             | 18              |
| LED 7    | 6             | 22              |
| LED 8    | 7             | 7               |
| LED 9    | 8             | 3               |
| LED 10   | 9             | 5               |
| LED 11   | 10            | 24              |
| LED 12   | 11            | 26              |
| BUTTON   | 12            | 19              |

###Breadboard diagram
![Breadboard diagram](https://github.com/DanielHartUK/RPi-Reaction-game/blob/master/breadboarddiagram.png?raw=true)

##Compiling

You'll need to install WiringPi first to compile the code, full instructions can be found on the [WiringPi website](http://wiringpi.com/download-and-install/)

To compile:
`gcc -Wall -o game game.c -lwiringPi`

And then to run:
`sudo ./game`

