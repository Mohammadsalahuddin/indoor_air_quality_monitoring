
//please add the thinger.io lib for arduino, using arduino library manager.
//please add the thinger.io lib for arduino, using arduino library manager.
// or check the thinger.io documentation

#include <YunClient.h>
#include <ThingerYun.h>

#define USERNAME "__________YOUR_____USER____NAME____"
#define DEVICE_ID "__________YOUR DEVICE_____ID_____"
#define DEVICE_CREDENTIAL "_____YOUR___CREDENTIAL_____"

ThingerYun thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);


void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);

  // initialize bridge
  Bridge.begin();


  // resource output example (i.e. reading a sensor value, a variable, etc)
  thing["LPG"] >> outputValue(analogRead(A0)); // optional 
  thing["CO2"] >> outputValue(analogRead(A1));
  thing["CO"] >> outputValue(analogRead(A2));
  thing["AIRQ"] >> outputValue(analogRead(A3));

  // more details at http://docs.thinger.io/arduino/
}

void loop() {
  thing.handle();
}