// GPRO-FW-Launcher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

int main()
{
	int input = -1;

	printf(" Pick a Game to play!!!\n");
	printf(" 1. Checkers\n");
	printf(" 2. TicTacToe\n");
	printf("Input: ");
	scanf("%d", &input);


	switch (input) {
	case 1:
		launchCheckers();
	case 2:
		launchTicTacToe();
	}
}
