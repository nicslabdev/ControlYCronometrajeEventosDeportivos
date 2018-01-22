/*********************************************************************************************/
/*
 * Serial interface Arduino library
 * Created by Manuel Montenegro, January 20, 2017.
 * Developed for Manuel Montenegro Final Year Project. 
 * 
 *  This library is used for establishing a communication with PC by serial port and allows
 *	users to interact with Arduino easily. Serial interface is an abstraction opened to be 
 *	implemented. This library is only a simple implementation.
 *
 *	The use of this library is compatible with any serial port monitor, like Serial Monitor of
 *	Arduino IDE, GoSerial (Mac) or Putty (Windows).
*/
/*********************************************************************************************/

#include <SerialInterface.h>

SerialInterface::SerialInterface () {}

// Starts a interactive menu through serial port
uint8_t SerialInterface::introMenu () {

	Serial.println (F("\n --------------------------------------------"));
	Serial.println (F(" | MASTER device for setting up sport event |"));
	Serial.println (F(" --------------------------------------------"));
	Serial.println (F(" Please, send the option number of your choice"));
	Serial.println (F(" What do you want to do?"));
	Serial.println (F("   1. Set up and start a new event"));
	Serial.println (F("   2. Continue setting up an event"));
	Serial.println (F("   3. Clean card"));
	Serial.println (F("   4. Read card\n"));

	uint8_t userChoose;
	while (!Serial.available());      // Waits until the user send the answer
	userChoose = Serial.read ();      // Reads the answer
	while (Serial.available()) {      // Cleans the serial port (if more than 1 char introduced)
		Serial.read();
	}
	return (char)userChoose;
}

// Interactive menu about setting up each station
uint8_t SerialInterface::setupMenu (uint8_t stationID) {
	Serial.print (F("\n Put station #"));
	Serial.print (stationID);
	Serial.println (F(" on card reader"));
	Serial.println (F(" After that, send the option number of your choice"));
	Serial.println (F("   1. Set up this station"));
	Serial.println (F("   2. Finish the setup process\n"));

	uint8_t userChoose;
  	while (!Serial.available());      // Waits until the user send the answer
	userChoose = Serial.read ();      // Reads the answer
	while (Serial.available()) {      // Cleans the serial port (if more than 1 char introduced)
		Serial.read();
	}
	return (char)userChoose;
}