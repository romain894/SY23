/*
 * wifi_ESP32.c
 *
 * Copyright 2020 Viet Phuong DINH <viet_phuong@doussot>
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
#include <WiFi.h>
#include <Wire.h>
#include <HTTPClient.h>
#define SSID  "d206-IOT-AP"
#define PASSPHRASE "d2062019uttSY23"

#define RegTe 0x00
#define RegTh 0x01
#define RegConf 0x02
#define PmodHygroID 0x40

const int LED=LED0;
HTTPClient http;
uint16_t temperature, humidity = 0;


void AfficheParametres() {
  byte adrMAC[6];
  IPAddress ip,gw,masque;
  WiFi.macAddress(adrMAC);
  // tableau des valeurs de l'adress MAC
  for(int i=0;i<6;i+=1) {
    Serial.print(adrMAC[i],HEX);
    Serial.print(":");
  }
  Serial.println();
  Serial.print("ip : ");
  ip = WiFi.localIP();
  Serial.println(ip);
  Serial.print("passerelle : ");
  gw = WiFi.gatewayIP();
  Serial.println(gw);
  Serial.print("masque : ");
  masque = WiFi.subnetMask();
  Serial.println(masque);
}

void ConnexionWifi(char *ssid, const char *passphrase) {
  int etatled=0;
  Serial.print("connexion ");
  Serial.println(ssid);
  // initialise connexion
  WiFi.begin(ssid, passphrase);
  // attente connexion
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
    etatled ^= 1; //etatled XOR 1
    digitalWrite(LED,etatled);
  }
  Serial.println("connexion OK");
  digitalWrite(LED,HIGH);
}

void ConnexionHTTPGET(const char* url) {
  Serial.print("connexion URL: ");
  Serial.println(url);
  http.begin(url);
  int httpCode = http.GET();
  Serial.print("httpCode = ");
  Serial.println(httpCode);
    if (httpCode) {
      if (httpCode == 200) {
        String reponse = http.getString();
        Serial.println(reponse);
      }
      else {
        Serial.print("erreur http ");
        Serial.println(httpCode);
      }
    }

  Serial.println("closing connection");
  http.end();
}

void ConnexionHTTPPOST(const char* url, String datas) {
  Serial.print("connexion URL: ");
  Serial.println(url);
  http.begin(url);
  int httpCode = http.POST(datas);
  Serial.print("httpCode = ");
  Serial.println(httpCode);
    if (httpCode) {
      if (httpCode == 200) {
        String reponse = http.getString();
        Serial.println(reponse);
      }
      else {
        Serial.print("erreur http ");
        Serial.println(httpCode);
      }
    }
  Serial.println("closing connection");
  http.end();
}

float getTemp(uint16_t temperature){
	float celsius;
	celsius = ((float)temperature/0x10000) * 165.0 - 40.0;
	return celsius;
}

float getHumidity(uint16_t humidity){
	float percent;
	percent = ((float) humidity/0x10000) * 100.0;
	return percent;
}

//Request data from the PmodHygro sensor. data can either be temperature or humidity.
uint16_t getData(uint8_t reg){
	Wire.beginTransmission(PmodHygroID);
	Wire.write(reg);
	Wire.endTransmission();
	uint16_t data = 0;
	Wire.requestFrom(PmodHygroID, 2);
	if (Wire.available()){
		data <<= 8;
		data = (uint16_t) Wire.read();  //Read received bytes, cast it into a uint16_t and stock in data
		data <<= 8; //Shift 8 bits to the left, most significant byte first.
		data |= (uint16_t) Wire.read(); //Cast the read byte into uint16_t and add it to the 8-shifted uint16_t already in data
	}
	return data;
}

//Creates the GET request by concatenating the returns from the i2c function calls with the parameter strings.
String composeRequest(){
  // String surl ="http://10.23.12.199/capteurs/temphygro.php?id=43141";  //Given CGI script
  String surl = "http://10.23.12.187/cgi-bin/uvs/parsing.cgi?id=43141"; //Custom CGI script at individual VM
  String paramTemp = "&temperature=";
  String paramHum = "&hygrometrie=";

  float temp =  getTemp(getData(RegTe));   //Conversion to int hurts the precision....
  float hum =  getHumidity(getData(RegTh));

  surl += paramTemp;
  surl += temp;
  surl += paramHum;
  surl += hum;

  return surl;
}

void setup() {
  Serial.begin(9600);
  Wire.begin();

  //Separate temperature and humidity readings. 0x0000 for separate readings and 0x1000 for grouped
  Wire.beginTransmission(PmodHygroID);
  Wire.write(RegConf);
  Wire.write(0x00);
  Wire.write(0x00);
  Wire.endTransmission();

  delay(1000);
  ConnexionWifi((char*)SSID,PASSPHRASE);
  AfficheParametres();
  delay(1000);
}

void loop() {
  String surl = composeRequest();
  const char* url = surl.c_str(); //String to const char* conversion
  ConnexionHTTPGET(url);
  delay(2000);
}
