# INF224



## Partie C++

### Etape 5 : Traitement générique (en utilisant le polymorphisme) 

- **Une fonction virtuelle**:
	est une fonction pour laquelle on prévient le compilateur que le comportement 
risque d'être modifié par une classe dérivée.


- **Une fonction virtuelle pure (abstraite)**:
	est une fonction qui signale au compilateur qu'on ne dispose pas des informations 
nécessaires pour implémenter un comportement "de base" et donc dont le comportement 
devra être précisé pour les classes dérivées qu'on souhaite pouvoir instancier.


Dans notre cas il s'agit donc d'une fonction virtuelle pure, puisque chaque type d'objet 
nécessite un utilitaire différent pour être joué !

#### Question :
` Pourquoi il n'est plus possible d'instancer des objets de la classe de base ? `

#### Réponse:

La classe Multimedia contient une fonction virtuelle pure, il n'est plus donc possible de l'instancier.

### Etape 6 : Films et tableaux

#### Question :
` Que faut-il faire pour que l'objet Film ait plein contrôle sur ses données
et que son tableau de durées des chapitres ne puisse pas être modifié
(ou pire, détruit) à son insu ? `

#### Réponse :
Il faut copier le contenu du tableau donné en paramètre.

Il faut ensuite s'assurer de ne pas divulguer l'adresse du tableau interne 
en implémentant une méthode qui retourne un seul élément du tableau suivant 
son indice (un entier dans notre cas).

Si nous voulons impléemnter un accesseur, ce dernier doit retourner un pointeur de type const int*.
(attention, il est toujours possible de caster le const int* en int* mais cela entraîne un comportement indéfini !).



### Etape 7 : Destruction et copie des objets

#### Question :
` Parmi les classes précédemment écrites quelles sont celles qu'il faut modifier afin
qu'il n'y ait pas de fuite mémoire quand on détruit leurs instances ? `

#### Réponse :
La classe Film contient une allocation dynamique (new). Il ne faut donc pas oublier d'appeler delete dans le déstructeur.

### Etape 8 : Créer des groupes


### Etape 9 : Gestion automatique de la mémoire


### Etape 11 : Client / serveur

On ajoute la méthode processRequest à notre classe Manager.

Cette méthode est appelée chaque fois qu'il y a une requête à traiter.

Notons qu'on a modifié les méthodes printVariables de Multimedia afin de remplacer les "endl" par "||".
Ceci est fait dans le but de pouvoir envoyer les string en totalité via sockets.

On fait le parse de la requête envoyée par le client dans Manager::processRequest et on retourne le résultat dans le string "response"
donné en paramètres.

## Partie Java Swing

### Etape 1 : Fenêtre principale et quelques interacteurs

### Etape 2:  Menus, barre d'outils et actions
Nous optons dans la suite pour l'option où on utilise les Actions.
On crée donc des sous-classes de AbstractAction imbriquée dans notre RemoteControl.

### Etape 3: Intéraction client/serveur
On s'inspire du code Client.java afin de communiquer avec notre set-top box codée en C++

### Etape 4: Créer Makefile
