#include <Servo.h>
class mouvement{
  public:
    mouvement();
    Servo myServos[10];
    float pi=3.14159;
    int TotalNumberofServos=10;
    float Shift = 2*pi/TotalNumberofServos;
    float Wavelengths, rads;
    int  MaxAngleDisplacement;
    void slither(int offset, int Amplitude, int Speed, float wavelengths);
    void straightline();
  private:

};