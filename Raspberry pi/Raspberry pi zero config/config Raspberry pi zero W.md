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
![imager](https://github.com/YOUSSNDR/PolySnake/blob/4ac6e7a7b111ad55d9ccb3da3fdd20d2143687f6/Raspberry%20pi/Raspberry%20pi%20zero%20config/aide%20images/rasberrypi_imager.jpg)
il suffit de:
- choisir la version voulu (pour un zero W on prendra un lite 32 bit) ![os selection](https://github.com/YOUSSNDR/PolySnake/blob/4ac6e7a7b111ad55d9ccb3da3fdd20d2143687f6/Raspberry%20pi/Raspberry%20pi%20zero%20config/aide%20images/os%20selection.jpg)
- séletionner l'espace de stockage (la carte mini SD)
- écrire (l'écriture et la vérification prendront environ 8 minutes).![écriture](https://github.com/YOUSSNDR/PolySnake/blob/4ac6e7a7b111ad55d9ccb3da3fdd20d2143687f6/Raspberry%20pi/Raspberry%20pi%20zero%20config/aide%20images/%C3%A9criture.jpg)

#### configurer la connexion au résau wifi, et autoriser les connections à distance par ssh

##### 1) Mise en service du SSH
les opérations suivantes peuvent être faites avec l'invite de commande windows mais ici nous utiliserons le terminal de la machine virtuel.

- on active le port USB lié à la carte SD pour la machine virtuelle.
    pour cela:
    - on ouvre la machine virtuelle et on sélectionne "configuration" ![MV](https://github.com/YOUSSNDR/PolySnake/blob/4ac6e7a7b111ad55d9ccb3da3fdd20d2143687f6/Raspberry%20pi/Raspberry%20pi%20zero%20config/aide%20images/machine_virtuelle.jpg)
    - ensuite on choisit la section "USB" puis on ajoute un filtre usb ![port usb](https://github.com/YOUSSNDR/PolySnake/blob/4ac6e7a7b111ad55d9ccb3da3fdd20d2143687f6/Raspberry%20pi/Raspberry%20pi%20zero%20config/aide%20images/ajout_d_un_port_usb.jpg)

- on peut maintenant rentrer les fichiers nécessaires pour le service ssh et le wifi.
    Il faut maintenant:
    - démarrer la machine virtuelle
    - aller dans "bootfs" qui sera lue comme un clé usb et y ouvrir le terminal ![ouverture du terminal](https://github.com/YOUSSNDR/PolySnake/blob/4ac6e7a7b111ad55d9ccb3da3fdd20d2143687f6/Raspberry%20pi/Raspberry%20pi%20zero%20config/aide%20images/ouverture%20de%20terminal.jpg)
    - on y crée le fichier "ssh" avec la commande "touch ssh"
    - on crée ensuite le fichier "wpa_supplicant.conf" avec la commande touch wpa_supplicant.conf"
    - il faudra écrire dans ce fichier (on pourra utiliser la commande vim pour éditer le fichier)
    voici les commandes utilisés: ![command](https://github.com/YOUSSNDR/PolySnake/blob/4ac6e7a7b111ad55d9ccb3da3fdd20d2143687f6/Raspberry%20pi/Raspberry%20pi%20zero%20config/aide%20images/commandes%20terminal.jpg)
    et voici le texte a rentrer dans le fichier "wpa_supplicant.conf": ![wpa config](https://github.com/YOUSSNDR/PolySnake/blob/4ac6e7a7b111ad55d9ccb3da3fdd20d2143687f6/Raspberry%20pi/Raspberry%20pi%20zero%20config/aide%20images/wpa_supplicant_config.jpg)

On peut ensuite retirer la carte et la remettre au Raspberry pi, il faudra brancher celle-ci et attendre l'initialisation et la conexion au wifi qui devrait prendre un peu moins de 5 minutes.

##### 2) connexion SSH

une fois la connexion wifi établi, il nous faut relever l'adresse ip ou l'identifiant de la raspberry, si vous avez utilisez le partage de connexion de votre téléphone regardez dans les appareils connectés []().

on va maintenant se connecté à la carte en SSH, pour cela on peut utiliser l'invite de commande windows(ou le terminal linux):
- on utilise la commande "ssh pi@raspberrypi" où ssh "pi@adresseip"(en remplaçant adresseip par votre adresse ip)