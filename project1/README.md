# Project 1 - Real Wizard Chess

### Contents

- [Project 1 - Real Wizard Chess](#project-1---real-wizard-chess)
    - [Contents](#contents)
  - [Introduction](#introduction)
  - [How to play](#how-to-play)
    - [Compiling](#compiling)
    - [Running](#running)
    - [Cleaning](#cleaning)
  - [Implementation](#implementation)
    - [Extra Credit](#extra-credit)
  - [Laboratory group](#laboratory-group)

## Introduction

Real Wizard Chess is a simple virtual chess game inspired by the _Harry Potter_ series, where the pieces can move by themselves and complain about the moves of the player.

## How to play

### Compiling

This project has a `Makefile` that can be used to compile all the code. To compile the code, simply run the following command:

```bash
make
```

This will generate the executable `bin/wizard_chess.out` and the `build` folder, which contains all the object files generated during the compilation process.

**Disclaimer**: The `Makefile` uses the `gcc` compiler to compile the code. To use a different compiler, modify the `CC` variable in the `Makefile` to the desired compiler.

### Running

After compiling the code, you can run the executable `bin/wizard_chess.out` by running the following command:

```bash
./bin/wizard_chess.out
```

It is highly recommended to run the game in a terminal sized to 68 characters wide by 36 characters high (68x36), as the chess board is designed to fit this dimension and the game may not display correctly in a smaller terminal.

### Cleaning

To clean all the generated files, run the following command:

```bash
make clean
```

## Implementation

The first design decision that was made was try to print first the board, then overwrite the board by adding the pieces and lastly override the board by adding the cursor. But we couldn't find a way to do this, so we decided to print the board, the pieces and the cursor at the same time. This was done by creating a 2D array of characters that represents the board and then allocating the pieces and the cursor in the array.

Another design decision was to create make the chessboard wider, because the original chessboard size suggested in the project statement was 33x33, but the horizontal characters '-' looked too small in comparison to the vertical characters '|'. So we decided to make the chessboard 67x34 (notation included), so the '-' characters would look more like the '|' characters.
Although the chessboard is 67x34, we suggest to run the game in a terminal sized to 68x36, so there is some extra space for the terminal borders.

### Extra Credit

1. **Chessboard notation**: The game displays the chessboard notation for each rank (row) and file (column) in the board. The notation is displayed in the right and bottom of the board, respectively.

## Laboratory group

- Luis Isea [@lmisea](https://github.com/lmisea) (19-10175).
- Jesús Prieto [@dev-jlpt18](https://github.com/dev-jlpt18) (19-10211).
