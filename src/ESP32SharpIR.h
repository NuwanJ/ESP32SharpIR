/*
   SEP32-SharpIR
   Library for the acquisition of distance data from Sharp IR sensors
*/

#pragma once

#include <Arduino.h>

#define ANALOG_RESOLUTION 12

//#define DEBUG

class ESP32SharpIR
{
  public:

    using sensorCode = const uint8_t ;

    ESP32SharpIR( sensorCode _sensorType , uint8_t _sensorPin ); 
    
    float getDistanceFloat(bool avoidBurstRead = true);

    uint8_t getRawDistance( bool avoidBurstRead = true );
    uint8_t getDistance(bool avoidBurstRead = true);

    void setFilterRate(float rate);

    static sensorCode GP2Y0A41SK0F = 0;
    static sensorCode GP2Y0A21YK0F = 1;
    static sensorCode GP2Y0A02YK0F = 3;

  protected:
    uint8_t sensorType, pin ;

  private:
    float alpha = 0.2f;
    float average = 25.0f;
    float rawDistance = 0.0f;
    uint32_t rawReading = 0;
    uint32_t lastTime = 0 ;
};
