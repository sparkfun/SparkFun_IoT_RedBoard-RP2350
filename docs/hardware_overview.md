---
icon: material/cog
---

This document gives a detailed overview of the RedBoard IoT - RP2350 and all components present on the board.

## RP2350 Microcontroller

The RP2350 from Raspberry Pi packs a whole lot of computing punch in a tiny package. The RP2350 is a unique dual-core microcontroller that has <i>four</i> internal processors (two Arm Cortex-M33 and two Hazard3 RISC-V processors @150 MHz), though you can only select any two of these four to run at the same time. 

This internal configuration allows users to customize the chip to use a pair their preferred architecture (ARM or Hazard3) or to use one of each! The RP2350 includes 520kB of on-chip SRAM in ten independent banks, 8kB of one-time-programmable (OTP) storage and this board also includes PSRAM connected to the chip's QSPI bus. The RP2350 also has a bevy of security features including optional boot signing with protected OTP storage for the boot decryption key, global bus filtering (based on either Arm or RISC-V security and privilege levels) and more.

The RedBoard IoT - RP2350 uses the "A" version of the microcontroller which has 30 5V-tolerant GPIO with 4 analog inputs and also includes the following peripheral options:

* 2x UART
* 2x SPI
* 2x I<sup>2</sup>C
* 24 PWM
* USB 1.1 Controller
* 12 PIO State Machines
* 1x High-Speed Transmit (HSTX) Peripheral for DVI/DSI support

For complete information on the RP2350, refer to the [datasheet](./assets/component_documentation/rp2350-datasheet.pdf).

## Memory

### W25Q128 Flash

The W25Q128 Flash IC adds 16MB of storage space on the RedBoard IoT. This connects to the RP2350 over QSPI.

### PSRAM

The board also includes an 8MB PSRAM IC for dynamic storage. This also connects to the RP2350 over QSPI. PSRAM support is included in the SparkFun MicroPython "early release" firmware found later in this guide and on the product page, but is not natively supported in the Pico SDK as of release. Refer to the Arducam Demo section of this guide for information on how to enable and set up PSRAM using the Pico SDK.

For a complete overview of the PSRAM IC, refer to the [datasheet](./assets/component_documentation/APS6404L_3SQR_Datasheet.pdf).

### &micro;SD Card Slot

The board has a &micro;SD card slot that connects to the RP2350's SPI bus for even more storage. Make sure the SPI are **LOW** when the &micro;SD card is **unpowered**. Setting these pins **HIGH** can damage the GPIO pins. The connector is a fricton-fit connector so no "clicking" and "unclicking" is necessary. Just plug it in nice and snug. 

## Raspberry Pi RM2 Radio Module

The Raspberry Pi RM2 (radio module 2) is built around the same chipset as the previous Raspberry Pi radio module found on boards like the Pico W. The module features both WiFi 4 (802.11n) 2.4GHz and  Bluetooth<sup>&trade;</sup> 5.2 with support for Low Energy (Central and Peripheral) and Classic. 

The RM2 communicates with the RP2350 over SPI and we've designed this board to use the same pins for the radio module as official Raspberry Pi boards (Pico W and Pico 2 W), making it easy to use the radio module without having to adjust anything from those development boards. The RedBoard IoT routes the module's GPIO0 pin to a blue STAT LED to allow users to create a visual indicator of the status of the module. We added this STAT LED connected to the same pin used on the Pico W to make code for that compatible with the RedBoard IoT - RP2350.

## Power

The RedBoard IoT - RP2350 includes several options for powering including USB-C, LiPo battery with on-board battery charging and monitoring circuits as well as direct power inputs.

### USB-C

The USB-C connector on the board acts as the primary serial interface for the RP2350 as well as a power input. The <b>5V</b> USB input voltage is regulated down to <b>3.3V</b> through a voltage regulator with a max current of <b>500mA@3.3V</b>.

### Barrel Jack

The barrel jack connector on this board accepts a supply voltage between <b>7V</b> and <b>15V</b>. This supply voltage includes a <b>16V/2.5A/5A</b> fuse.

### LiPo Power & Charging

The IoT RedBoard - RP2350 can also be powered with a single cell lithium battery through a 2-pin JST connector. The board also includes a MCP73831 LiPo charge IC as part of a charging circuit for a connected battery. The charge rate is set to <b>455mA</b> and is powered either via USB, barrel jack or dedicated pin. 

It also has a MAX17048 battery fuel gauge to monitor a connected battery's voltage level. The fuel gauge communicates with the RP2350 over I<sup>2</sup>C.

## Pinout

### R3 Footprint Female Headers

### HSTX Connector

### RP2350 Debug Connector

## LEDs

This board has four LEDs labeled <b>STAT/25</b>, <b>CHG</b>, <b>WRL</b>, <b>PWR</b> and <b>RGB/IO3</b>.

## Buttons

There are three push buttons on the board labeled <b>RESET</b>, <b>USER/36</b> and <b>BOOT</b>.

## Solder Jumpers