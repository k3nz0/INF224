# INF224



## Partie C++

### Etape 5 : Traitement générique (en utilisant le polymorphisme) 
Comment appelle-t'on ce type de méthode et comment faut-il les déclarer ? 

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
Si vous avez fait correctement ce qui précède, il ne sera plus possible
 d'instancer des objets de la classe de base. Pourquoi ?

#### Reponse: 

La classe Multimedia contient une fonction virtuelle pure, il n'est plus donc possible de l'instancier.

### Etape 6 : Films et tableaux

#### Question :
	Que faut-il faire pour que l'objet Film ait plein contrôle sur ses données 
et que son tableau de durées des chapitres ne puisse pas être modifié 
(ou pire, détruit) à son insu ? (c'est l'objet qui doit pouvoir modifier 
ce qui lui appartient, pas les autres !)

#### Reponse : 
Il faut copier le contenu du tableau donné en paramètre.

Il faut ensuite s'assurer de ne pas divulguer l'adresse du tableau interne 
en implémentant une méthode qui retourne un seul élément du tableau suivant 
son indice (un entier dans notre cas).



#### Question
Le même problème se pose si un accesseur retourne directement ce tableau sans prendre 
les précautions nécessaires : la encore le contenu du tableau n'est pas récopié 
et l'appelant peut le modifier à sa guise. 
Quelle est la solution très simple que propose C/+\+ pour éviter ce problème ?

#### Reponse: 
Il faut que l'accesseur retourne un pointeur de type const int*.
(attention, il est toujours possible de caster le const int* en int*, cela entraîne un comportement indéfini).



### Etape 7 : Destruction et copie des objets

#### Question :
Parmi les classes précédemment écrites quelles sont celles qu'il faut modifier afin qu'il n'y ait pas de fuite mémoire quand on détruit leurs instances ?

#### Reponse :
La classe Film contient une allocation dynamique (new). Il ne faut donc pas oublier d'appeler delete dans le déstructeur.


### Etape 11 : Client / serveur

On ajoute la méthode processRequest à notre classe Manager.
Cette méthode est appelée chaque fois qu'il y a une requête à traiter.
On fait le parse de la requête envoyée par le client dans Manager::processRequest.



## Etape 12 : Sérialisation / désérialisation


