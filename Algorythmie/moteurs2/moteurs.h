class moteurs{
  public:
    moteurs(int vAvance, int vRecul); //on définit la classe moteur qui nous permettra de faire une marche avant ou une marche arrière
    int vAvance,vRecul; //on définit de variable attribuer a l'avancer ou le recul des roues
    void fMarche_avant(int vitesse); //cette fonction permettra une marche avant à la vitesse choisi
    void fMarche_arriere(int vitesse); //cette fonction permettra une marche arriere à la vitesse choisi
    void fArret();//cette fonction permet un arrêt des roues
  private:

};