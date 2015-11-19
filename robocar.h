/*
/*
 *robocar.h
 *
 *robocar - библиотека для проекта машинки робота
 *
*/


#ifndef robocar_h
#define robocar_h

#define _RCDEBUG_ 1

struct MOTOR //Структура для хранения pin-ов контроллера
{
  int in1;
  int in2;
  int enable;
}

class robocar
{
  public:
    robocar();
    robocar(MOTOR *m1, MOTOR *m2);
    void motor_forward(int m, int speed=254);
    void motor_back(int m, int speed=254);
  
  private:
    void set_m_pins(MOTOR *m);
    void m_forward(MOTOR *m, int speed-254);
    void m_back(MOTOR *m, int speed-254);
    MOTOR MOTOR1;
    MOTOR MOTOR2;
}

#endif //ifndef robocar_h
