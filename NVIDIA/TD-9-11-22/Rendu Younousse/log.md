#GESTION DES LOGS

pour la gestion des logs on utilise un logrotate.

##création du fichier:

le fichier doit être créé dans /etc/logrotate.d  en utilisant la commande : sudo vim savedata 

##contenu du fichier:
pour la gestion des logs tout d'abord je donne l'emplacement du fichier pour lequel j'utilise le logrotate et ensuit j'utilise 3 commandes:

le daily pour que le logrotate s'éxecute tous les jours.

"size 63M" pour lancer le logrotate dés que le fichier atteint ce volume, celui-ci sera prioritaire sur le daily.

Enfin, le "rotate 10" pour qu'il n'y ai pas plus de 10 fichiers log créé en même temps.
