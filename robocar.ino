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
};

//Порты МК к которым подключаются порты драйвера
MOTOR MOTOR2 = {13,12,11};
MOTOR MOTOR1 = {10,9,6};

int spd = 170; //Скорость вращения двигателя (делитель ШИМ) 1-255
int button = 7; //Пин подключения кнопки
boolean wait;
float border;
float white;
float black;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Инициализация "Датчика света"
  pinMode(A0, INPUT);
  //Инициализация кнопки
  pinMode(button, INPUT);
  digitalWrite(button, HIGH); // Подключаем подтягивающий резистор
  //Инициализация пинов управления двигателем
  pinMode(MOTOR1.in1, OUTPUT);
  pinMode(MOTOR1.in2, OUTPUT);
  pinMode(MOTOR2.in1, OUTPUT);
  pinMode(MOTOR2.in2, OUTPUT);
  pinMode(MOTOR2.enable, OUTPUT);
  // Ожидаем нажатие кнопки
  while(wait == false){ 
    //Serial.print( "button " );
    //Serial.println( digitalRead(button) );
    if (digitalRead(button) == LOW){
      wait = true;
    };
  }
  white = analogRead(A0); //Получаем значение уровня белого
  Serial.print( "white: " );
  Serial.println( white );
  black = white * 1.2 ; //Уровень черного на 20% больше уровня белого
  Serial.print( "black: " );
  Serial.println( black );
  //forward();
  //delay(1000);
  //Serial.println( "stop " );
  //stopDrive();

/* 
   //Test
   delay(5000);
  forward();
  delay(1000);
  stopDrive();
*/
/*  
  back(); 
  delay(5000);
  stopDrive();
  
  left();
  delay(5000);
  stopDrive();
  
  right();
  delay(5000);
  stopDrive();
*/
}

void loop() {
  // put your main code here, to run repeatedly:
  border = analogRead(A0);
  if (border >= black)
  {
    stopDrive();
  } else {
    forward();
  }
  Serial.println(border);
  //delay(200);
}

void stopDrive()
{
  analogWrite(MOTOR1.enable, 0);
  digitalWrite(MOTOR2.enable, LOW);
  
}

void forward()
{
  digitalWrite(MOTOR1.in1, HIGH);
  digitalWrite(MOTOR1.in2, LOW);
  analogWrite(MOTOR1.enable, spd);
}

void back()
{
  digitalWrite(MOTOR1.in1, LOW);
  digitalWrite(MOTOR1.in2, HIGH);
  analogWrite(MOTOR1.enable, 255);
}

void left()
{
  digitalWrite(MOTOR2.in1, HIGH);
  digitalWrite(MOTOR2.in2, LOW);
  digitalWrite(MOTOR2.enable, HIGH);
}

void right()
{
  digitalWrite(MOTOR2.in1, LOW);
  digitalWrite(MOTOR2.in2, HIGH);
  digitalWrite(MOTOR2.enable, HIGH);
}




