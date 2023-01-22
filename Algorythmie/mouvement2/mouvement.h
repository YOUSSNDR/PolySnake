#include <Servo.h>
class mouvement{
  public:
    mouvement();
    Servo myServos[10]; //permet d'initialiser 10 objets de type servo ils seront utiles ppour le controle des servos moteurs
    float pi=3.14159; //on pourrais utiliser une fonction mais une valeur aproximé nous suffit
    int vNombre_total_de_servo=10; //on note le nombre de servos cette variable pourra être modifier selon le nombre de servos que l'on utilise on l'initialise a 10 le nombre de servos que nous voulons utiliserau total
    float vDephasage = 2*pi/vNombre_total_de_servo; //déphasage que l'on mettra entre les servos pour permettre le mouvement
    float vLongueur_d_onde, rads; //longueur d'onde et la variable pour stocker un angle en radiant
    int  vAnglemaximal; //cette variable définit l'angle maximal que prendra le servo (pour éviter les angles >180 deg l'angle max de nos servos)
    void fOndulation(int vDecallage, int vAmplitude, int vVitesse, float vLongueur_d_onde);// la fonction permettant les ondulation on peut y controler longueur d'onde, vitesse de propagation, amplitude et décalage (le décalage nous permet de choisir une direction au robot)
    void fLigne(); // fonction permettant de mettre le serpent en ligne droite utilise moins de courant que de mettre l'amplitude a 0 sur la fonction ondulation
  private:

};