/*
 PAN3101.h - Part of optical mouse sensor library for Arduino
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

#ifndef PAN3101_h
#define PAN3101_h

#include "Arduino.h"
#include <inttypes.h>

#include "OptiMouse.h"

class PAN3101 : public OptiMouse
{
  private:
	uint8_t _status;
  public:
	PAN3101(uint8_t, uint8_t);
	void updateStatus(void);
	signed char dx(void);
	signed char dy(void);
	uint8_t motion() const;
	uint8_t dxOverflow() const;
	uint8_t dyOverflow() const;
};

#endif
