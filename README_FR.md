🇬🇧 English version available [here](README.md)
* * *
# Présentation du projet `cpp_05`
## Description
Ce module introduit les exceptions en C++ et se concentre sur la gestion sécurisée et correcte des erreurs.

À travers ces exercices, l’objectif est d’apprendre à lancer, capturer et propager des exceptions, à créer des classes d’exceptions personnalisées, et à garantir la gestion correcte des ressources même en cas d’erreurs. Cela renforce une conception orientée objet robuste.

* * *
## Langages & Technologies

**Langage**
- C++ (standard C++98)

**Technologies**
- Makefile

* * *
## Concepts clés
- Gestion des exceptions (`try`, `catch`, `throw`)
- Exceptions standards (`std::exception`)
- Classes d’exceptions personnalisées
- Sécurité des ressources et gestion mémoire
- Garantie de sécurité forte des exceptions
- Hiérarchie des exceptions et slicing

* * *
## Aperçu des exercices
### ex00. Mommy, when I grow up, I want to be a bureaucrat!
Introduction à la gestion des exceptions de base :
- Gestion des exceptions standards
- Utilisation de `try`, `catch` et `throw`

### ex01. Form up, maggots!
Création et utilisation de classes d’exceptions personnalisées :
- Implémentation de la méthode `what()`
- Lancer et capturer des exceptions personnalisées

### ex02. No, you need form 28B, not 28C...
Assurer la sécurité des ressources et la gestion correcte des objets lors d’exceptions :
- Utilisation correcte des constructeurs/destructeurs
- Éviter les fuites mémoire

### ex03. At least this beats coffee-making
Travail avec plusieurs niveaux d’exceptions et héritage :
- Capturer des exceptions par type de classe de base
- Compréhension du slicing des exceptions
- Organisation propre de la gestion des erreurs

* * *

## Règles de compilation

Tous les exercices sont compilés avec les flags suivants :
- `-Wall`
- `-Wextra`
- `-Werror`
- `-std=c++98`

* * *
# Utilisation de `cpp_05`

## **Comment utiliser `cpp_05`**

*Note : ce dépôt contient uniquement le module `cpp_05`. Il fait partie du dépôt global [cpp_modules](https://github.com/bibickette/cpp_modules), qui regroupe l’ensemble des modules C++.*
1. Clonez `cpp_05` dans un dossier : `git clone https://github.com/bibickette/cpp_05.git`
2. Déplacez-vous dans le dépôt : `cd cpp_05`
3. Compilez le module : `make`; cela compilera tous les exercices du module
4. Vous pouvez maintenant vous rendre dans chaque dossier d’exercice et lancer les exécutables correspondants

* * *

*Date de validation du projet : 19 mars 2025*