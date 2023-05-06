#include <Servo.h>
class mouvement{
  public:
    mouvement();
    Servo myServos[10];
    float pi=3.14159;
    int TotalNumberofServos=8;
    float Shift = 2*pi/TotalNumberofServos;
    float Wavelengths, rads;
    int  MaxAngleDisplacement;
    int r=0;
    int O, A, v, x;
    float L;
    bool condition= true;
    void slither(int offset, int Amplitude, int Speed, float wavelengths);
    void straightline();
    float teta(int offset, int Amplitude, int Speed, float Wavelengths, int j, float rads);
    float choose(int value);
  private:

};