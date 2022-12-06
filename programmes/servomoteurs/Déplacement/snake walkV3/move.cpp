#include "move.h"
#include<Arduino.h>

Move::Move(){};

void Move::mv(int i1, int i2, int i3){
    switch (i1,i2){ // on compare avec chaque angle atteignable
    case 90, 67.5:
      
    case 112.5, 90:
    case 135, 112.5:
    case 112.5, 135:
    case 90, 112,5:
    case 67.5, 90:
    case 45, 67.5:
    case 67.5, 45:
    }
}