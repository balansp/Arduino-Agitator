 
#include <Servo.h>

#define SERVO_PIN 4
#define POT_PIN A1

#define POS_MIN 10
#define POS_MAX 110

#define POT_MIN 10
#define POT_MAX 1023

#define SLOW_MIN 5
#define SLOW_MAX 25
 

Servo servo;   
 
int pos,potVal,slow;

void setup() {
  servo.attach(SERVO_PIN);   
  Serial.begin(115200);
}

void loop() {
   potVal=analogRead(POT_PIN);
  
  if(potVal>10){
      for (pos = POS_MIN; pos <= POS_MAX; pos += 1) {  
         servoMove(pos);
      }
      
      for (pos = POS_MAX; pos >= POS_MIN; pos -= 1) {  
         servoMove(pos);
      }
  }
}

void servoMove(int pos){
  
  potVal=analogRead(POT_PIN);
  Serial.print("PotVal:");
  Serial.print(potVal);
  Serial.print(", Pos:");
  Serial.print(pos);
  
  slow = map(potVal, POT_MIN, POT_MAX, SLOW_MIN, SLOW_MAX); 
  
  Serial.print(", Slow:");
  Serial.println(slow);
  servo.write(pos); 
  delay(slow); 

}
