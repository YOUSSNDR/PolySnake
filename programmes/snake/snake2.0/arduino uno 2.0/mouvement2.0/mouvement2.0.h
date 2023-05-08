#include <Servo.h>
class mouvement{
  public:
    mouvement();
    Servo myServos[10]; // define the servos
    float pi=3.14159; // approx of pi
    int TotalNumberofServos=8; //number of servo we use
    float Shift = 2*pi/TotalNumberofServos; // shift betwin the servos
    float Wavelengths, rads; 
    int  MaxAngleDisplacement;
    int r=0;
    int O, A, v, x;//Offset, Amplitude, Speed, the int value to take the decisoions
    float L;// wavelength
    bool condition= true; //while true the slither function will keep working
    void slither(int offset, int Amplitude, int Speed, float wavelengths); // the function that mimic the snake motion
    void straightline(); //the function to initialise all the servo to a 90° angle
    float teta(int offset, int Amplitude, int Speed, float Wavelengths, int j, float rads); // to calculate the angle of each servo
    float choose(int value);// to decide wich direction need to be taken
  private:

};