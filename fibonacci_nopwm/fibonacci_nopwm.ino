//L293D
//Motor A
const int motorLpin1  = 3;  
const int motorLpin2  = 5; 
 
//Motor B
const int motorRpin1  = 11; 
const int motorRpin2  = 10;

int cmd;


void setup(){
    Serial.begin(9600);
    //Set pins as outputs
    
    pinMode(motorRpin1, OUTPUT);
    pinMode(motorRpin2, OUTPUT);
    pinMode(motorLpin1, OUTPUT);
    pinMode(motorLpin2, OUTPUT);
     
}

void rotateLeft(int duration){
    //robot left rotation
    //duration in ms
   
    digitalWrite(motorRpin1, HIGH);
    digitalWrite(motorRpin2, LOW);
    digitalWrite(motorLpin1, LOW);
    digitalWrite(motorLpin2, HIGH);  

    delay(duration);
}

void rotateRight(int duration){
    //robot right rotation
    //duration in ms

    digitalWrite(motorRpin1, LOW);
    digitalWrite(motorRpin2, HIGH);
    digitalWrite(motorLpin1, HIGH);
    digitalWrite(motorLpin2, LOW);

    delay(duration);
}

void forwardMotors(int duration){
    // robot moves forward
    //duration in ms
    
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
int distanceList[6];
int counter = 0;
void loop(){
  f3 = f2+f1;
  f1 = f2;
  f2 = f3;
  Serial.println(f1);
  distance = 200*f1;
  distanceList[counter] = distance;
  counter = counter + 1;
  //forwardMotors(distance);
  rotateLeft(500);
  stopMotors();
  delay(1000);
  if (f2 > 13) {
    Serial.println("FINISHED");
    for (int i = 5; i >= 0; i = i - 1) {
      Serial.println(distanceList[i]);
      delay(10); 
    }
    exit(0);
  }
}
  
