/*
 ADNS2051.cpp - Part of optical mouse sensor library for Arduino
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

#include "Arduino.h"
#include "OptiMouse.h"
#include "ADNS2051.h"

/******************************************************************************
 * Definitions
 ******************************************************************************/

#define Delta_Y				0x04
#define Delta_X				0x03
#define Motion_Status		0x02

#define Mask_Motion			0x80
#define Mask_DYOVF			0x10
#define Mask_DXOVF			0x08

/******************************************************************************
 * Constructors
 ******************************************************************************/


ADNS2051::ADNS2051(uint8_t sclkPin, uint8_t sdioPin) : OptiMouse::OptiMouse(sclkPin, sdioPin)
{

}

/******************************************************************************
 * User API
 ******************************************************************************/

void ADNS2051::updateStatus(void)
{
	_status = readRegister(Motion_Status);
}

signed char ADNS2051::dx(void)
{
	return (signed char) readRegister(Delta_X);
}

signed char ADNS2051::dy(void)
{
	return (signed char) readRegister(Delta_Y);
}

uint8_t ADNS2051::motion() const
{
	return (uint8_t) (_status & Mask_Motion) == Mask_Motion;
}

uint8_t ADNS2051::dxOverflow() const
{
	return (uint8_t) (_status & Mask_DXOVF) == Mask_DXOVF;
}
uint8_t ADNS2051::dyOverflow() const
{
	return (uint8_t) (_status & Mask_DYOVF) == Mask_DYOVF;
}

// Private Methods /////////////////////////////////////////////////////////////

