# Raycasting — Cours Complet pour cub3D

> **Objectif :** Comprendre toutes les notions mathématiques et algorithmiques nécessaires pour implémenter un moteur de raycasting à la Wolfenstein 3D / cub3D.

---

## Table des matières

1. [Notions fondamentales de géométrie et de trigonométrie](#1-notions-fondamentales)
2. [Le système de coordonnées et la grille de jeu](#2-la-grille-de-jeu)
3. [Le principe du Raycasting](#3-le-principe-du-raycasting)
4. [Le joueur : position, direction et plan caméra](#4-le-joueur)
5. [L'algorithme DDA (Digital Differential Analysis)](#5-lalgorithme-dda)
6. [Calcul de la hauteur des murs](#6-calcul-de-la-hauteur-des-murs)
7. [Correction de l'effet fisheye](#7-correction-de-leffet-fisheye)
8. [Texturage des murs](#8-texturage-des-murs)
9. [Orientation des murs (N/S/E/W)](#9-orientation-des-murs)
10. [Gestion des mouvements du joueur](#10-mouvements-du-joueur)
11. [Récapitulatif de l'algorithme complet](#11-recapitulatif)
12. [Annexe : Formules et Cheatsheet](#12-annexe)

---

## 1. Notions Fondamentales

### 1.1 Vecteurs 2D

Un **vecteur** est une quantité ayant une **direction** et une **magnitude** (longueur).

```
Vecteur v = (x, y)
```

- **Magnitude (norme)** : `|v| = sqrt(x² + y²)`
- **Vecteur unitaire (normalisé)** : `v̂ = (x / |v|, y / |v|)`  
  → Sa norme vaut exactement 1. Utile pour représenter des directions pures.
- **Addition** : `v1 + v2 = (x1+x2, y1+y2)`
- **Soustraction** : `v1 - v2 = (x1-x2, y1-y2)`
- **Multiplication scalaire** : `k * v = (k*x, k*y)`
- **Produit scalaire (dot product)** : `v1 · v2 = x1*x2 + y1*y2`

### 1.2 Trigonométrie essentielle

Dans un cercle unité (rayon = 1) centré en O :

```
cos(θ) = composante X
sin(θ) = composante Y
```

Un angle `θ` donne le vecteur direction : `d = (cos(θ), sin(θ))`

| Angle (degrés) | Angle (radians) | cos(θ) | sin(θ) |
|:--------------:|:---------------:|:------:|:------:|
| 0°  | 0       | 1      | 0      |
| 90° | π/2     | 0      | 1      |
| 180°| π       | -1     | 0      |
| 270°| 3π/2    | 0      | -1     |

> **En C**, les fonctions `cos()` et `sin()` de `<math.h>` prennent des **radians**.  
> Conversion : `radians = degrés * (M_PI / 180.0)`

### 1.3 Rotation d'un vecteur

Pour **faire pivoter** un vecteur `(x, y)` d'un angle `α` :

```
x' = x * cos(α) - y * sin(α)
y' = x * sin(α) + y * cos(α)
```

Cette formule est **fondamentale** pour la rotation du joueur.  
Pour une rotation vers la gauche, `α > 0` ; vers la droite, `α < 0`.

### 1.4 Coordonnées cartésiennes vs. grille

Dans cub3D, l'espace est une **grille 2D** où chaque case est un carré de côté 1. La position du joueur est un vecteur de coordonnées réelles (flottantes), ex. `(3.5, 2.2)`.

---

## 2. La Grille de Jeu

### 2.1 Représentation de la carte

La carte est un tableau 2D de caractères (ex. `map[y][x]`) :

```
111111
100001
101001
100001
111111
```

- `1` = mur
- `0` = couloir libre

> **Attention :** La convention habituelle est `map[y][x]` (ligne, colonne).  
> Ainsi `x` correspond à la colonne (horizontal) et `y` à la ligne (vertical).

### 2.2 Systèmes de coordonnées

```
    y
    ↑
    |
    |
    +------→ x
   (0,0)
```

En raycasting, on travaille en coordonnées **monde** (world coordinates) où une case de la grille = 1 unité.

Un joueur en `(3.5, 2.5)` est au **centre** de la case `(3, 2)`.

---

## 3. Le Principe du Raycasting

### 3.1 Idée générale

Le raycasting est une technique qui **simule une vue 3D** à partir d'une carte 2D.

**Principe :**
1. Pour chaque colonne de pixels de l'écran (de `x=0` à `x=SCREEN_WIDTH-1`), on lance un **rayon** depuis la position du joueur.
2. Ce rayon avance jusqu'à toucher un **mur**.
3. La **distance** au mur détermine la **hauteur** de la tranche de mur dessinée : plus le mur est loin, plus il est petit.

```
         Vue du dessus (2D)
         
         +---------+
         |         |
         |  Rayon  |
 Joueur  +---->----+ Mur touché
         |         |
         +---------+
         
         Vue à l'écran (3D simulé)
         
         ┌───────────────────┐
         │    PLAFOND        │
         │───────────────────│
         │    MUR            │  ← hauteur dépend de la distance
         │───────────────────│
         │    SOL            │
         └───────────────────┘
```

### 3.2 Pourquoi ça fonctionne ?

L'illusion de profondeur vient de la **perspective** : un objet 2x plus loin paraît 2x plus petit.

Si `distance_projetee` est la distance corrigée au mur, la hauteur du mur dessinée est :

```
hauteur_mur = SCREEN_HEIGHT / distance_projetee
```

### 3.3 Espace caméra vs. espace monde

On distingue :
- **Espace monde** : coordonnées de la grille (position du joueur, des murs)
- **Espace caméra** : coordonnées normalisées de -1 à +1 sur l'axe horizontal de l'écran

Pour la colonne `x` de l'écran :
```
cameraX = 2 * x / SCREEN_WIDTH - 1
```
- `cameraX = -1` → bord gauche de l'écran
- `cameraX = 0`  → centre de l'écran
- `cameraX = +1` → bord droit de l'écran

---

## 4. Le Joueur

### 4.1 Position

```c
double posX, posY;  // Position dans la grille
```

Exemple : `posX = 3.5`, `posY = 2.5` → au centre de la case (3,2).

### 4.2 Vecteur Direction

```c
double dirX, dirY;  // Vecteur direction (normalisé)
```

Ce vecteur indique **où regarde** le joueur. Il doit être **normalisé** (norme = 1).

Exemple : `dirX = -1.0, dirY = 0.0` → le joueur regarde vers la gauche (axe X négatif).

### 4.3 Plan Caméra (Camera Plane)

```c
double planeX, planeY;  // Vecteur plan caméra
```

Le plan caméra est un vecteur **perpendiculaire** à la direction. Il représente la **largeur du champ de vision** (FOV).

```
        Plan caméra
        ←——————————→
        
        planeX, planeY
        
              ↑
              | dirX, dirY (direction)
              |
           [Joueur]
```

**Relation fondamentale :**  
Le plan caméra est perpendiculaire à la direction.  
Si `dir = (dirX, dirY)`, alors `plane = (-dirY, dirX)` (rotation de 90°), mais sa **magnitude** définit le FOV.

### 4.4 Champ de vision (FOV)

```
FOV = 2 * atan(|plane| / |dir|)
```

Pour `|dir| = 1` et `|plane| = 0.66` :

```
FOV ≈ 2 * atan(0.66) ≈ 66°
```

C'est la valeur classique pour cub3D. Pour un FOV de 90° : `|plane| = 1.0`.

> **Règle importante :** Le vecteur direction et le plan caméra doivent **toujours rester perpendiculaires**. Lors de la rotation, les deux sont tournés du même angle.

### 4.5 Valeurs initiales typiques

Joueur regardant vers le **bas** (axe Y positif) :
```c
posX   = 1.5;   posY   = 1.5;
dirX   = 0.0;   dirY   = 1.0;
planeX = 0.66;  planeY = 0.0;
```

Joueur regardant vers le **haut** (axe Y négatif) :
```c
dirX = 0.0;  dirY = -1.0;
planeX = -0.66;  planeY = 0.0;
```

Joueur regardant vers la **droite** (axe X positif) :
```c
dirX = 1.0;  dirY = 0.0;
planeX = 0.0;  planeY = 0.66;
```

---

## 5. L'Algorithme DDA

Le **DDA (Digital Differential Analysis)** est l'algorithme qui détermine quelle case de la grille un rayon traverse, et dans quel ordre.

### 5.1 Construction du rayon

Pour la colonne `x` de l'écran :

```c
double cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
double rayDirX = dirX + planeX * cameraX;
double rayDirY = dirY + planeY * cameraX;
```

`rayDir` est le **vecteur direction du rayon** pour cette colonne.

### 5.2 Case de départ

```c
int mapX = (int)posX;  // Case où se trouve le joueur
int mapY = (int)posY;
```

### 5.3 deltaDist — Distance entre deux intersections

**deltaDist** est la distance que le rayon parcourt pour traverser **une case complète** dans la direction X ou Y.

```
deltaDistX = |1 / rayDirX|
deltaDistY = |1 / rayDirY|
```

**Pourquoi ?**  
Si le rayon parcourt `rayDirX` unités en X pour `1` unité de longueur, il faut `1/rayDirX` unités de longueur pour avancer de 1 unité en X.

```
       Y
       |
   ----+----+----+----
       |    |    |    
   ----+----+----+----
       |    |    |    
   ----+----+----+----
       |    |    |    
   ----+----+--->+----  X
   
   <--deltaDistX-->
```

> **Cas limite :** Si `rayDirX == 0`, `deltaDistX = INFINITY` (le rayon est parallèle à l'axe Y, il ne croisera jamais une ligne verticale).

### 5.4 sideDist — Distance à la première intersection

**sideDist** est la distance au **premier bord de case** que le rayon va croiser.

```c
double sideDistX, sideDistY;

if (rayDirX < 0) {
    stepX = -1;
    sideDistX = (posX - mapX) * deltaDistX;
} else {
    stepX = 1;
    sideDistX = (mapX + 1.0 - posX) * deltaDistX;
}

if (rayDirY < 0) {
    stepY = -1;
    sideDistY = (posY - mapY) * deltaDistY;
} else {
    stepY = 1;
    sideDistY = (mapY + 1.0 - posY) * deltaDistY;
}
```

- **`stepX / stepY`** : direction de progression sur la grille (+1 ou -1).
- Si le rayon va vers la **droite** (rayDirX > 0), la première intersection verticale est à `mapX + 1`.
- Si le rayon va vers la **gauche** (rayDirX < 0), la première intersection verticale est à `mapX`.

### 5.5 La boucle DDA — Avancer case par case

```c
int hit = 0;
int side;  // 0 = mur vertical (axe X), 1 = mur horizontal (axe Y)

while (hit == 0) {
    // Avancer vers la prochaine intersection la plus proche
    if (sideDistX < sideDistY) {
        sideDistX += deltaDistX;
        mapX += stepX;
        side = 0;
    } else {
        sideDistY += deltaDistY;
        mapY += stepY;
        side = 1;
    }
    // Vérifier si on a touché un mur
    if (map[mapY][mapX] > 0)
        hit = 1;
}
```

**Logique de la boucle :**
- On compare `sideDistX` et `sideDistY`.
- On avance vers l'intersection la **plus proche** (la plus petite des deux).
- Après avoir avancé, on met à jour `sideDist` en ajoutant `deltaDist`.
- On vérifie si la nouvelle case contient un mur.

### 5.6 Visualisation du DDA

```
  +---+---+---+---+
  |   |   |   |▓▓▓|  ← Mur touché
  +---+---+---+---+
  |   | ↗ |   |   |
  +---+/--+---+---+
  | ↗ |   |   |   |
  +-/-+---+---+---+
  |P  |   |   |   |  P = joueur
  +---+---+---+---+
  
  Les × sont les intersections vérifiées par DDA
```

---

## 6. Calcul de la Hauteur des Murs

### 6.1 Distance perpendiculaire au plan caméra

**IMPORTANT :** On ne calcule pas la distance euclidienne (en ligne droite) entre le joueur et le mur, mais la **distance perpendiculaire au plan caméra**. C'est cette distance qui élimine l'effet fisheye.

```c
double perpWallDist;

if (side == 0)
    perpWallDist = (sideDistX - deltaDistX);
else
    perpWallDist = (sideDistY - deltaDistY);
```

**Pourquoi cette formule ?**

Quand la boucle DDA se termine, `sideDistX` (ou `sideDistY`) contient déjà la distance **après** avoir franchi le mur. En soustrayant `deltaDistX` (ou `deltaDistY`), on revient à la distance **au mur**.

### 6.2 Hauteur de la ligne de mur

```c
int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);
```

Cette formule vient de la **projection perspective** :
- Un mur à distance 1 occupe toute la hauteur de l'écran.
- Un mur à distance 2 occupe la moitié de la hauteur.
- Un mur à distance d occupe `SCREEN_HEIGHT / d` pixels.

### 6.3 Pixels de début et fin de la tranche

```c
int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
if (drawStart < 0) drawStart = 0;

int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
if (drawEnd >= SCREEN_HEIGHT) drawEnd = SCREEN_HEIGHT - 1;
```

- Le mur est **centré verticalement** sur l'écran.
- `SCREEN_HEIGHT / 2` est le centre vertical.
- On dessine de `drawStart` à `drawEnd`.

---

## 7. Correction de l'Effet Fisheye

### 7.1 Qu'est-ce que l'effet fisheye ?

Si on utilise la **distance euclidienne** (ligne droite joueur → point d'impact), les murs sur les côtés de l'écran semblent incurvés, comme une photo prise avec un objectif fisheye.

```
   Avec distance euclidienne       Avec distance perpendiculaire
   (effet fisheye)                 (correct)
   
   |  \         /  |              |            |
   |   \       /   |              |            |
   | ↑  |     |  ↑ |              |            |
   |dist|     |dist|              |   hauteur  |
   |↓   |     |   ↓|              |  uniforme  |
   |    |     |    |              |            |
```

### 7.2 Pourquoi la distance perpendiculaire est correcte ?

La **distance perpendiculaire** est la projection de la distance réelle sur l'axe de vision du joueur.

```
       Plan caméra
    A  ←——————————→  B
       
    d_eucl = distance réelle jusqu'au mur en A (plus longue)
    d_perp = projection perpendiculaire (correcte)
    
    d_eucl > d_perp → si on utilise d_eucl, le mur en A paraît plus petit → fisheye
```

**La formule DDA donne directement `perpWallDist`** sans nécessiter de calcul trigonométrique supplémentaire. C'est l'un des grands avantages de l'algorithme.

---

## 8. Texturage des Murs

### 8.1 Coordonnée de texture X (wallX)

Pour chaque rayon qui touche un mur, on calcule **où exactement** sur la face du mur il touche. C'est la coordonnée `wallX` (un nombre entre 0 et 1).

```c
double wallX;

if (side == 0)
    wallX = posY + perpWallDist * rayDirY;
else
    wallX = posX + perpWallDist * rayDirX;

wallX -= floor(wallX);  // Garde uniquement la partie fractionnaire
```

**Explication :**
- Si `side == 0` (mur vertical, le rayon a croisé une ligne X), l'intersection est à `posY + perpWallDist * rayDirY`.
- On soustrait `floor(wallX)` pour obtenir la position **relative** dans la case (entre 0 et 1).

### 8.2 Coordonnée de texture X en pixels

```c
int texX = (int)(wallX * TEX_WIDTH);

// Correction de l'orientation (éviter texture miroir)
if (side == 0 && rayDirX > 0) texX = TEX_WIDTH - texX - 1;
if (side == 1 && rayDirY < 0) texX = TEX_WIDTH - texX - 1;
```

### 8.3 Coordonnée de texture Y (texY) — Pas à pas vertical

Pour chaque pixel vertical de la colonne, on calcule la coordonnée Y dans la texture :

```c
double step = 1.0 * TEX_HEIGHT / lineHeight;
double texPos = (drawStart - SCREEN_HEIGHT / 2 + lineHeight / 2) * step;

for (int y = drawStart; y < drawEnd; y++) {
    int texY = (int)texPos & (TEX_HEIGHT - 1);
    texPos += step;
    
    // Récupérer la couleur dans la texture à (texX, texY)
    uint32_t color = texture[texY * TEX_WIDTH + texX];
    
    // Assombrir les murs sur les faces Y (ombrage)
    if (side == 1) color = (color >> 1) & 0x7F7F7F;
    
    framebuffer[y * SCREEN_WIDTH + x] = color;
}
```

**`step`** : combien d'unités de texture correspondent à un pixel d'écran.
- Si `lineHeight < TEX_HEIGHT` : le mur est petit (loin), on saute des texels.
- Si `lineHeight > TEX_HEIGHT` : le mur est grand (proche), on répète des texels.

### 8.4 Ombrage selon l'orientation

Un ombrage simple et efficace : les faces Nord/Sud (side == 1) sont assombries d'un facteur 2.

```c
if (side == 1)
    color = (color >> 1) & 0x7F7F7F;  // Division par 2 de chaque composante RGB
```

---

## 9. Orientation des Murs (N/S/E/W)

Pour appliquer une texture différente selon la face du mur :

```c
int texIndex;  // Index de la texture à utiliser

if (side == 0) {          // Mur vertical (face E ou W)
    if (rayDirX > 0)
        texIndex = EAST;  // Face Est
    else
        texIndex = WEST;  // Face Ouest
} else {                  // Mur horizontal (face N ou S)
    if (rayDirY > 0)
        texIndex = SOUTH; // Face Sud
    else
        texIndex = NORTH; // Face Nord
}
```

> **Convention d'orientation :**  
> - `side == 0` et `rayDirX > 0` : le rayon vient de la **gauche**, il touche la face **Est** du mur.  
> - `side == 0` et `rayDirX < 0` : le rayon vient de la **droite**, il touche la face **Ouest** du mur.  
> - `side == 1` et `rayDirY > 0` : le rayon vient du **haut**, il touche la face **Sud** du mur.  
> - `side == 1` et `rayDirY < 0` : le rayon vient du **bas**, il touche la face **Nord** du mur.

---

## 10. Mouvements du Joueur

### 10.1 Avancer / Reculer

On déplace le joueur dans la **direction du regard** :

```c
double moveSpeed = 0.05;

// Avancer
if (key_up) {
    if (map[(int)(posY)][(int)(posX + dirX * moveSpeed)] == 0)
        posX += dirX * moveSpeed;
    if (map[(int)(posY + dirY * moveSpeed)][(int)(posX)] == 0)
        posY += dirY * moveSpeed;
}

// Reculer
if (key_down) {
    if (map[(int)(posY)][(int)(posX - dirX * moveSpeed)] == 0)
        posX -= dirX * moveSpeed;
    if (map[(int)(posY - dirY * moveSpeed)][(int)(posX)] == 0)
        posY -= dirY * moveSpeed;
}
```

**Note :** La **collision** est gérée en vérifiant X et Y **séparément**. Ainsi le joueur peut longer un mur.

### 10.2 Rotation (tourner)

La rotation applique la **matrice de rotation** à la fois sur `dir` et sur `plane` :

```c
double rotSpeed = 0.03;  // en radians par frame

// Rotation vers la droite
if (key_right) {
    double oldDirX = dirX;
    dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
    dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
    
    double oldPlaneX = planeX;
    planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
    planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
}

// Rotation vers la gauche
if (key_left) {
    double oldDirX = dirX;
    dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
    dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
    
    double oldPlaneX = planeX;
    planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
    planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
}
```

> **Pourquoi tourner aussi le plan caméra ?**  
> Le plan caméra doit toujours être perpendiculaire à la direction. Si on tourne uniquement `dir` sans tourner `plane`, le FOV sera faussé.

---

## 11. Récapitulatif de l'Algorithme Complet

Voici le pseudocode de la boucle de rendu principale :

```
POUR chaque colonne x de 0 à SCREEN_WIDTH - 1 :

  1. CALCULER la coordonnée caméra
     cameraX = 2 * x / SCREEN_WIDTH - 1
     
  2. CALCULER la direction du rayon
     rayDirX = dirX + planeX * cameraX
     rayDirY = dirY + planeY * cameraX
     
  3. INITIALISER la case de départ
     mapX = (int)posX
     mapY = (int)posY
     
  4. CALCULER deltaDist
     deltaDistX = |1 / rayDirX|
     deltaDistY = |1 / rayDirY|
     
  5. CALCULER sideDist initial et stepX/Y
     (selon le signe de rayDirX/Y)
     
  6. BOUCLE DDA jusqu'au mur
     Tant que pas de mur :
       Si sideDistX < sideDistY :
         sideDistX += deltaDistX
         mapX += stepX
         side = 0
       Sinon :
         sideDistY += deltaDistY
         mapY += stepY
         side = 1
       Si map[mapY][mapX] == mur → arrêter
       
  7. CALCULER perpWallDist
     Si side == 0 : perpWallDist = sideDistX - deltaDistX
     Sinon        : perpWallDist = sideDistY - deltaDistY
     
  8. CALCULER lineHeight, drawStart, drawEnd
     lineHeight = SCREEN_HEIGHT / perpWallDist
     drawStart  = -lineHeight/2 + SCREEN_HEIGHT/2
     drawEnd    = lineHeight/2 + SCREEN_HEIGHT/2
     
  9. CALCULER texX (coordonnée texture X)
     wallX = (posY ou posX) + perpWallDist * (rayDirY ou rayDirX)
     wallX -= floor(wallX)
     texX = (int)(wallX * TEX_WIDTH)
     
 10. CHOISIR la texture (N/S/E/W)
 
 11. DESSINER la colonne pixel par pixel
     - Plafond : couleur fixe (de y=0 à drawStart)
     - Mur : échantillonner la texture
     - Sol : couleur fixe (de drawEnd à SCREEN_HEIGHT)
```

---

## 12. Annexe : Formules et Cheatsheet

### 12.1 Résumé des variables clés

| Variable | Type | Description |
|----------|------|-------------|
| `posX, posY` | double | Position du joueur dans la grille |
| `dirX, dirY` | double | Vecteur direction (normalisé) |
| `planeX, planeY` | double | Plan caméra (perpendiculaire à dir) |
| `cameraX` | double | Coordonnée caméra [-1, +1] |
| `rayDirX, rayDirY` | double | Direction du rayon pour la colonne x |
| `mapX, mapY` | int | Case courante dans la grille |
| `deltaDistX, deltaDistY` | double | Distance entre deux intersections |
| `sideDistX, sideDistY` | double | Distance à la prochaine intersection |
| `stepX, stepY` | int | Direction de progression (+1 ou -1) |
| `side` | int | 0=mur vertical, 1=mur horizontal |
| `perpWallDist` | double | Distance perpendiculaire au plan caméra |
| `lineHeight` | int | Hauteur en pixels de la tranche de mur |
| `wallX` | double | Position d'impact sur la face [0,1] |
| `texX, texY` | int | Coordonnées dans la texture |

### 12.2 Toutes les formules

```
cameraX        = 2 * x / SCREEN_WIDTH - 1
rayDirX        = dirX + planeX * cameraX
rayDirY        = dirY + planeY * cameraX
deltaDistX     = |1 / rayDirX|   (INFINITY si rayDirX == 0)
deltaDistY     = |1 / rayDirY|   (INFINITY si rayDirY == 0)
perpWallDist   = sideDistX - deltaDistX  (si side == 0)
               = sideDistY - deltaDistY  (si side == 1)
lineHeight     = SCREEN_HEIGHT / perpWallDist
drawStart      = -lineHeight / 2 + SCREEN_HEIGHT / 2
drawEnd        = lineHeight / 2 + SCREEN_HEIGHT / 2
wallX          = posY + perpWallDist * rayDirY  (si side == 0)
               = posX + perpWallDist * rayDirX  (si side == 1)
wallX         -= floor(wallX)
texX           = (int)(wallX * TEX_WIDTH)
step (tex)     = TEX_HEIGHT / lineHeight
texPos initial = (drawStart - SCREEN_HEIGHT/2 + lineHeight/2) * step
```

### 12.3 Rotation du joueur

```
dir_new_X  = dirX * cos(a) - dirY * sin(a)
dir_new_Y  = dirX * sin(a) + dirY * cos(a)
plane_new_X = planeX * cos(a) - planeY * sin(a)
plane_new_Y = planeX * sin(a) + planeY * cos(a)
```
Rotation gauche : `a > 0` / Rotation droite : `a < 0`

### 12.4 Conseils d'implémentation

1. **Toujours tester X et Y séparément** pour les collisions.
2. **Ne jamais diviser par zéro** : gérer le cas `rayDirX == 0` et `rayDirY == 0`.
3. **La texture doit être une puissance de 2** (ex: 64x64, 128x128) pour utiliser l'opération `& (TEX_SIZE - 1)` à la place du modulo.
4. **Séparer le rendu des murs** (raycasting) **du rendu du sol et plafond** (deux passes distinctes ou calcul par pixel).
5. **FOV standard** : direction normalisée + plan de magnitude 0.66 ≈ 66°.

---

*Cours rédigé pour le projet cub3D — 42 School*  
*Références : Lode's Computer Graphics Tutorial (lodev.org)*
