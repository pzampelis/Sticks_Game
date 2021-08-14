#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define M  5    /* The default number of sticks for every color */
#define K1 3    /* The special number of red sticks that can be removed */
#define K2 2    /* The special number of green sticks that can be removed */
#define K3 2    /* The special number of yellow sticks that can be removed */

void display_sticks(int red, int green, int yellow);
int minimax(int red ,int green ,int yellow ,int sticks, int turn);
