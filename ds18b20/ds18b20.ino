#include "ds18b20.h"

#ifdef LINE
ds18b20 ds(D4, "Hs home", "home0907", "b3P2r1H7PE6JVxLo1KnvEj", "maker.ifttt.com");
#endif

#ifndef LINE
ds18b20 ds(D4, "Hs home", "home0907", "2A9M6IPTQ6DVLGHK", "api.thingspeak.com");
#endif


void setup(void)
{
  ds.setup();
}
 
 
void loop(void)
{
  ds.sendTemperature(ds.getTemperature());
  
  #ifdef LINE
  delay(5000);
  #endif
  
  #ifndef LINE
  delay(60000);
  #endif
}

