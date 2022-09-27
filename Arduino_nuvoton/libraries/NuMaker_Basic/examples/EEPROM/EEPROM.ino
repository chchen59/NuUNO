/*
		This sample code sets I2C bus clock to 100kHz. Then, accesses EEPROM 24LC64 with Byte Write
		and Byte Read operations, and check if the read data is equal to the programmed data.
        
		This example code is in the public domain.
*/



#include <Wire.h>
#include <EEPROM.h>

void setup()
{
  Serial1.begin(115200);
  
  /* Programming EEPROM */
  int reading;  
  for(int i=0;i<256;i++)
  {    
    EEPROM.write(i,i);  /* Write EEPROM */
  }
     
  for(int i=0;i<256;i++)
  {
     reading=EEPROM.read(i);  /* Read EEPROM */
     Serial1.print(reading);   /* print the reading */
     Serial1.print("\t");        
  }     
}

void loop()
{

}