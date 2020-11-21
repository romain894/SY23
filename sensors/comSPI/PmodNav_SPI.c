//Romain THOMAS

#include <Arduino.h>
#include <SPI.h>
#include <stdint.h>

#define cs_alt 9 //definir le chip select

uint8_t statT, statP;
uint16_t TempLSB, TempMSB; //meme taille que la variable finale pour les decalage
uint32_t PLSB, Pinter, PMSB;
uint16_t Rtemp1, Rtemp2, RP1, RP2, RP3, Status;
int16_t temp;
int32_t pression;
float Temperature, Pression;


void setup() {
  Rtemp1 = 0x2B | 0x80; //Mode lecture registre temp 1
  Rtemp2 = 0x2C | 0x80; //Mode lecture registre temp 2
  RP1 = 0x28 | 0x80;    //Mode lecture registre pression 1
  RP2 = 0x29 | 0x80;    //Mode lecture registre pression 2
  RP3 = 0x2A | 0x80;    //Mode lecture registre pression 3
  Status = 0x27 | 0x80; //Mode lecture ragistre de status


  Serial.begin(9600);
  pinMode(cs_alt,OUTPUT);
  SPI.begin();
  SPI.setDataMode(SPI_MODE0);
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  SPI.setBitOrder(MSBFIRST);

  digitalWrite(cs_alt,LOW);
  SPI.transfer(0x10); //registre de control 1
  SPI.transfer(0x0A);
  digitalWrite(cs_alt,HIGH);

  digitalWrite(cs_alt,LOW);
  SPI.transfer(0x20); //registre de control 2
  SPI.transfer(0x80);
  digitalWrite(cs_alt,HIGH);
  delay(100);

}

void loop() {
  digitalWrite(cs_alt,LOW);
  SPI.transfer(0x21); //registre de controle 3
  SPI.transfer(1);    //demande de mesure
  digitalWrite(cs_alt,HIGH);

  statT=0; //verifie sur la temperature est disponible
  while(statT!=1){
    digitalWrite(cs_alt,LOW);
    SPI.transfer(Status);
    statT=SPI.transfer(0);
    digitalWrite(cs_alt,HIGH);
    statT=statT & 0x01;
    }

  digitalWrite(cs_alt,LOW);
  SPI.transfer(Rtemp1); //recuperation donnees temperature
  TempLSB=SPI.transfer(0)& 0x00FF; //masquage pour etre sur que les autres bits sont a 0
  digitalWrite(cs_alt,HIGH);

  digitalWrite(cs_alt,LOW);
  SPI.transfer(Rtemp2);
  TempMSB=SPI.transfer(0)& 0x00FF;
  digitalWrite(cs_alt,HIGH);

  statP=0; //verifie sur la pression est disponible
  while(statP!=2){
     digitalWrite(cs_alt,LOW);
    SPI.transfer(Status);
    statP=SPI.transfer(0);
    statP=statP & 0x02;
    digitalWrite(cs_alt,HIGH);
    }
     digitalWrite(cs_alt,LOW);
  SPI.transfer(RP1); //recuperation donnees pression
  PLSB=SPI.transfer(0) & 0x000000FF;
  digitalWrite(cs_alt,HIGH);

     digitalWrite(cs_alt,LOW);
  SPI.transfer(RP2);
  Pinter=SPI.transfer(0)& 0x000000FF;
  digitalWrite(cs_alt,HIGH);

     digitalWrite(cs_alt,LOW);
  SPI.transfer(RP3);
  PMSB=SPI.transfer(0)& 0x000000FF;
  digitalWrite(cs_alt,HIGH);


  temp = TempMSB<<8 | TempLSB; //regroupement sur 16 bits
  pression = PMSB<<16 | Pinter<<8 | PLSB; //regroupement sur 32 bits

  Pression = ((float)pression)/4096.0; //calcul de la pression
  Temperature = ((float)temp/480.0)+42.5; //calcul de la temperature
  Serial.print("Température = ");
  Serial.println(Temperature);
  Serial.print("Pression = ");
  Serial.println(Pression);
  delay(5000);
}
