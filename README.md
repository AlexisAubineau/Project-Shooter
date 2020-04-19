# O Space Made By Patrcik and Alexis

Projet créé à partir de la SFML 2.5.1, le but de ce projet étais de créer une architecture forte capable de servir de base sur d'autres projets perso et d'évaluer nos compétences acquises en C++ .

L’exécutable du projet est disponible à l'adesse suivante :
[Lien release Github](https://github.com/AlexisAubineau/Project-Shooter/releases/tag/1.0.0)

Les sources du projet sont disponible à l'adresse suivante :
[Lien repo Github](https://github.com/AlexisAubineau/Project-Shooter)

## SDK SFML 2.5.1 : 
Suite au téléchargement des sources du projet vous devriez pouvoir lancer un build de debug ou build une release si vous avez un problème regarder bien dans les propriétés du projets si les chemins ci-dessous sont correcte :

 - Propriété de config -> C/C++ -> Général -> Autres répertoires include : SFML-2.5.1/include
 - Propriété de config -> Editeur de lien -> Général -> Répertoires de bibliothèques supplémentaires : SFML-2.5.1/lib

## Controle du jeu : 

Déplacement du joueur :
 
 - Move Up : Z
 - Move Down : S
 - Move Left : Q
 - Move Right : D
 
 Action du joueur :
 
  - Tire : SPACE

## Travail réalisé par l'équipe :

Pour ce projet nous avons constitué une équipe de 2 personnes:

 - Patrick
 - Alexis

### Travail réalisé par Patrick :

 - Engine
 - Mob Spawner
 - Normal Ennemie mechanics
 - Normal Ennemie Projectile
 - Death Ennemie Systems
 - Boss
 - Graphics

### Travail réalisé par Alexis :

 - Player
 - Player Projectile
 - Death Player Systems
 - Death Menu Systems

## Difficultés rencontré :

 #### Patrick :
 
  - Le moteur:
    * Création des differents outils: GameObject, GameObjectManager
- Normal Enemy:
    * Du mal a leur donner un patern et leur faire tirer des projectiles
    * Gestion des projectiles enemis
- Enemy Wave Spawner:
    * Gros mal a spawn des mobs en vagues, 
    * Gerer les collisions des mobs par rapports aux balles
    
 #### Alexis :
 
  - Gestion des projectiles
  - Gestion de la suppression du joueur lors de ça mort
  - Bouncing Border pour repousser le joueur lorsqu'il atteint la limite de la fenetre
