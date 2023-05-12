
#include <Servo.h>

using namespace std;

Servo armServo;
Servo wristServo;

double pos = 0;
bool goingLeft = true;

void setup() {
  armServo.attach(13);
  wristServo.attach(11);

  Serial.begin(9600);
}

void loop() {
  setArmPosition(pos);
}

/* Calculates and sets arm position, then sets wrist position */ 
void setArmPosition(double position) {
  /* Global to servo conversion, delete if 0 position is pointing north */
  double pos = position + 90;
  armServo.write(pos);

  setWristPosition(position);
}

/* Given the arm position, the wrist angle is calculated */ 
void setWristPosition(double armPosition) {
  double setPoint = 0;
  if (armPosition > 0) {
    setPoint = -(abs(armPosition) - 90);
  } else {
    setPoint = abs(armPosition) - 90;
  }
  double pos = setPoint + 90;

  wristServo.write(pos);
}
