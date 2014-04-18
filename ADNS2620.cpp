/*
 ADNS2620.cpp - Part of optical mouse sensor library for Arduino
 Copyright (c) 2008 Martijn The.  All right reserved.
 http://www.martijnthe.nl/
 2620 derived from 2610 by zapmaker (zapmaker.org)
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
#include "ADNS2620.h"

/******************************************************************************
 * Definitions
 ******************************************************************************/

#define Delta_Y				0x42
#define Delta_X				0x43
#define SQual				0x44
#define MaxPix				0x45
#define MinPix				0x46
#define PixSum				0x47
#define PixData				0x48
#define ShutterUp			0x49
#define ShutterDown			0x4A
#define FramePeriod			0x4B

/******************************************************************************
 * Constructors
 ******************************************************************************/


ADNS2620::ADNS2620(uint8_t sclkPin, uint8_t sdioPin) : OptiMouse::OptiMouse(sclkPin, sdioPin)
{

}

/******************************************************************************
 * User API
 ******************************************************************************/

signed char ADNS2620::dx(void)
{
	return (signed char) readRegister(Delta_X);
}

signed char ADNS2620::dy(void)
{
	return (signed char) readRegister(Delta_Y);
}

signed char ADNS2620::squal(void)
{
	return (signed char) readRegister(SQual);
}

signed char ADNS2620::maxPix(void)
{
	return (signed char) readRegister(MaxPix);
}

signed char ADNS2620::minPix(void)
{
	return (signed char) readRegister(MinPix);
}

signed char ADNS2620::pixSum(void)
{
	return (signed char) readRegister(PixSum);
}

signed char ADNS2620::shUp(void)
{
	return (signed char) readRegister(ShutterUp);
}

signed char ADNS2620::shDown(void)
{
	return (signed char) readRegister(ShutterDown);
}

signed char ADNS2620::framePer(void)
{
	return (signed char) readRegister(FramePeriod);
}

// Private Methods /////////////////////////////////////////////////////////////

