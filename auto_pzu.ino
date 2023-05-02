#include <EEPROM.h>

// announcement of pins to which sensors are connected
#define IR1 A7  // A7
#define IR2 A12 // A12
#define IR3 A13 // A13
#define IR4 A15 // A15
#define IR5 A14 // A14

//the maximum coefficient for the sensor (taken from the bit depth of the analog signal)
int IR1NOW = 0;
int IR2NOW = 0;
int IR3NOW = 0;
int IR4NOW = 0;
int IR5NOW = 0; 

//the minimum coefficient for the sensor (taken from the bit depth of the analog signal)
int IR1NOWMIN = 1024;
int IR2NOWMIN = 1024;
int IR3NOWMIN = 1024;
int IR4NOWMIN = 1024;
int IR5NOWMIN = 1024;

//variables for the average value
int KIR1;
int KIR2;
int KIR3;
int KIR4;
int KIR5;

unsigned long Time, PreviousTime;
long Period = 15000; 

void setup() {
  
  Serial.begin(9600);
  pinMode(IR1, INPUT);   
  pinMode(IR2, INPUT);  
  pinMode(IR3, INPUT);   
  pinMode(IR4, INPUT);   
  pinMode(IR5, INPUT); 
  PreviousTime = millis();
}

void loop() {

// selection of maximum values

  if (analogRead(IR1) > IR1NOW) 
  {
    IR1NOW = analogRead(IR1);   
  }
  if (analogRead(IR2) > IR1NOW) 
  {
    IR2NOW = analogRead(IR2);   
  }
  if (analogRead(IR3) > IR3NOW) 
  {
    IR3NOW = analogRead(IR3);   
  }
  if (analogRead(IR4) > IR4NOW) 
  {
    IR4NOW = analogRead(IR4);   
  }
  if (analogRead(IR5) > IR5NOW) 
  {
    IR5NOW = analogRead(IR5);   
  }

//selection of minimum values

  if (analogRead(IR1) < IR1NOWMIN) 
  {
    IR1NOWMIN = analogRead(IR1);   
  }
  if (analogRead(IR2) < IR1NOWMIN) 
  {
    IR2NOWMIN = analogRead(IR2);   
  }
  if (analogRead(IR3) < IR3NOWMIN) 
  {
    IR3NOWMIN = analogRead(IR3);   
  }
  if (analogRead(IR4) < IR4NOWMIN) 
  {
    IR4NOWMIN = analogRead(IR4);   
  }
  if (analogRead(IR5) < IR5NOWMIN) 
  {
    IR5NOWMIN = analogRead(IR5);   
  }
  
  Time = millis();

  if(Time - PreviousTime > Period)
  {
     KIR1 = (IR1NOW + IR1NOWMIN)/2;
     KIR2 = (IR2NOW + IR2NOWMIN)/2;
     KIR3 = (IR3NOW + IR3NOWMIN)/2;
     KIR4 = (IR4NOW + IR4NOWMIN)/2;
     KIR5 = (IR5NOW + IR5NOWMIN)/2;
        
     Serial.print("Коеф для 1 :");
     Serial.println(KIR1);
     Serial.print("Коеф для 2 :");
     Serial.println(KIR2);
     Serial.print("Коеф для 3 :");
     Serial.println(KIR3);
     Serial.print("Коеф для 4 :");
     Serial.println(KIR4);
     Serial.print("Коеф для 5 :");
     Serial.println(KIR5);

//Recording average coefficients in PROM
     EEPROM.update(10, KIR1);
     EEPROM.update(12, KIR2);
     EEPROM.update(14, KIR3);
     EEPROM.update(16, KIR4);
     EEPROM.update(18, KIR5);

     Serial.end();
  }
    
}
  
