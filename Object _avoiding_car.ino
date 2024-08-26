// For the two motor driver pins
 
 #define ENA 10
 #define IN1 9
 #define IN2 8
 #define ENB 11
 #define IN3 7
 #define IN4 6

 // For the 3 sensors
 
 #define frontTrigPin 13
 #define frontEchoPin 12
 #define leftTrigPin 3
 #define leftEchoPin 2
 #define rightTrigPin 4
 #define rightEchoPin 5
 

void setup() {

 // for the motor driver
  
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // For the sensors

  pinMode(frontTrigPin, OUTPUT);
  pinMode(frontEchoPin, INPUT);
  pinMode(leftTrigPin, OUTPUT);
  pinMode(leftEchoPin, INPUT);
  pinMode(rightTrigPin, OUTPUT);
  pinMode(rightEchoPin, INPUT);

  // for serial monitor
   Serial.begin(9600);

}

void loop() {
 
  // Distance calculation
  long frontDistance = measureDistance(frontTrigPin, frontEchoPin);
  long leftDistance = measureDistance(leftTrigPin, leftEchoPin);
  long rightDistance = measureDistance(rightTrigPin, rightEchoPin);

  // For serial monitor
  Serial.print("Front: ");
   Serial.print(frontDistance);
    Serial.print(" cm ");
  Serial.print("Left: "); 
   Serial.print(leftDistance);
    Serial.print(" cm ");
  Serial.print("Right: "); 
   Serial.println(rightDistance); 
    Serial.println(" cm");
  
  //Now condition

  if (frontDistance < 15) {
    stopCar();
    delay(1000);

    if (leftDistance > rightDistance) {
      turnLeft();
    }
     else {
      turnRight();
    }
    delay(1000);
  } 
  else {
    moveForward();
  }
}

// Function for moveForward
  void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


// Function for moveRight
  void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


// Function for moveLeft
  void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Function for stopCar
  void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// Function for measureDistance
  long measureDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;
  return distance;
}

