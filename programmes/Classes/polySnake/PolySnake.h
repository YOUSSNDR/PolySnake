class mouvement{
  public:
    mouvement();
    const float pi=3.14159;
    const int TotalNumberofServos=10;
    const float Shift = 2*pi/TotalNumberofServos;
    const float Wavelengths, rads;
    const int  MaxAngleDisplacement;
    void slither(int offset, int Amplitude, int Speed, float wavelengths);
    void straightline();
    private:

}:

class roues{
  public:
  
}