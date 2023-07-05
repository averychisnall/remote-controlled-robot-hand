#include <Servo.h>

Servo myServo;

// define ADC pins
#define adcPin1 A0
#define adcPin2 A1
#define adcPin3 A2
#define adcPin4 A3

const float VCC = 4.98;       // Measured voltage of Ardunio 5V line
const float R_DIV = 50000.0;  // Resistance for voltage divider

const float STRAIGHT_RESISTANCE = 25000.0;  // resistance when straight
const float BEND_RESISTANCE = 50000.0;      // resistance at 90 deg

void setup() {
  // initialize ADC pins
  pinMode(adcPin1, INPUT);
  pinMode(adcPin2, INPUT);
  pinMode(adcPin3, INPUT);
  pinMode(adcPin4, INPUT);

  // initialize serial communication
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  // Read the ADC, and calculate voltage and resistance from it
  int flexADC1 = analogRead(adcPin1);
  float flexV = flexADC1 * VCC / 1023.0;
  float flexR = R_DIV * (VCC / flexV - 1.0);

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
  float angle1 = map(flexR, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                    90, 0);

  // print ADC value to slave arduino
  Serial.println("Sensor 1:");
  Serial.println(angle1);
  Serial1.println(angle1);  


  // Read the ADC, and calculate voltage and resistance from it
  int flexADC2 = analogRead(adcPin2);
  flexV = flexADC2 * VCC / 1023.0;
  flexR = R_DIV * (VCC / flexV - 1.0);

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
  float angle2 = map(flexR, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                    0, 90);

  // print ADC value to slave arduino
  Serial.println("Sensor 2:");
  Serial.println(angle2);
  Serial1.println(angle2);

  // Read the ADC, and calculate voltage and resistance from it
  int flexADC3 = analogRead(adcPin3);
  flexV = flexADC3 * VCC / 1023.0;
  flexR = R_DIV * (VCC / flexV - 1.0);

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
  float angle3 = map(flexR, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                    90, 0);

  // print ADC value to slave arduino
  Serial.println("Sensor 3:");
  Serial.println(angle3);
  Serial1.println(angle3);

  // Read the ADC, and calculate voltage and resistance from it
  int flexADC4 = analogRead(adcPin4);
  flexV = flexADC4 * VCC / 1023.0;
  flexR = R_DIV * (VCC / flexV - 1.0);

  // Use the calculated resistance to estimate the sensor's
  // bend angle:
  float angle4 = map(flexR, STRAIGHT_RESISTANCE, BEND_RESISTANCE,
                    0, 90);

  // print ADC value to slave arduino
  Serial.println("Sensor 4:");
  Serial.println(angle4);
  Serial1.println(angle4);


  // delay for a short period of time
  delay(100);
}