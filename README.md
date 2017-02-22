Dynamixel Serial library
========================

Arduino library for interfacing with Dynamixel MX series servos over serial comm v1.0.

## Usage

### Connection of Dynamixel AX or MX to Arduino 

You do not need a half to full duplex circuit if you do not wish to receive ANY data FROM the Dynamixel servo, as we are only setting up the Dynamixel servo we will leave this circuit out and connect directly to Arduino to make things simple.

    AX/MX (Pin)            Arduino and/or Power supply (Pin)
    ====================================
    GND (1) -------------- GND (GND)
    +12V (2) -------------- +12v (VIN)
    DATA(3) -------------- TX (Arduino Pin 1) 


### Connection of Dynamixel RX to Arduino 

Signal conversion from TTL serial to RS485 using a MAX485 or equivalent is necessary in this case. Half duplex bidirectional communication are also supported using this interface.

A 0.1uF ceramic capacitor shoud be wired between the Vcc and ground pins of the MAX485 and placed
physically near the chip.

A 120 Ohm +- 10% resistor should also be connected between the A and B data lines at the output of
the MAX485 and at the end of the bus to prevent signal reflections and ensure reliable communication.

--Wiring--

    Dynamixel RX (Pin)      Device
    ====================================
    GND (1) -------------- GND
    +12V (2) ------------- +12v
    RS485_DATA+(3) ------  MAX485 pin 6
    RS485_DATA-(4) ------  MAX485 pin 7

Additionally, the following connections must be made between the MAX485 and Arduino:

    Arduino             Device
    ====================================
    GND (GND) --------- MAX485 pin 5 (GND)
    +5v --------------- MAX485 pin 8 (Vcc)
    Pin 2 ------------- MAX485 pins 2 and 3 (~RE and DE)
    TX (TX1 if Mega) -- MAX485 pin 4 (DI)
    RX (RX1 if Mega) -- MAX485 pin 1 (RO)


The ground must be common(connected) between the Arduino and Dynamixel servo. If the Arduino is NOT powered via USB, the +12v source may be connected to the barrel jack (preferred) or the Vin pin of the Arduino in order to power the Arduino. 

CAUTION: 
    The +12v power supply must not be greater then +14.8Vdc as per the Dynamixel datasheet.
    Take extreme care when connecting to the Dynamixel servo as incorrect connections, especially of power, will likely cause permanent damage.

## Changelog
* 21 February 2017 - Implement and document RX series servo support as well as Arduino 1.6.x compatibility. Fix build errors in examples. 
* 25 March 2015 -  Library migrated to GitHub.
* 25 April 2013 - A few errors have been fixed in Dynamixel Library
* 28 June 2012 - Dynamixel Library re-written from the ground up... there is no longer missed commands set to the servo.
* 10 April 2012 - Dynamixel Library now has example of how to set-up and program a Dynamixel Servo via a Arduino
* 17 January 2012 - Library and Arduino sketch in download section updated to work with Ardunio 1.0

## More Information
* Robotis e-Manual<br/>
  [http://support.robotis.com](http://support.robotis.com)
* Communication Overview<br/>
  [http://support.robotis.com/en/product/dynamixel/dxl_communication.htm](http://support.robotis.com/en/product/dynamixel/dxl_communication.htm)
* MX Series Control Table<br/>
  [http://support.robotis.com/en/product/dynamixel/mx_series/mx-64.htm](http://support.robotis.com/en/product/dynamixel/mx_series/mx-64.htm)
* Instruction Packet & Status Packet<br/>
  [http://support.robotis.com/en/product/dynamixel/communication/dxl_packet.htm](http://support.robotis.com/en/product/dynamixel/communication/dxl_packet.htm)
* Instruction Packet Examples<br/>
  [http://support.robotis.com/en/product/dynamixel/communication/dxl_instruction.htm](http://support.robotis.com/en/product/dynamixel/communication/dxl_instruction.htm)

## Attribution
Original code by J.Teda [https://code.google.com/p/slide-33/](https://code.google.com/p/slide-33/)
Notable contributions by Nash Kaminski

## License
Released under LGPL, see `LICENSE.txt`
