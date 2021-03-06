/*********************************************************************************************/
/*
 * MASTER-Card
 * Created by Manuel Montenegro, February 21, 2018.
 * Developed for Manuel Montenegro Bachelor Thesis. 
 * 
 *  This sketch reads and format player cards.
 * 
 *  This sketch must be uploaded in master device. Serial connection to PC and NFC shield is 
 *  required. Serial port baudrate: 115200
 *  
 *  Compatible boards with this sketch: Arduino UNO, Arduino Leonardo.
*/
/*********************************************************************************************/

//#include <SetUpStations.h>          // Stations' setup library
#include <PlayerCard.h>             // User's card management library
#include <SerialInterface.h>        // Serial communication with PC library

uint8_t userChoice;                 // User choose from serial menu

SerialInterface usb;

void setup() {

  Serial.begin (115200);            // Sets up serial port baudrate
  while (!Serial);                  // Waits until serial port is opened in PC
}

void loop() {

  userChoice = usb.receiveChoiceSendAck();
  
  if (userChoice == '3') {
    PlayerCard card;
    card.begin();
    card.format(); 
  } else if (userChoice == '4') {
    PlayerCard card;
    card.begin();
    card.readPunches();
  }


}
