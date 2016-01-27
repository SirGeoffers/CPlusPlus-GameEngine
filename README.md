# C++ Game Engine

Game State Manager
- Manages all game resources
- Handles multiple game states (Menu, Game, Options, etc)

Entity Component System
- An architectural pattern that allows greater flexibility in defining game objects
- Each Entity can contain a set of Components
- Components store information about the Entity, such as position, velocity, sprites, etc.
- Systems act on Enities that have the required Components for the System (Movement, Rendering, Collision).

All of the main files for the program can be found under the FEO directory.
I am using [SFML 2.2] (http://www.sfml-dev.org/) for this project.
