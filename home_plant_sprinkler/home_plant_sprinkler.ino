
// Automatic sprinkler for up to four water pumps operating independently under the control of the arduino and RTC module.
// The sprinkler is activated at a specific time, and the water flow is controlled by the time the water pump is on.


#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 rtc;

const int pine5 = 5;
const int pine7 = 7;
const int pine9 = 9;
//const int pineX = X;


//here you need to define the time to turn on the first water pump. For example, 3.15pm you need to set hours = 15
//minutes = 15, and seconds = 0

int hours = 15;
int minutes = 25;
int seconds = 0;
int delayPump = 10000;


void setup () {
    Serial.begin(9600);
    pinMode(5, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(9, OUTPUT);
 // pinMode(X, OUTPUT);
 

          //here is the configuration of the DS_RTC module
          #ifdef AVR
            Wire.begin();
          #else
            Wire1.begin(); 
          #endif
            rtc.begin();
        
            if (! rtc.isrunning()) {
                Serial.println("RTC is NOT running!");
              // following line sets the RTC to the date & time this sketch was compiled
              //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
                 
              // This line sets the RTC with an explicit date & time, for example to set
              // January 02, 2021 at 3pm you would call:
              // rtc.adjust(DateTime(2021, 1, 2, 13, 22, 50));
            }
  
}

void loop () {

        DateTime now = rtc.now();
        Serial.print(now.day(), DEC);
        Serial.print('-');
        Serial.print(now.month(), DEC);
        Serial.print('-');
        Serial.print(now.year(), DEC);
        Serial.print(' ');
        Serial.print(now.hour(), DEC);
        Serial.print(':');
        Serial.print(now.minute(), DEC);
        Serial.print(':');
        Serial.print(now.second(), DEC);
        Serial.println();

    
   
    //if the time/date is at the given point, pineX will be on (LOW), else it will be off (HIGH).
      digitalWrite(pine5, HIGH);
      digitalWrite(pine7, HIGH);
      digitalWrite(pine9, HIGH);  

    //in my project I let the pump on for 10 seconds (dalayPump). The water pumps are started sequentially at 1 minute intervals. 
    //You need to define the time interval for the activation of the water pumps in your project, according 
    //to your needs. 
            if(now.hour() == hours && now.minute() == minutes  && now.second() == seconds) 
          {
            digitalWrite(pine5, LOW);
            delay (delayPump);
          }



           if(now.hour() == hours && now.minute() == minutes+1  && now.second() == seconds) 
          {
            digitalWrite(pine7, LOW);
            delay (delayPump);
          }

      

           if(now.hour() == hours && now.minute() == minutes+2  && now.second() == seconds) 
          {
            digitalWrite(pine9, LOW);
            delay (delayPump);
          }

    
    }
   
   
   
   
   
