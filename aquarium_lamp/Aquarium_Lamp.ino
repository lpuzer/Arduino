
// Arduino project to switch on/off an aquarium lamp. 
//The system is under control of a relay connected to the arduino pine 8.


int pino8 = 8;
int delayOff = 32400000;
int delayOn = 54000000;

void loopLamp() {
      for (;;){
      digitalWrite(pino8, LOW);
      delay (delayOn);
      digitalWrite(pino8, HIGH);
      delay (delayOff);
      } 
}

void setup () {
  pinMode(8, OUTPUT);
  Serial.begin(9600);
} 

void loop () {

    //After restarting the system, use the code below to turn the aquarium lamp back 
    //on and align it with the loopLamp (7am - 10pm). You need to adjust the delay 
    //according to the time you are turning on the aquarium lamp.
    //For example, if the time is 2pm, you need to replace the value of 54000000 with 28800000 
    //(ms up to 10pm).
    
    
      digitalWrite(pino8, LOW);
      delay (54000000);
      digitalWrite(pino8, HIGH);
      delay (delayOff);
    
    

     //Looping that controls the relay and keeps the lamp on between 7am and 10pm.
    loopLamp();

}
   
   
   
   
   
