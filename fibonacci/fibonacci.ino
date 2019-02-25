//L293D
//Motor A
const int motorLpin1  = 3;  
const int motorLpin2  = 5; 
const int speedmotorL  = 6;  
//Motor B
const int motorRpin1  = 11; 
const int motorRpin2  = 10;
const int speedmotorR  = 9;  

int cmd;


void setup(){
    Serial.begin(9600);
    //Set pins as outputs
    pinMode(motorRpin1, OUTPUT);
    pinMode(motorRpin2, OUTPUT);
    pinMode(motorLpin1, OUTPUT);
    pinMode(motorLpin2, OUTPUT);
    pinMode(speedmotorR, OUTPUT);
    pinMode(speedmotorL, OUTPUT);
     
}

void rotateLeft(int duration){
    //robot left rotation
    //duration in ms
    analogWrite(speedmotorR,180);
    analogWrite(speedmotorL,180);
   
    digitalWrite(motorRpin1, HIGH);
    digitalWrite(motorRpin2, LOW);
    digitalWrite(motorLpin1, LOW);
    digitalWrite(motorLpin2, HIGH);  

    delay(duration);
}

void rotateRight(int duration){
    //robot right rotation
    //duration in ms
    analogWrite(speedmotorR,180);
    analogWrite(speedmotorL,180);

   digitalWrite(motorRpin1, LOW);
    digitalWrite(motorRpin2, HIGH);
    digitalWrite(motorLpin1, HIGH);
    digitalWrite(motorLpin2, LOW);

    delay(duration);
}

void forwardMotors(int duration, int speedL=255, int speedR=255){
    // robot moves forward
    //duration in ms
    analogWrite(speedmotorR,speedL);
    analogWrite(speedmotorL,speedR);
    digitalWrite(motorRpin1, HIGH);
    digitalWrite(motorRpin2, LOW);
    digitalWrite(motorLpin1, HIGH);
    digitalWrite(motorLpin2, LOW);
    delay(duration);
}

void stopMotors(){
    // robot stops
    
    digitalWrite(motorRpin1, LOW);
    digitalWrite(motorRpin2, LOW);
    digitalWrite(motorLpin1, LOW);
    digitalWrite(motorLpin2, LOW);
}

int f1=1;
int f2=1;
int f3;
int distance; 

void loop(){
  f3 = f2+f1;
  f1 = f2;
  f2 = f3;
  Serial.println(f1);
  distance = 200*f1;
  forwardMotors(distance);
  rotateLeft(1300);
  stopMotors();
  if (f2 > 21) {
    exit(0);
  }
  delay(1000);
}
  /* int semicirc = 5000;
  forwardMotors(180,240,semicirc);
  stopMotors();
  delay(1000);
  rotate(0,1300);
  stopMotors();
  int diameter = 3000;
  forwardMotors(240,240,diameter);
  stopMotors();
  //Serial.println("PI=");
  Serial.println(2*(float)semicirc/(float)diameter,5);

  
  exit(0);
  */
