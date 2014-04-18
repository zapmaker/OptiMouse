// This example reads out the PAN3101 Optical Navigation Sensor
// It's used in many cheap optical mouses.
//
// For support for the Agilent ADNS-2051 or ADNS-2610, move the
// files for your mouse to the folder with the OptiMouse files.
// Then uncomment the right header files and object instances below.
//
// The Arduino reads out the dx register and passes it through
// the serial port, at a regular interval. So practically,
// it measures the speed of the surface.
//
// Written by Martijn The -> post [at] martijnthe.nl
// Tutorial: http://www.martijnthe.nl/optimouse/
// Based on the sketches by Beno”t Rousseau

#include "PAN3101.h"
// #include "ADNS2051.h"
// #include "ADNS2610.h"
// #include "ADNS2620.h"

#define SCLK 2                            // Serial clock pin on the Arduino
#define SDIO 3                            // Serial data (I/O) pin on the Arduino

PAN3101 Optical1 = PAN3101(SCLK, SDIO);   // Create an instance of the PAN3101 object
// ADNS2051 Optical1 = ADNS2051(SCLK, SDIO);
// ADNS2610 Optical1 = ADNS2610(SCLK, SDIO);
// ADNS2610 Optical1 = ADNS2610(SCLK, SDIO);

void setup()
{
  Serial.begin(38400);
  Optical1.begin();                        // Resync (really necessary?)
}

void loop()
{
  // It's also possible to check whether the internal counter of the sensor
  // has rolled over (overflow), on the PAN3101 and the ADNS2051:
  
  // Optical1.updateStatus();
  // if (Optical1.dxOverflow()) Serial.println("Overflow...");
  
  
  Serial.println(Optical1.dx(), DEC);
  delay(5);
}

