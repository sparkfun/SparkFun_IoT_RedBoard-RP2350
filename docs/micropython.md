## Setup

MicroPython is an application of the Python 3 language that runs on microcontrollers like the IoT RedBoard - RP2350 that allows you to easily interact with the board directly over a USB serial interface through either a command line interface or your preferred Python IDE such as [Thonny](https://thonny.org/). We'll do a quick overview of how to download MicroPython firmware on to the RedBoard IoT - RP2350 but for a complete overview of using MicroPython with this and other RP2350 boards, head over to Raspberry Pi's documentation by clicking the button below:

<center>
    [Raspberry Pi MicroPython Docs](https://www.raspberrypi.com/documentation/microcontrollers/micropython.html){ .md-button .md-button--primary}
</center>

## UF2 Firmware

The SparkFun IoT RedBoard - RP2350 ships with MicroPython firmware pre-loaded so you do not need to download and install it in your board. If you need to update the firmware at any point, it is available in the main release of MicroPython [here](https://micropython.org/download/). Search for "SparkFun IoT RedBoard - RP2350" on the MicroPython downloads page for the correct firmware. This release does **not** include PSRAM support; if your project requires using PSRAM, you can find a Beta release MicroPython firmware available [here](https://github.com/sparkfun/micropython/releases).

Download the latest release and then put the IoT RedBoard - RP2350 into UF2 bootloader mode and open the location the board appeared as a USB storage device (it should appear as "RP2350"). Next, drag and drop the UF2 file into the RP2350 folder and the board should reboot. After the board reboots, open up your preferred MicroPython IDE (or command line interface) and you can start interacting with your RedBoard IoT. Head over to the Quick Start guide for an example project that shows how to connect the board to a WiFi network, download data from a website and control the RGB LED.