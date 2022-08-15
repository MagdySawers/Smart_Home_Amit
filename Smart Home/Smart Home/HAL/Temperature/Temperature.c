 #include "Temperature.h"
 
 
 u16 Temperature_value(u16 ADC)
 {
	 float mVolt = (ADC / 1023.0) * 5000;
	 u16 Temperture= mVolt / 10;
	 
	 return Temperture;
 }
