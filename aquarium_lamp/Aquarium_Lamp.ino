
// Projeto arduino pisca led em hora específica.


int pino8 = 8;
int delayNight = 32400000;
int delayDay = 54000000;

void loopLamp() {
      for (;;){
      digitalWrite(pino8, LOW);
      delay (delayDay);
      digitalWrite(pino8, HIGH);
      delay (delayNight);
      } 
}

void setup () {
  pinMode(8, OUTPUT);
  Serial.begin(9600);
} 

void loop () {

    //After restarting the system, use the code below to turn the aquarium light back 
    //on and align it with the loopLamp (7am - 10pm). You need to adjust the delay 
    //according to the time you are turning on the aquarium light.
    //for example, if the time is 3pm, you need to replace the value of 54000000 with 28800000 
    //(number of ms up to 10pm).
    
    
      digitalWrite(pino8, LOW);
      delay (28799700);
      digitalWrite(pino8, HIGH);
      delay (delayNight);
    
    

     //Looping that controls the relay and keeps the lamp on between 7 am and 10 pm.
    loopLamp();

}
   
   
   
   
   
