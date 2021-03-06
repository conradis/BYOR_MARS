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

/*
 * DICHIARATE QUA SOTTO LE VARIABILI NECESSARIE
 */


 
void loop(){
  /*
   * QUESTO E' IL LOOP PRINCIPALE DEL ROVER: GIRA INFINTE VOLTE FINTANTO CHE 
   * NON CHIAMATE exit(0)
   */
  //INSERITE IL VOSTRO CODICE TRA QUI....




  //....E QUI!
  delay(20)
}
  
