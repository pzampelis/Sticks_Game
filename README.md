# Sticks Game

## Description
This is a simple terminal game with sticks that uses the MINIMAX algorithm (which is also used in games like Tic-Tac-Toe, Chess, etc).
The game is played against the computer, having the computer decide the first move.
At first there are M red, M green and M yellow sticks on the table (M is defined as 5 in this implementation).
The possible moves for the computer and the player are to remove 1 red, 1 green or 1 yellow stick, or K1 red, K2 green or K3 yellow sticks (K1, K2 and K3 are defined as 3, 2 and 2 respectively in this implementation).
The user has to choose between options 1-6 (if possible to be executed) and can also use the option 7 as many times as he/she wants, to display the sticks that remain on the table at any time during the game.
The computer and the user play turn by turn until there are no more sticks on the table.
The winner is whoever manages to remove the last stick(s) from the table.

## Compilation & Run
The program can be simply compiled by using the command "gcc -o sticks_game sticks_game.c" (after you cd with your terminal to the sticks_game folder) and executed by using the "./sticks_game" command.
