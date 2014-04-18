/*
 OptiMouse.cpp - Part ofoptical mouse sensor library for Arduino
 Copyright (c) 2008 Martijn The.  All right reserved.
 http://www.martijnthe.nl/
 Conversion to Arduino 1.x by zapmaker (zapmaker.org)
 
 Based on sketches by Benoît Rousseau.
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

/******************************************************************************
 * Includes
 ******************************************************************************/

#include "OptiMouse.h"

/******************************************************************************
 * Definitions
 ******************************************************************************/


/******************************************************************************
 * Constructors
 ******************************************************************************/

OptiMouse::OptiMouse(uint8_t sclkPin, uint8_t sdioPin)
{
  _sclkPin = sclkPin;
  _sdioPin = sdioPin;
  pinMode (_sclkPin, OUTPUT);
  pinMode (_sdioPin, INPUT);
}


/******************************************************************************
 * User API
 ******************************************************************************/

void OptiMouse::begin(void)
{
	// Re-sync (see datasheet §5.4):
	// Toggle the SLCK line from high to low to high....
	digitalWrite(_sclkPin, HIGH);                     
	delayMicroseconds(5);
	digitalWrite(_sclkPin, LOW);
	delayMicroseconds(1);
	digitalWrite(_sclkPin, HIGH);
	
	// Wait at least tSIWTT (0.9 second?) for the
	// OptiMouse serial transaction timer to time out:
	delay(1000);
}

// Private Methods /////////////////////////////////////////////////////////////


uint8_t OptiMouse::readRegister(uint8_t address)
{
	int i = 7;
	uint8_t r = 0;
	
	// Write the address of the register we want to read:
	pinMode (_sdioPin, OUTPUT);
	for (; i>=0; i--)
	{
		digitalWrite (_sclkPin, LOW);
		digitalWrite (_sdioPin, address & (1 << i));
		digitalWrite (_sclkPin, HIGH);
	}
	
	// Switch data line from OUTPUT to INPUT
	pinMode (_sdioPin, INPUT);
	
	// Wait a bit...
	delayMicroseconds(100);
	
	// Fetch the data!
	for (i=7; i>=0; i--)
	{                             
		digitalWrite (_sclkPin, LOW);
		digitalWrite (_sclkPin, HIGH);
		r |= (digitalRead (_sdioPin) << i);
	}
	delayMicroseconds(100);
	
	return r;
}

void OptiMouse::writeRegister(uint8_t address, uint8_t data)
{
	int i = 7;
	
	// Set MSB high, to indicate write operation:
	address |= 0x80;
	
	// Write the address:
	pinMode (_sdioPin, OUTPUT);
	for (; i>=0; i--)
	{
		digitalWrite (_sclkPin, LOW);
		digitalWrite (_sdioPin, address & (1 << i));
		digitalWrite (_sclkPin, HIGH);
	}
	
	// Write the data:
	for (i=7; i>=0; i--)
	{
		digitalWrite (_sclkPin, LOW);
		digitalWrite (_sdioPin, data & (1 << i));
		digitalWrite (_sclkPin, HIGH);
	}
}
