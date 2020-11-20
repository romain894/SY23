/*
 * comI2C.c
 *
 * Copyright 2020 Michel Doussot <michel@doussot>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

#include <Arduino.h>
#include <Wire.h>

#define RegTe 0x00
#define RegTh 0x01
#define RegConf 0x02
#define PmodHygroID 0x40

uint16_t temperature, humidity = 0;
float tempF, humF;
void setup() {
	Serial.begin(9600);
	Serial.println("Hello");
	Wire.begin();
}

// Temperature formula given
float getTemp(uint16_t temperature){
	float celsius;
	celsius = ((float)temperature/0x10000) * 165.0 - 40.0;
	return celsius;

}

//Humidity formula given
float getHumidity(uint16_t humidity){
	float percent;
	percent = ((float) humidity/0x10000) * 100.0;
	return percent;
}

void loop(){
	Wire.beginTransmission(PmodHygroID);
	Wire.write(RegTe);
	Wire.write(RegTh);
	Wire.endTransmission();

	Wire.requestFrom(PmodHygroID, 4);
	if (Wire.available()){
		temperature <<= 8;	//Shift left, MSB read first
		temperature = (uint16_t) Wire.read(); //Wire.read() returns a byte, conversion to uint16_t
		temperature <<= 8;	//Shift left, MSB read first
		temperature |= (uint16_t) Wire.read();	//Addition with the 2nd byte received and converted to uint16_t


		humidity <<= 8;
		humidity = (uint16_t) Wire.read();
		humidity <<= 8;
		humidity |= (uint16_t)Wire.read();
	}

	tempF = getTemp(temperature);
	humF = getHumidity(humidity);

	Serial.print("Temperature: ");
	Serial.print(tempF);
	Serial.println(" C");

	Serial.print("Humidity: ");
	Serial.print(humF);
	Serial.println(" %");

        Serial.print("Temperature bytes: ");
        Serial.println(temperature, HEX);

        Serial.print("Humidity bytes: ");
        Serial.println(humidity, HEX);

	delay(500);
}
