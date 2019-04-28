#include "ESP32SharpIR.h"

ESP32SharpIR::ESP32SharpIR( sensorCode _sensorType , uint8_t _sensorPin ) {

  // Assign sensor type and pin number
  sensorType = _sensorType;
  pin = _sensorPin;

  // Set ADC unit resolution on ESP32
  analogReadResolution(ANALOG_RESOLUTION);

}

void ESP32SharpIR::setFilterRate(float rate) {
  if (rate > 0 && rate < 1) alpha = rate;
}

float ESP32SharpIR::getDistanceFloat(bool avoidBurstRead ) {
  if ( !avoidBurstRead ) while ( millis() <= lastTime + 20 ) {}	//wait for sensor's sampling time

  rawDistance = getRawDistance(avoidBurstRead);
  average = (alpha * rawDistance) + (1 - alpha) * average;  			// exponential smoothing

#ifdef DEBUG
  Serial.printf("%f %f\n", rawDistance, average);
#endif

  return average;
}

uint8_t ESP32SharpIR::getDistance(bool avoidBurstRead ) {
  return (uint8_t)getDistanceFloat(avoidBurstRead );
}


uint8_t ESP32SharpIR::getRawDistance( bool avoidBurstRead ) {
  uint8_t distance ;

  if (!avoidBurstRead) while ( millis() <= lastTime + 20 ) {} //wait for sensor's sampling time

  lastTime = millis();

  switch ( sensorType )
  {
    case GP2Y0A41SK0F :
      // TODO: Implement
      distance = 0;// 2076/(analogRead(pin)-11);

      if (distance > 30) return 31;
      else if (distance < 4) return 3;
      else return distance;

      break;

    case GP2Y0A21YK0F :

      distance = (28400) / (analogRead(pin));
      if (distance > 80) return 81;
      else if (distance < 10) return 9;
      else return distance;

      break;

    case GP2Y0A02YK0F :
      // TODO: Implement
      distance = 0;// 9462/(analogRead(pin)-16.92);

      if (distance > 150) return 151;
      else if (distance < 20) return 19;
      else return distance;
  }
}
/*
  // White Perpendicular Block, r [0:511]

  d   r   d*r
  10  330 3300
  12  285 3420
  14  250 3500
  16  230 3680
  18  190 3420
  20  180 3600
  22  160 3520
  24  150 3600
  26  140 3640
  28  130 3640
  30  125 3750

  avg =   3550

*/
