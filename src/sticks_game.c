#include "sticks_game.h"

int main()
{
	int red = M, green = M, yellow = M;
	int sticks = red + green + yellow;
	int turn = 0;	/* turn == 0 -> computer, turn == 1 -> player */
	int computer;
	int valid[] = {0, 0, 0, 0, 0, 0}, v = 0;

	system("clear");
	display_sticks(red, green, yellow);

	while (sticks != 0)
	{
		/* computer's turn */
		if (turn == 0)
		{
			usleep(1000000);
			printf("\n\n--COMPUTER'S TURN--\n");
			computer = minimax(red, green, yellow, sticks, turn);

			/* remove the right amount of sticks based on what the MINIMAX algorithm returned */
			if (computer == 1 || computer == -1)
			{
				red = red - 1;
				sticks = sticks - 1;
			}
			else if (computer == 2 || computer == -2)
			{
				green = green - 1;
				sticks = sticks - 1;
			}
			else if (computer == 3 || computer == -3)
			{
				yellow = yellow - 1;
				sticks = sticks - 1;
			}
			else if (computer == 4 || computer == -4)
			{
				red = red - K1;
				sticks = sticks - K1;
			}
			else if (computer == 5 || computer == -5)
			{
				green = green - K2;
				sticks = sticks - K2;
			}
			else if (computer == 6 || computer == -6)
			{
				yellow = yellow - K3;
				sticks = sticks - K3;
			}

			display_sticks(red, green, yellow);
			turn = 1;
		}
		/* player's turn */
		else
		{
			printf("\n\n--YOUR TURN--\n");
			int choice = 0;

			/* print the player's options and check if something valid was chosen */
			while (choice < 1 || choice > 7 || valid[choice - 1] == 0)
			{
				printf("\nYour options are:\n\n");
				if (red >= 1)
				{
					valid[0] = 1;
					printf("1.Remove 1 x\033[1;31m | \033[0m\n");
				}
				if (green >= 1)
				{
					valid[1] = 1;
					printf("2.Remove 1 x\033[1;32m | \033[0m\n");
				}
				if (yellow >= 1)
				{
					valid[2] = 1;
					printf("3.Remove 1 x\033[1;33m | \033[0m\n");
				}
				if (red >= K1)
				{
					valid[3] = 1;
					printf("4.Remove %d x\033[1;31m | \033[0m\n", K1);
				}
				if (green >= K2)
				{
					valid[4] = 1;
					printf("5.Remove %d x\033[1;32m | \033[0m\n", K2);
				}
				if (yellow >= K3)
				{
					valid[5] = 1;
					printf("6.Remove %d x\033[1;33m | \033[0m\n", K3);
				}

				printf("7.See the remaining sticks");
				printf("\n\nChoose your move: ");
				scanf("%d", &choice);

				if (choice == 7)
				{
					display_sticks(red, green, yellow);
					choice = -1;
				}
			}

			/* turn valid moves back to 0 to reevaluate them on the next player's turn */
			v = 0;

			for (v; v < 6; v++)
				valid[v] = 0;

			/* remove the chosen amount of sticks, print them and change turn */
			if (choice == 1)
			{
				red = red - 1;
				sticks = sticks - 1;
			}
			else if (choice == 2)
			{
				green = green - 1;
				sticks = sticks - 1;
			}
			else if (choice == 3)
			{
				yellow = yellow - 1;
				sticks = sticks - 1;
			}
			else if (choice == 4)
			{
				red = red - K1;
				sticks = sticks - K1;
			}
			else if (choice == 5)
			{
				green = green - K2;
				sticks = sticks - K2;
			}
			else
			{
				yellow = yellow - K3;
				sticks = sticks - K3;
			}

			//system("clear");
			printf("\n(After your move)\n");
			display_sticks(red, green, yellow);

			turn = 0;
		}
	}

	/* at the end of the game check who's winner */
	if (turn == 0)
		printf("\nWELL PLAYED, YOU BEAT ME THIS TIME!\n\n");
	else
		printf("\n      GAME OVER      \nBetter luck next time\n\n");
	return 0;
}

void display_sticks(int red, int green, int yellow)
{
	printf("\nSticks remaining:\n");
	if (red == 0 && green == 0 && yellow == 0)
		printf("\n(Nothing left on the table)");

	/* prints red sticks */
	for (int r = 0; r < red; r++)
	{
		printf("\033[1;31m");
  		printf("| ");
  		printf("\033[0m");
	}

	printf("\n");

	/* prints green sticks */
	for (int g = 0; g < green; g++)
	{
		printf("\033[1;32m");
  		printf("| ");
  		printf("\033[0m");
	}

	printf("\n");

	/* prints yellow sticks */
	for (int y = 0; y < yellow; y++)
	{
		printf("\033[1;33m");
  		printf("| ");
  		printf("\033[0m");
	}

	printf("\n");
}

int minimax(int red ,int green ,int yellow ,int sticks, int turn)
{
	if ((sticks == 0) && (turn == 0))
		return -1;	/* player (MIN) wins */
	else if ((sticks == 0) && (turn == 1))
		return 1;	/* computer (MAX) wins */
	else if ((sticks > 0) && (turn == 0))
	{
		int necessary; /* for when the computer has to do a wrong move */

		if (red >= 1)
		{
			necessary = minimax(red-1, green, yellow, sticks-1, 1);

			if (necessary > 0)
				return 1;
		}
		if (green >= 1)
		{
			necessary = minimax(red, green-1, yellow, sticks-1, 1);

			if (necessary > 0)
				return 2;
		}
		if (yellow >= 1)
		{
			necessary = minimax(red, green, yellow-1, sticks-1, 1);

			if (necessary > 0)
				return 3;
		}
		if (red >= K1)
		{
			necessary = minimax(red-K1, green, yellow, sticks-K1, 1);

			if (necessary > 0)
				return 4;
		}
		if (green >= K2)
		{
			necessary = minimax(red, green-K2, yellow, sticks-K2, 1);

			if (necessary > 0)
				return 5;
		}
		if (yellow >= K3)
		{
			necessary = minimax(red, green, yellow-K3, sticks-K3, 1);

			if (necessary > 0)
				return 6;
		}

		return necessary;	/* computer loses */
	}
	else if ((sticks > 0) && (turn == 1))
	{
		if ((red >= 1) && (minimax(red-1, green, yellow, sticks-1, 0) < 0))
			return -1;
		if ((green >= 1) && (minimax(red, green-1, yellow, sticks-1, 0) < 0))
			return -2;
		if ((yellow >= 1) && (minimax(red, green, yellow-1, sticks-1, 0) < 0))
			return -3;
		if ((red >= K1) && (minimax(red-K1, green, yellow, sticks-K1, 0) < 0))
			return -4;
		if ((green >= K2) && (minimax(red, green-K2, yellow, sticks-K2, 0) < 0))
			return -5;
		if ((yellow >= K3) && (minimax(red, green, yellow-K3, sticks-K3, 0) < 0))
			return -6;
		
		return 1;	/* player loses */
	}
}
