/*
CPR feedback Test sketch
-Using LCD to display results in real time
 */

#include <LiquidCrystal.h>

int pressurePin = 0; 
int pressureRead; 
const int buttonPin = 8;  
unsigned long time;
const int pressGood = 10;
const int pressBad =  9;

int BPM; 
float bpmCount; 
float cprCount = 0;  
int buttonState = 0;         
int lastButtonState = 0;     
int cprTotal = 0; 
int cprCycle = 0; 

int  timeSec, timeCPR, BPM_1; 
float totalTime;
unsigned long timeBegin, timeEnd;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //LCD pins

void setup() {
 
  pinMode(buttonPin, INPUT); 
  pinMode(pressGood, OUTPUT); 
  pinMode(pressBad, OUTPUT);
  Serial.begin(9600); 
  Serial.println("Begin CPR");
  lcd.begin(16, 2);
  lcd.home();
  lcd.print("Begin CPR");
}

void loop() {
pressureRead = analogRead(pressurePin);
  time = millis(); 
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) {
       
    if (buttonState == HIGH) { 
      lcd.clear();
      lcd.home();
     
      Serial.println(cprCount);
       
      Serial.println(pressureRead);
      lcd.setCursor(0,0);
      lcd.print("Count: ");
      lcd.setCursor(7,0);
      lcd.print(cprCount);
      lcd.setCursor(10,0);
      lcd.print("R: ");     
      cprCount++; 
      
      if(cprCount == 1){
         timeBegin = millis(); 
      }
      
      }
    
     
    }
    //pressureRead = analogRead(pressurePin);
    if (pressureRead < 233){
        digitalWrite(pressGood, HIGH);
        digitalWrite(pressBad, LOW);
    }
    else if (pressureRead > 234){
        digitalWrite(pressBad, HIGH);
        digitalWrite(pressGood, LOW);
    }



     if (cprCount == 30){ 
            cprCount = 0; 
            timeEnd = millis(); 
            
            totalTime = (timeEnd - timeBegin) / 1000; 
            Serial.print("Total Time: ");
            Serial.println(totalTime);
            bpmCount = ( 30.0 / totalTime); 
            Serial.print("BPM Count: ");
            Serial.println(bpmCount);
            BPM = (bpmCount * 60.0);
            Serial.print("Total time in sec: ");
            Serial.println(totalTime);
            lcd.home();
            lcd.print("Rate (BPM): ");
            lcd.setCursor(12,0);
            lcd.print(BPM);
            Serial.print("BPM is: ");
            Serial.println(BPM);
            lcd.setCursor(0,1);
            lcd.print("Total Time: ");
            lcd.setCursor(12,1);
            lcd.print(totalTime);
            cprCycle++;
            Serial.print("CPR Cycle #: ");
            Serial.println(cprCycle);
            if (cprCycle == 5){
                cprCycle = 0;
            }
            
     }
     
     if (cprCount > 5 && cprCount <= 30) {
         float rateTime = (millis() - timeBegin) / 1000;
         //Serial.println(rateTime);
         int rate = (cprCount / rateTime) * 60; 
         //Serial.print("BPM is: ");
         //Serial.println(rate);
         
         if (rate >= 100 && rate <= 120 ){ 
             lcd.setCursor(12,0);
             lcd.print("Good");
         }
         else {
             lcd.setCursor(0,1);
             lcd.print("----");
         }
     }

     
    // Delay
    delay(25); 
  lastButtonState = buttonState;
}