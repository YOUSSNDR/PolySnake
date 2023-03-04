## Config Raspberry pi zero W

#### Intro:
    Ce document présent servira d'exemple pour une configuration de carte Raspberry pi Zero et résume ce document:
 [Raspberry_pi_Zero_W:_Installation_sans_écran_ni_clavier](https://thedatafrog.com/fr/articles/raspberry-pi-zero-headless-install/)

### Etapes:
###### - flasher une image de raspbian lite sur la carte micro SD
###### - configurer la connexion au résau wifi, et autoriser les connections à distance par ssh
###### - démarrer le pi et s'y connecter par ssh pour finaliser l'installation

####  flasher une image de raspbian lite sur la carte micro SD
ici on s'aide de ce document: [Installation rapide minimale d'un raspberry pi](https://thedatafrog.com/fr/articles/minimal-install-raspberry-pi/)

Raspbian est le système d'exploitation recommandé pour le raspberry pi. Il s'utilise un peu comme Ubuntu.

1) télécharger l'image de Raspbian lite [ici](https://www.raspberrypi.com/software/), nous utiliserons [celle-ci](liensgithub).

2) pour graver l'image on peut utiliser [Etcher](https://www.balena.io/etcher) si ce qui a était installer et une image(.img).
dns notre cas pour la gravure tout est géré dans le .exe installé avant.
il suffit de:
- choisir la version voulu (pour un zero W on prendra un lite 32 bit)
- séletionner l'espace de stockage (la carte mini SD)
- écrire

#### configurer la connexion au résau wifi, et autoriser les connections à distance par ssh

##### 1) Mise en service de SSH

- on utilise la machine virtuelle en activant au préalable le port USB lié à la carte SD.
- on se place à la racine de la partition boot et on y cré le fichier nomé ssh (touch ssh) 