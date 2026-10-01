#include <Servo.h>

const int trigPin = 10;
const int echoPin = 11;
Servo myServo; 

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myServo.attach(9); // Servo signal connected to Pin 9
}

void loop() {
  // Sweep from 15 degrees to 165 degrees
  for(int angle = 15; angle <= 165; angle += 15) {
    myServo.write(angle);
    delay(100); // Wait for servo to reach position
    
    int distance = calculateDistance(); // Call function to get distance
    
    // Print data to Serial Monitor formatted for debugging/plotting
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print(" degrees | Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  // Sweep back from 165 degrees down to 15 degrees
  for(int angle = 165; angle >= 15; angle -= 15) {
    myServo.write(angle);
    delay(100);
    
    int distance = calculateDistance();
    
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print(" degrees | Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
}

// Custom function to handle distance math cleanly
int calculateDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}