/*
 Line Follower Robot using Arduino
 5 IR Sensors + Dual DC Motors
 Author: Mohammad Zakariya
*/

#define m1 4
#define m2 5
#define m3 2
#define m4 3
#define e1 9
#define e2 10

#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3
#define ir5 A4
#define nearpin A5
#define sw 8

void setup() {
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(e1, OUTPUT);
  pinMode(e2, OUTPUT);

  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);

  pinMode(nearpin, INPUT);
  pinMode(sw, INPUT);
}

void loop() {
  int s1 = digitalRead(ir1);
  int s2 = digitalRead(ir2);
  int s3 = digitalRead(ir3);
  int s4 = digitalRead(ir4);
  int s5 = digitalRead(ir5);

  if (digitalRead(nearpin) == HIGH) {
    stopMotors();
    return;
  }

  if (s3 == LOW) {
    forward();
  }
  else if (s2 == LOW || s1 == LOW) {
    turnRight();
  }
  else if (s4 == LOW || s5 == LOW) {
    turnLeft();
  }
  else {
    stopMotors();
  }
}

void forward() {
  analogWrite(e1, 255);
  analogWrite(e2, 255);
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}

void turnRight() {
  analogWrite(e1, 255);
  analogWrite(e2, 255);
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
}

void turnLeft() {
  analogWrite(e1, 255);
  analogWrite(e2, 255);
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}

void stopMotors() {
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
}
