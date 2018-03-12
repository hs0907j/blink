#include "ds18b20.h"

ds18b20 ds(D4, "Hs home", "home0907", "2A9M6IPTQ6DVLGHK");

void setup(void)
{
  ds.setup();
}
 
 
void loop(void)
{
  ds.sendTemperature(ds.getTemperature());
  delay(60000);
}

