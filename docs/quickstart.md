



<div class="grid cards desc" markdown>

-    <a href="https://www.sparkfun.com/products/iot-redboard-rp2350.html">
    **SparkFun IoT RedBoard - RP2350**<br>
    **SKU:** WRL-27708

    ---

    <figre markdown>
    ![Product Thumbnail](./assets/img/SparkFun_IoT_RedBoard-RP2350.jpg)
    </figure></a>

    <center>
    <article class="video_desc">
    <iframe src="https://www.youtube.com/embed/umC06onaavo?si=j9rEibxVvqwawaoB" title="Product Showcase: SparkFun Thing Plus - RP2350" frameborder="0" allow="accelerometer; autoplay; clipboard-write;encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
    </article>
    </center>

-   Welcome to the SparkFun IoT RedBoard - RP2350 Quick Start Guide. This streamlined version of our standard Hookup Guides assumes a working knowledge of how to use a development board and the required software to program them for your project's needs. It covers a quick assembly and then jumps right into getting the necessary software packages installed to start uploading code in just a few short minutes. The guide finishes with simple examples for each development environment showing how to set up and use the RM2 wireless chip to connect to a WiFi network.
<br>
<br>
If you're not familiar with using development boards or the development environments covered in this guide, refer to the Hardware & Software tabs above for a detailed overview of the board along with instructions on programming the IoT RedBoard - RP2350.

</div>

## Basic Assembly

Start by plugging the IoT RedBoard - RP2350 into your computer using a USB-C connector. 

<figure markdown>
[![Photo showing RedBoard IoT - RP2350 connected over USB-C](./assets/img/SparkFun_IoT_RedBoard-RP2350.jpg){ width="600"}](./assets/img/SparkFun_IoT_RedBoard-RP2350.jpg "Click to enlarge")
</figure>

## Software Setup

Next up we'll cover how to upload to the IoT RedBoard - RP2350 using preferred development environment(s). If you're using any peripherals (Qwiic boards, shields, etc.) connect those now or after installing the board packages. Make sure to install any software packages or libraries for any connected peripherals.

### Raspberry Pi Pico SDK

The IoT RedBoard - RP2350 is supported in **version needed - ML** of the Pico SDK. Upload to it by selecting `sparkfun_redboard_rp2350`.

### MicroPython

The IoT RedBoard - RP2350 has Beta releases of MicroPython firmware available [here](https://github.com/sparkfun/micropython/releases) or by clicking the button below:

<center>
    [SparkFun MicroPython Beta Releases](https://github.com/sparkfun/micropython/releases){ .md-button .md-button--primary}
</center>

Put the IoT RedBoard in bootloader mode by pressing and holding the RESET button while pressing and releasing the BOOT button. Once in bootloader mode, navigate to the RedBoard's drive location and copy the UF2 file into the drive.

### Arduino IDE

The IoT RedBoard - RP2350 board definition is included in the [Arduino-Pico](https://github.com/earlephilhower/arduino-pico) boards package. Make sure to install or update to the latest Arduino-Pico release and select `SparkFun IoT RedBoard - RP2350` as your board.

## Code Examples

The following examples all complete the same task of connecting the IoT RedBoard - RP2350 to a WiFi network and pinging a site. They also include a visual indicator of the connection status using the RGB LED on the board like the photos below show:

<div class="grid cards hide col-4" markdown align="center">

-	<figure markdown>
	[![Photo showing WS2812 set to RED.](./assets/img/Thing_Plus_RP2350-RED.jpg){ width="600"}](./assets/img/Thing_Plus_RP2350-RED.jpg "Click to enlarge")
	<fig caption>LED set to <b>RED</b> while connecting to WiFi.</fig caption>
	</figure>

-	<figure markdown>
	[![Photo showing WS2812 set to BLUE.](./assets/img/Thing_Plus_RP2350-BLUE.jpg){ width="600"}](./assets/img/Thing_Plus_RP2350-BLUE.jpg "Click to enlarge")
	<fig caption>LED set to <b>BLUE</b> while downloading.</fig caption>
	</figure>

-	<figure markdown>
	[![Photo showing WS2812 set to GREEN.](./assets/img/Thing_Plus_RP2350-GREEN.jpg){ width="600"}](./assets/img/Thing_Plus_RP2350-GREEN.jpg "Click to enlarge")
	<fig caption>LED set to <b>GREEN</b> indicating download success.</fig caption>
	</figure>
</div>

Before running the examples, adjust the template values called <code>WIFI_NETWORK</code> and <code>WIFI_PASSWORD</code> with your WiFi network ID and password.

### Pico SDK

**Insert example code - ML**

### MicroPython

**Insert example code - ML**

### Arduino

**Insert example code - ML**