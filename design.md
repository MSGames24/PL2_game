Design ideas:
- Player is spawned in the middle of the map. Gem, magic apples and monsters are spawned in random locations in random number (Gem is always single). 
- Player and monsters have strength and energy. Energy is consumed after each turn. Strength is used to determine who wins in a battle. When energy falls to zero, entity dies.
- Player can be moved in one direction per one turn. Monsters move in random direction every turn unless they see a player nearby. In that case, they'll attack a player.
- When a player eats a gem, the door to the next level is opened. Each level's map is randomly generated and increases in size when going to the new level.

Classes:
**Position**
Holds the coordinates (int x and y values) of all objects. Can be accessed with corresponding setters and getters. Two instances can be compared.
**GameObject**
Holds the position and the symbol of the objects. The position and the symbol can be accessed with getters. However, symbol can't be changed and position can be changed only once. It's a parent class for all the objects in the game.
**MagicApple**
Holds the value that gets added to strength after interaction. I's a static object (can't be moved). It's a child class of GameObject.
**Gem**
It's a child class of GameObject. Can be interacted by player to open a door and increase the strength.
**Entity**
it's a parent class for moving objects, like monsters and player. Holds the strength and the energy of an object. Has all the corresponding setters and getters to change the properties.
**Player**
It's a child class of GameObject and Entity. It overrides the setters of the position so that the position can be changed.
**Monster**
It's a child class of GameObject and Entity. It overrides the setters of the position so that the position can be changed. Additionally, it can interact with a player (attack).
**Map**
The main purpose of the class is to create and store the map of one level. The map is created based on the number of the level. It always has 1-symbol-thick wall around and some random walls inside. It also stores the wight and the width of the map, as well as the position of the door to the next level (The door is generated in Map, not in the game, like most of the objects.
**Logger**
The class to keep track of game events. It's basically a vector of strings, with written methods to acess them properly. 
**Game**
The main class that controls everything that happens in the game. It has all the above-mentioned classes as properties. Monsters, gems and magic apples are stored in vectors because their number is changing during the game. It has only one public method, so to start a game, you only need to create an instance and apply method .start() to it.
**Settings**
The class that has only static variables, which are used to control most of the operations in all the classes. The game difficulty can be altered with this class.