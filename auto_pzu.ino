#include <EEPROM.h>
// выходы arduino для датчика линии
#define IR1 A7  // A7
#define IR2 A12 // A12
#define IR3 A13 // A13
#define IR4 A15 // A15
#define IR5 A14 // A14
//#define KN 29

//Максимальный коэфициент для датчиков
int IR1NOW = 0;
int IR2NOW = 0;
int IR3NOW = 0;
int IR4NOW = 0;
int IR5NOW = 0; 

//Минимальные коэфициент для датчиков (берется с максимального значения аналогового сигнала)
int IR1NOWMIN = 1024;
int IR2NOWMIN = 1024;
int IR3NOWMIN = 1024;
int IR4NOWMIN = 1024;
int IR5NOWMIN = 1024;

//Средний коэфициент  для датчиков
int KIR1;
int KIR2;
int KIR3;
int KIR4;
int KIR5;

unsigned long Time, PreviousTime;
long Period = 15000; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IR1, INPUT);   
  pinMode(IR2, INPUT);  
  pinMode(IR3, INPUT);   
  pinMode(IR4, INPUT);   
  pinMode(IR5, INPUT);
//  pinMode(KN, INPUT); 
  PreviousTime = millis();
}

void loop() {

// подбор максимальных значений

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

//подбор минимальных значений

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
      Serial.print("Коеф для 1 :");
     Serial.println(IR1NOW);
     Serial.print("Коеф для 2 :");
     Serial.println(IR2NOW);
     Serial.print("Коеф для 3 :");
     Serial.println(IR3NOW);
     Serial.print("Коеф для 4 :");
     Serial.println(IR4NOW);
     Serial.print("Коеф для 5 :");
     Serial.println(IR5NOW);
//  if(Time - PreviousTime > Period)
//  {
//     KIR1 = (IR1NOW + IR1NOWMIN)/2;
//     KIR2 = (IR2NOW + IR2NOWMIN)/2;
//     KIR3 = (IR3NOW + IR3NOWMIN)/2;
//     KIR4 = (IR4NOW + IR4NOWMIN)/2;
//     KIR5 = (IR5NOW + IR5NOWMIN)/2;
//     
//     Serial.print("Коеф для 1 :");
//     Serial.println(IR1NOW);
//     Serial.print("Коеф для 2 :");
//     Serial.println(IR2NOW);
//     Serial.print("Коеф для 3 :");
//     Serial.println(IR3NOW);
//     Serial.print("Коеф для 4 :");
//     Serial.println(IR4NOW);
//     Serial.print("Коеф для 5 :");
//     Serial.println(IR5NOW);

//      Запись средних коэфициентов в ПЗУ
//     EEPROM.update(10, KIR1);
//     EEPROM.update(12, KIR2);
//     EEPROM.update(14, KIR3);
//     EEPROM.update(16, KIR4);
//     EEPROM.update(18, KIR5); 

//     Serial.end();

//     Serial.println(EEPROM.read(10));
//     Serial.println(EEPROM.read(12));
//     Serial.println(EEPROM.read(14));
//     Serial.println(EEPROM.read(16));
//     Serial.println(EEPROM.read(18));    
  }
//    analogRead(IR1);
//    analogRead(IR2);
//    analogRead(IR3);
//    analogRead(IR4);
//    analogRead(IR5);
//int    QT1 = analogRead(IR1);
//int    QT2 = analogRead(IR2);
//int    QT3 = analogRead(IR3);
//int    QT4 = analogRead(IR4);
//int    QT5 = analogRead(IR5);
//
//
//     Serial.print("Коеф для 1 :"); // четвертый A7
//     Serial.println(QT1);
//     Serial.print("Коеф для 2 :"); // пятый
//     Serial.println(QT2);
//     Serial.print("Коеф для 3 :"); // второй
//     Serial.println(QT3);
//     Serial.print("Коеф для 4 :"); // первый 
//     Serial.println(QT4);
//     Serial.print("Коеф для 5 :"); //третий 
//     Serial.println(QT5);
//}
