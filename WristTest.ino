
#include <Servo.h>

Servo armServo;

Servo wristServo;

using namespace std;

double pos = 0;
bool goingLeft = true;
void setup() {
  // put your setup code here, to run once:
  armServo.attach(13);
  wristServo.attach(11);

  Serial.begin(9600);
}



void loop() {
  if (pos >= 90) {
    goingLeft = false;
  } else if (pos <= -90) {
    goingLeft = true;
  }
  if (goingLeft) {
    pos += 0.1;
  } else {
    pos -= 0.1;
  }

  setArmPosition(pos);
}

void setArmPosition(double position) {
  double pos = position + 90;

  armServo.write(pos);
  setWristPosition(position);
}

void setWristPosition(double armPosition) {
  double setPoint = 0;
  if (armPosition > 0) {
    setPoint = -(abs(armPosition) - 90);
  } else {
    setPoint = abs(armPosition) - 90;
  }
  double pos = setPoint + 90;
Serial.println(pos);
  wristServo.write(pos);
}