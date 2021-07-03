[![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)](http://www.gnu.org/licenses/gpl-3.0)

# ESP32SharpIR
An Arduino library for ESP32 development board that can measure distance from an analog Sharp IR sensor.

## Currently supported sensor models
- GP2Y0A21YK0F  

## Usage
- Adding the library to the sketch

~~~c++
#include <ESP32SharpIR.h>
~~~

- Creating an instance  

~~~c++
SharpIR sensorName(sensorModel, sensorPin);
~~~
~~~
sensorName	: the name of the object   
sensorModel	: the model code of the sensor (e.g. GP2YA41SK0F)  
sensorPin	: the analog pin where the sensor Vout pin is attached  
~~~    

- Acquiring data

~~~c++
sensorName.getDistance();
sensorName.getDistance( avoidBurstRead );
~~~
~~~
avoidBurstRead	: can be true or false
~~~

The above method returns an uint8_t type value that is the distance in centimeters from the sensor and the object in front of it.  
By default burst reads are avoided but this causes a delay of 20ms on every call.
In order to speed up the sketch is possible to allow bust reads by setting the parameter **avoidBurstRead** to **false**, in this way:


~~~c++
sensorName.getDistanceFloat();
sensorName.getDistanceFloat(  avoidBurstRead  );
~~~

Above method returns the distance in cm, as a float value filtered by exponent filter. 

~~~c++
sensorName.getRawDistance();
sensorName.getRawDistance(  avoidBurstRead  );
~~~

Above method returns just the raw distance read by the sensor, without applying any filter in cm.

~~~c++
sensorName.setFilterRate(float rate);
~~~

~~~
rate	: a value from the range from 0.01 to 0.99. 
		  0.01 equal to sampling 100 values and getting the average.
~~~


## License ##
<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">
<img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" />
</a>
<br />
<span xmlns:dct="http://purl.org/dc/terms/" property="dct:title">The SharpIR Library</span>
by <a xmlns:cc="http://creativecommons.org/ns#" href="https://nuwanjaliyagoda.com" property="cc:attributionName" rel="cc:attributionURL">Nuwan Jaliyagoda</a> is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">Creative Commons Attribution-ShareAlike 4.0 International License</a>

The library is based on the library 'Arduino_SharpIR', written by <a xmlns:cc="http://creativecommons.org/ns#" href="https://facebook.com/dev.giuseppemasino" property="cc:attributionName" rel="cc:attributionURL">Giuseppe Masinos</a>
