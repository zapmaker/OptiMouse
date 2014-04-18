/*
 OptiMouse.h - Part ofoptical mouse sensor library for Arduino
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

#ifndef OptiMouse_h
#define OptiMouse_h

#include "Arduino.h"
#include <inttypes.h>

class OptiMouse
{
  private:
  protected:
	uint8_t _sclkPin;
    uint8_t _sdioPin;
	uint8_t readRegister(uint8_t);
	void writeRegister(uint8_t, uint8_t);
  public:
    OptiMouse(uint8_t, uint8_t);
    void begin(void);
	signed char dx(void);
	signed char dy(void);
};

#endif
