#include <Servo.h>
#include <string.h>

// define servo pins
const int SERVO_PIN1 = 10;
const int SERVO_PIN2 = 11;
const int SERVO_PIN3 = 12;
const int SERVO_PIN4 = 13;

// initialize Servo objects
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;


void setup() {
  // initialize servo pins
  myservo1.write(0);
  myservo1.attach(SERVO_PIN1);

  myservo2.write(0);
  myservo2.attach(SERVO_PIN2);

  myservo3.write(0);
  myservo3.attach(SERVO_PIN3);

  myservo4.write(0);
  myservo4.attach(SERVO_PIN4);

  // initialize serial communication
  Serial1.begin(9600);
  Serial.begin(9600);
}

void loop() {
  //Checks to see if there is data in the serial bus
  if (Serial1.available() > 0) {
    //Takes the data from the serial bus and places it into a variable
    float angle1 = Serial1.parseFloat();

    //Writing the positional data to the servo
    Serial.println(angle1);
    myservo1.write(angle1);

    //Takes the data from the serial bus and places it into a variable
    float angle2 = Serial1.parseFloat();

    //Writing the positional data to the servo
    Serial.println("Angle 2");
    Serial.println(angle2);
    myservo2.write(angle2);
    
    //Takes the data from the serial bus and places it into a variable
    float angle3 = Serial1.parseFloat();

    //Writing the positional data to the servo
    Serial.println(angle3);
    myservo3.write(angle3);
    
    //Takes the data from the serial bus and places it into a variable
    float angle4 = Serial1.parseFloat();

    //Writing the positional data to the servo
    Serial.println(angle4);
    myservo4.write(angle4);
  }
}
