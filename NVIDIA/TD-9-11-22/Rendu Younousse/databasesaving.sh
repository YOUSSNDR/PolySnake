#!/bin/bash
exec &>> /var/log/dump-mysql.log

AMJ=$(date +%F);
H=$(date +%H);
M=$(date +%M);
S=$(date +%S);
date=${AMJ}"-"${H}"-"${M}"-"${S} 
echo let the save beguin 

mysqldump -u user -ppass classicmodels > /home/younousse/polytech/TD_SQL/save_sample/${date}.sql
cd /home/younousse/polytech/TD_SQL/save_sample #on se déplace dans save_sample
bzip2 ${date}.sql #compresse le fichier
n=$(ls -1 | wc -l) #prend le nombre de fichier dans le dossier

if [ "$n" -gt "5" ]
then
	echo to much files, need to erase some 
	rm $(ls -t | tail -1)
fi
