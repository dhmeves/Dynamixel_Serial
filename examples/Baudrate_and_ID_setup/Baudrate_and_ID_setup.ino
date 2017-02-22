/*
This is a setup sketch for only one MX, AX, or RX servo connected and it is used as an example for setting the ID and Baudrate of the Dynamixel actuator

Please refer to the README for Wiring instructions.

After about 30 seconds and if connected correctly, the Dynamixel should start to move with its LED turning ON and OFF.

Robotis e-Manual ( http://support.robotis.com )

*/


#include <Dynamixel_Serial.h>       // Library needed to control Dynamixal servo

#define SERVO_ID 0x01               // ID of which we will set Dynamixel too 
#define SERVO_ControlPin 0x02       // Control pin of buffer chip, NOTE: this does not matter becasue we are not using a half to full contorl buffer.
#define SERVO_SET_Baudrate 19200  // Baud rate speed which the Dynamixel will be set too (19200 and 250k baud have the smallest timing errors on a 16MHz arduino and are preferred)
#define SERVO_DEF_Baudrate 57142  // Baud rate default for RX (57142 Baud). Must be exact or else the Arduino lib will round down to the nearest valid UBRR values which have too large of a timing error.
#define LED13 0x0D                  // Pin of Visual indication for runing "heart beat" using onboard LED


void setup(){
 pinMode(LED13, OUTPUT);            // Pin setup for Visual indication of runing (heart beat) program using onboard LED
 digitalWrite(LED13, HIGH);

 delay(1000);                                                 // Give time for Dynamixel to start on power-up

 for (int b=1; b<0xFF; b++){                                  // This "for" loop will take about 20 Sec to compelet and is used to loop though all speeds that Dynamixel can be and send reset instuction 
    long Baudrate_BPS = 0;
    Baudrate_BPS  = 2000000 / (b + 1);                        // Calculate Baudrate as ber "Robotis e-manual"
      Dynamixel.begin(Serial1,Baudrate_BPS,SERVO_ControlPin);   // Set Ardiuno Serial speed and control pin      
        Dynamixel.reset(0xFE);                                // Broadcast to all Dynamixel IDs(0xFE is the ID for all Dynamixel to responed) and Reset Dynamixel to factory default
        delay(5);
         
 } 
 digitalWrite(LED13, LOW);
 
 delay(3000);                                                 // Give time for Dynamixel to reset

 // Now that the Dynamixel is reset to factory setting we will program its Baudrate and ID
 Dynamixel.begin(Serial1,SERVO_DEF_Baudrate,SERVO_ControlPin); 
 Dynamixel.setID(0xFE,SERVO_ID);                               // Broadcast to all Dynamixel IDs(0xFE) and set with new ID
 delay(10);                                                     // Time needed for Dynamixel to set it's new ID before next instruction can be sent
 Dynamixel.setStatusPaket(SERVO_ID,READ);                      // Tell Dynamixel to only return status packets when a "read" instruction is sent e.g. Dynamixel.readVoltage();
 delay(10);
 Dynamixel.setBaudRate(SERVO_ID,SERVO_SET_Baudrate);           // Set Dynamixel to new serial speed 
 delay(30);                                                    // Time needed for Dynamixel to set it's new Baudrate


  Dynamixel.begin(SERVO_SET_Baudrate,SERVO_ControlPin);    // We now need to set Ardiuno to the new Baudrate speed 
  Dynamixel.ledState(SERVO_ID, ON);                            // Turn Dynamixel LED on
  delay(5);
  Dynamixel.setMode(SERVO_ID, SERVO,0x0000,0x3FF);              // Turn mode to SERVO, must be WHEEL if using wheel mode
  delay(5);
  Dynamixel.setMaxTorque(SERVO_ID, 0x2FF);                     // Set Dynamixel to max torque limit
  delay(5);
  Dynamixel.setHoldingTorque(SERVO_ID, 0x1);                     // Set Dynamixel to max torque limit
}



// Flash Dynamixel LED and move Dynamixel to check that all setting have been writen
void loop(){
  digitalWrite(LED13, HIGH);                  // Turn Arduino onboard LED on
  Dynamixel.ledState(SERVO_ID, ON);           // Turn Dynamixel LED on
  delay(5);
  //Dynamixel.wheel(SERVO_ID,LEFT,0x3FF);              // Comman for Wheel mode, Move left at max speed  
  Dynamixel.servo(SERVO_ID,0x0001,0x0100);   // Comman for servo mode, Move servo to angle 1(0.088 degree) at speed 100
  delay(4000);
  
  digitalWrite(LED13, LOW);                  // Turn Arduino onboard LED off
  Dynamixel.ledState(SERVO_ID, OFF);         //Turn Dynamixel LED off
  delay(5);
  //Dynamixel.wheel(SERVO_ID,RIGHT,0x3FF);          // Comman for Wheel mode, Move right at max speed 
  Dynamixel.servo(SERVO_ID,0x02FF,0x03FF);  // Comman for servo mode, Move servo to max angle at max speed (angle
  delay(4000);
  
}
