/*
 ADNS2620.h - Part of optical mouse sensor library for Arduino
 Copyright (c) 2008 Martijn The.  All right reserved.
 http://www.martijnthe.nl/
 2620 derived from 2610 by zapmaker (zapmaker.org)
 Conversion to Arduino 1.x by zapmaker
 
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

#ifndef ADNS2620_h
#define ADNS2620_h

#include <inttypes.h>
#include "OptiMouse.h"

class ADNS2620 : public OptiMouse
{
  private:
  public:
  	ADNS2620(uint8_t, uint8_t);
	signed char config(void);
	void writeConfig(signed char c);
	signed char status(void);
	signed char dx(void);
	signed char dy(void);
	signed char squal(void);
	signed char maxPix(void);
	signed char minPix(void);
	signed char pixSum(void);
	signed char shUp(void);
	signed char shDown(void);
	signed char framePer(void);
	void startPixRead(void);
	signed char pixRead(void);

	
};

#endif
