#include "GPRO-FW-TWO.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
	while (true)
	{
		int input;
		cout << "Enter a number (0 to quit): ";
		cin >> input;

		if (input == 0)
		{
			break;
		}

		else
		{
			cout << input << " is " << oddOrEven(input) << endl;
		}
	}
}