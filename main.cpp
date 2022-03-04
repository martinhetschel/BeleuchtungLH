#include <iostream>
#include "arduino.hpp"

constexpr uint8_t INTERVAL{30}; // in seconds

constexpr uint8_t OUTCOUNT{12}; // number of OUT ports
constexpr uint8_t OUT[]{3,4,5,6,7,8,9,10,11,12,13,14};

constexpr uint16_t LIGHTCOUNT{21}; // number of elements of LIGHT
constexpr uint16_t LIGHT[]{
	3085,
	3894,
	2559,
	3006,
	3982,
	1437,
	1940,
	2900,
	3573,
	3061,
	3558,
	2026,
	507,
	511,
	414,
	926,
	414,
	1980,
	1465,
	1489,
	208
};

void setOutput(uint16_t const state){
	for(uint8_t i=0; i<OUTCOUNT; ++i){
		bool out = (state >> i) & 1;
		digitalWrite(OUT[i], out?HIGH:LOW);	
	}
}

void setup(){
	for (size_t i=0; i<OUTCOUNT; ++i ){
		pinMode(OUT[i], OUTPUT);
	}
}

void loop(){
	for (uint16_t count=0; count< LIGHTCOUNT; ++count){
		setOutput(LIGHT[count]);
		delay(INTERVAL * 1000);
	}
}

 