# Project 0 - Pokemon Pikachu

> This project is made entirely in english, all the comments, variables, functions, and source files are in english.

## Description

Pokemon Pikachu is a simple virtual pet game where the user can interact with a **Pikachu**. The user has a watts balance that is used to buy items from the shop, and give them to the Pikachu to increase its relationship level.
The Pikachu becomes angry if the user does not interact with it and its relationship level decreases.
The user can also play with the Pikachu to increase its relationship level and earn watts.

The game has the following features:

- **Relationship ASCII Art**: The game displays an ASCII art of Pikachu with different expressions, depending on the relationship level of the Pikachu.
- **Main Menu**: The user can navigate through the different options of the game.
- **Time**: Consult the time that has passed since the game started.
- **Watts**: Consult the user's watts balance.
- **Shop**: The user can buy items from the shop using their watts balance.
- **Pikachu**: The user can consult the relationship level of the Pikachu, and see all the items that the Pikachu has received.
- **Play**: The user can play with the Pikachu to increase its relationship level and earn watts.
- **Back**: Return to the main menu. If the user is in the main menu, the game will exit.

### Extra Credit

The game has the following extra features:

- Display an ASCII art of Pikachu eating a consumable item, when the user buys a consumable item from the shop.
- Display an ASCII art of Pikachu surprised, when the user beats Pikachu in the play option.
- Display an ASCII art of Pikachu happy, when Pikachu wins in the play option.

## Compiling and Running

### Compiling

This project has a `Makefile` that can be used to compile all the code. To compile the code, simply run the following command:

```bash
make
```

This will generate the executable `bin/pokemon.out` and the `build` folder, which contains all the object files generated during the compilation process.

**Disclaimer**: The `Makefile` uses the `gcc` compiler to compile the code. To use a different compiler, modify the `CC` variable in the `Makefile` to the desired compiler.

### Running

After compiling the code, you can run the executable `bin/pokemon.out` by running the following command:

```bash
./bin/pokemon.out
```

### Cleaning

To clean all the generated files, run the following command:

```bash
make clean
```

## Laboratory group

- Luis Isea [@lmisea](https://github.com/lmisea) (19-10175).
- Jesús Prieto [@dev-jlpt18](https://github.com/dev-jlpt18) (19-10211).
