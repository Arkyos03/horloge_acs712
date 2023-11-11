# Projet Arduino avec Capteur de Courant, Horloge RTC et Émetteur Infrarouge

Ce projet Arduino utilise un capteur de courant ACS712, une horloge temps réel (RTC DS3231), et un émetteur infrarouge pour effectuer des actions en fonction du courant détecté.

## Description

Le code Arduino inclus dans ce projet surveille en continu le courant capté par le capteur ACS712. Lorsque le courant dépasse un certain seuil (0.17 ampère dans cet exemple), un minuteur de 1 minute est déclenché. À l'expiration du minuteur, des commandes infrarouges sont envoyées via l'émetteur infrarouge.

## Matériel Requis

- Capteur de courant ACS712
- Module RTC DS3231
- Émetteur infrarouge (et LED infrarouge)
- Arduino (avec ports analogiques et numériques)

## Câblage

Assurez-vous de câbler les composants selon le schéma de câblage fourni dans le code. Vous pouvez trouver des instructions détaillées dans la section "Câblage" du README.


## Personnalisation

Vous pouvez personnaliser ce projet en ajustant les seuils de courant, les durées du minuteur, ou en ajoutant des fonctionnalités supplémentaires selon vos besoins.

## Auteurs

- **Arkyos03**

N'hésitez pas à contribuer à ce projet en proposant des améliorations, des corrections de bugs, ou des fonctionnalités supplémentaires.

## Licence

-- 
