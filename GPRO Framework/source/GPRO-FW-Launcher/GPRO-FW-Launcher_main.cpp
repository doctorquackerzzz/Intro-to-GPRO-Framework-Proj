#include "GPRO-FW-TWO.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
	int num = foo(1337);
	cout << num << endl;
	while (true)
	{
		int input;
		cout << "Pick a number, young one (type 0 if you're sick of it and wanna quit): ";
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