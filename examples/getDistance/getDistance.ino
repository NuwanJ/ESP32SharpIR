
#include <ESP32SharpIR.h>

ESP32SharpIR sensor( ESP32SharpIR::GP2Y0A21YK0F, 27);

void setup() {
  Serial.begin(115200);
  
  // Setting the filter resolution to 0.1
  sensor.setFilterRate(0.1f);
}

void loop() {

  // Print distance in cm
  //Serial.println(sensor.getDistance());

  // Print distance in cm, as a float value
  Serial.println(sensor.getDistanceFloat());
  
  delay(100);
}
