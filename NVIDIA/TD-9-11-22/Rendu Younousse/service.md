#services

##unit

Dans "Description" on donne le rôle du service.

"after=network.target" permet de lancer le service au moment où il y a une connexion internet.

##Service

dans "WorkingDirectory" on met le chemin du dossier contenant le ".sh" .

On donne l'utilisateur "User".

Type=oneshot pour que le programme ne se lance qu'une seule fois.

On donne le chemin du fichier  pour ExecStart.

##Install

"WantedBy=multi-user.target" définit l'état du service, on dit à "systemd" que le service doit débuter comme si il faisait partie du systeme de démarage.

##lancement:
pour le lancement du service tout d'abord on utilise "sudo systemcl daemon-reload" pour que le système prenne en compte les modifications sur les services.
Ensuite on lance le service avec "sudo systemctl start databasesaving.service".
