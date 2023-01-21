class moteurs{
  public:
    moteurs(int Ma, int Mr);
    int Ma,Mr; 
    void marche_avant(int speed);
    void marche_arriere(int speed);
    void stop();
  private:

};