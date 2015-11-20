/*
 * Управление двигателями через драйвер L293
 *
 *
*/


struct MOTOR
{
  int in1;
  int in2;
  int enable;
}

//Порты МК к которым подключаются порты драйвера
MOTOR MOTOR1 = {13,12,11};
MOTOR MOTOR2 = {7,8,9};

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}


void forward()
{
  digitalWrite(MOTOR1.in1, HIGH);
  digitalWrite(MOTOR1.in2, LOW);
  analogWrite(MOTOR1.enable, 254);
}

void back()
{
  digitalWrite(MOTOR1.in1, LOW);
  digitalWrite(MOTOR1.in2, HIGH);
  analogWrite(MOTOR1.enable, 254);
}

void left()
{
  digitalWrite(MOTOR2.in1, HIGH);
  digitalWrite(MOTOR2.in2, LOW);
  analogWrite(MOTOR2.enable, 254);
}

void right()
{
  digitalWrite(MOTOR2.in1, LOW);
  digitalWrite(MOTOR2.in2, HIGH);
  analogWrite(MOTOR2.enable, 254);
}



}
