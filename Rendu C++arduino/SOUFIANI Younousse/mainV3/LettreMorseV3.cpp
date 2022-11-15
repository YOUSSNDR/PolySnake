#include "LettreMorseV3.h"

LettreMorse::LettreMorse(){};


void LettreMorse::morsetr(int code){
    switch (code){//on test tous les caractère pour voir si il y a correspondance et on prend sa traduction morse
    case 'a':
        morse = ".-";
        break;
    case 'b':
        morse = "-...";
        break;
    case 'c':
        morse = "-.-.";
        break;
    case 'd':
        morse = "-..";
        break;
    case 'e':
        morse = ".";
        break;
    case 'f':
        morse = "..-.";
        break;
    case 'g':
        morse = "--.";
        break;
    case 'h':
        morse = "....";
        break;
    case 'i':
        morse = "..";
        break;
    case 'j':
        morse = ".---";
        break;
    case 'k':
        morse = "-.-";
        break;
    case 'l':
        morse = ".-..";
        break;
    case 'm':
        morse = "--";
        break;
    case 'n':
        morse = "-.";
        break;
    case 'o':
        morse = "---";
        break;
    case 'p':
        morse = ".--.";
        break;
    case 'q':
        morse = "--.-";
        break;
    case 'r':
        morse = ".-.";
        break;
    case 's':
        morse = "...";
        break;
    case 't':
        morse = "-";
        break;
    case 'u':
        morse = "..-";
        break;
    case 'v':
        morse = "...-";
        break;
    case 'w':
        morse = ".--";
        break;
    case 'x':
        morse = "-..-";
        break;
    case 'y':
        morse = "-.--";
        break;
    case 'z':
        morse = "--..";
        break;
    case '1':
        morse = ".----";
        break;
    case '2':
        morse = "..---";
        break;
    case '3':
        morse = "...--";
        break;
    case '4':
        morse = "....-";
        break;
    case '5':
        morse = ".....";
        break;
    case '6':
        morse = "-....";
        break;
    case '7':
        morse = "--...";
        break;
    case '8':
        morse = "---..";
        break;
    case '9':
        morse = "----.";
        break;
    case '0':
        morse = "-----";
        break;
    default:
        morse = "";
        break;
    }
    }
