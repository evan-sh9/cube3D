*This project has been created as part of the 42 curriculum by adjelili, eprieur.*
 
# cub3D — My first RayCaster with miniLibX
 
## Description
 
cub3D is a 42 school project inspired by **Wolfenstein 3D**, the world-famous game considered the first true First Person Shooter in video game history. The goal is to build a dynamic, realistic 3D graphical representation of the inside of a maze from a first-person perspective, using **ray-casting** techniques.
 
The program reads a `.cub` scene description file that defines wall textures, floor/ceiling colors, and a map layout. It then renders the maze in real time using the **miniLibX** graphics library.
 
### Features
 
**Mandatory**
- Ray-casting engine rendering walls with correct perspective
- Four distinct wall textures depending on the face direction (North, South, East, West)
- Configurable floor and ceiling colors (RGB)
- Player movement with `W`, `A`, `S`, `D`
- Camera rotation with the left/right arrow keys
- Clean exit on `ESC` or window close button
- Strict `.cub` map parsing with error handling
**Bonus**
- Wall collision detection — the player cannot walk through walls
- Minimap system — a top-down overview of the maze displayed on screen
---
 
## Instructions
 
### Requirements
 
- A Unix-based system (Linux or macOS)
- `cc` compiler
- `make`
- miniLibX (included or available on your system)
### Compilation
 
```bash
# Mandatory part
make
```
 
### Usage
 
```bash
./cub3D path/to/map.cub
```
 
### Map format (`.cub`)
 
The scene file must follow this structure:
 
```
NO ./path/to/north_texture.xpm
SO ./path/to/south_texture.xpm
WE ./path/to/west_texture.xpm
EA ./path/to/east_texture.xpm
 
F 220,100,0
C 225,30,0
 
1111111
1000001
10N0001
1111111
```
 
- `1` — wall
- `0` — empty space
- `N`, `S`, `E`, `W` — player start position and orientation
- The map must be closed/surrounded by walls
- The map must be the last element in the file
### Controls
 
| Key | Action |
|-----|--------|
| `W` / `A` / `S` / `D` | Move forward / left / backward / right |
| `←` / `→` | Rotate camera left / right |
| `ESC` | Quit the program |
 
---
 
## Resources
 
### Documentation & References
 
- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) — the main reference for understanding and implementing the DDA ray-casting algorithm
- [miniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx) — official documentation for the miniLibX graphics library
- [Wolfenstein 3D (play online)](http://users.atw.hu/wolf3d/) — the original game that inspired this project
- [Wikipedia — Ray casting](https://en.wikipedia.org/wiki/Ray_casting) — general overview of the technique
### AI Usage
 
AI was used at two stages of the project:
 
- **Learning phase** — to understand the core concepts behind ray-casting (DDA algorithm, camera plane, wall distance calculation, texture mapping) and to get an overview of how to structure the implementation before diving into the code.
- **Debugging phase** — toward the end of the project, to help investigate unexpected behaviors (rendering glitches, edge cases in map parsing, collision logic) that were difficult to trace manually.
All AI-generated explanations were reviewed, tested, and validated by the team before being integrated into the project.
