// This example reads out the PixArt PAN3101 Optical Navigation Sensor
// It's used in many cheap optical mouses.
//
// For support for the Agilent ADNS-2051, ADNS-2083 or ADNS-2610, move
// the files for your mouse to the folder with the OptiMouse files.
// Then uncomment the right header files and object instances below.
//
// The Arduino will keep track of a (x, y) coordinate by increasing
// or decreasing the x and y variables by dx and respectively dy.
// Every 128th sample it reports the current (x, y) over the Serial.
//
// Written by Martijn The -> post [at] martijnthe.nl
// Tutorial: http://www.martijnthe.nl/optimouse/
// Based on the sketches by Beno”t Rousseau

#include "PAN3101.h"
// #include "ADNS2051.h"
// #include "ADNS2610.h"
// #include "ADNS2620.h"
// #include "ADNS2083.h"

#define SCLK 2                            // Serial clock pin on the Arduino
#define SDIO 3                            // Serial data (I/O) pin on the Arduino

PAN3101 Optical1 = PAN3101(SCLK, SDIO);   // Create an instance of the PAN3101 object
// ADNS2051 Optical1 = ADNS2051(SCLK, SDIO);
// ADNS2610 Optical1 = ADNS2610(SCLK, SDIO);
// ADNS2620 Optical1 = ADNS2620(SCLK, SDIO);
// ADNS2083 Optical1 = ADNS2083(SCLK, SDIO);

signed long x = 0;                        // Variables for our 'cursor'
signed long y = 0;                        //

int c = 0;                                // Counter variable for coordinate reporting

void setup()
{
  Serial.begin(38400);
  Optical1.begin();                       // Resync (not really necessary?)
}

void loop()
{

//  The status commands are available only for the PAN3101 and the ADNS2051:

//  Optical1.updateStatus();                // Get the latest motion status
//  if (Optical1.motion())                  // If the 'Motion' status bit is set,
//  {

    x += Optical1.dx();                   // Read the dX register and in/decrease X with that value
    y += Optical1.dy();                   // Same thing for dY register.....

//  }
  
  if (c++ & 0x80)
  {                                       // Report the coordinates once in a while...
    Serial.print("x=");
    Serial.print(x, DEC);
    Serial.print(" y=");
    Serial.print(y, DEC);
    Serial.println();
    c = 0;                                // Reset the report counter
  }
}


