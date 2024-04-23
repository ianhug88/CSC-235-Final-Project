
// defines pins numbers
const int trigPin = 5;
const int echoPin = 7;
// defines variables
long duration;
int distance;


int state = 0;

void setup() {
  pinMode(trigPin, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);   // Sets the echoPin as an Input
  Serial.begin(9600);        // Starts the serial communication
}

void loop() {

  if (distanceSensor() <= 10) {
    motorControl(3, map(distanceSensor(), 1, 10, 125, 70));
  } else {
    motorControl(3, 0);
  }

  // motor test
  //motorControl(3, 150);

  //distance sensor test
  //distanceSensor();

}

int distanceSensor() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;  // distance in cm

  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  return distance;
}

void motorControl(int motorPin, int speed) {
  // int speed = map(distanceSensor(), 1, 10, 65, 125);
  // //int speed = 100;
  analogWrite(motorPin, speed);
  Serial.print("Speed: ");
  Serial.println(speed);
}
