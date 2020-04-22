
#include <stdio.h>
#include <stdlib.h>


//-----------------------------------------------------------------------------
// DECLARATIONS

#define GS_TICTACTOE_PLAYERS					2
#define GS_TICTACTOE_BOARD_WIDTH				3
#define GS_TICTACTOE_BOARD_HEIGHT				3

enum gs_tictactoe_space_state
{
	// invalid space state
	gs_tictactoe_space_invalid = -1,

	// states visible to both players
	gs_tictactoe_space_open,	// space is open
	gs_tictactoe_space_o,		// space is taken by O player
	gs_tictactoe_space_x,		// space is taken by X player
};
#ifndef __cplusplus
typedef		enum gs_tictactoe_space_state		gs_tictactoe_space_state;
#endif	// !__cplusplus

// tic-tac-toe game state
typedef		unsigned char						gs_tictactoe_index;
typedef		gs_tictactoe_space_state			gs_tictactoe[GS_TICTACTOE_BOARD_WIDTH][GS_TICTACTOE_BOARD_HEIGHT];


#define	GS_VALIDATE_COORDINATE(x,y,w,h)			(x < w && y < h)
#define GS_TICTACTOE_VALID(x,y)					GS_VALIDATE_COORDINATE(x,y,GS_TICTACTOE_BOARD_WIDTH,GS_TICTACTOE_BOARD_HEIGHT)


inline gs_tictactoe_space_state gs_tictactoe_getSpaceState(gs_tictactoe const game, gs_tictactoe_index const xpos, gs_tictactoe_index const ypos)
{
	if (GS_TICTACTOE_VALID(xpos, ypos))
		return (game[xpos][ypos]);
	return gs_tictactoe_space_invalid;
}

inline gs_tictactoe_space_state gs_tictactoe_setSpaceState(gs_tictactoe game, gs_tictactoe_space_state const state, gs_tictactoe_index const xpos, gs_tictactoe_index const ypos)
{
	if (GS_TICTACTOE_VALID(xpos, ypos))
		return (game[xpos][ypos] = state);
	return gs_tictactoe_space_invalid;
}

inline gs_tictactoe_index gs_tictactoe_reset(gs_tictactoe game)
{
	gs_tictactoe_index xpos, ypos, total;
	for (xpos = 0; xpos < GS_TICTACTOE_BOARD_WIDTH; ++xpos)
		for (ypos = 0; ypos < GS_TICTACTOE_BOARD_HEIGHT; ++ypos)
			game[xpos][ypos] = gs_tictactoe_space_open;
	total = (xpos * ypos);
	return total;
}


//-----------------------------------------------------------------------------
// DEFINITIONS

char TwoPlayerCreator(gs_tictactoe game, int i, int j)
{
	char XandO;
	if (gs_tictactoe_getSpaceState(game, i, j) == 1)
	{
		XandO = 'X';
	}
	else if (gs_tictactoe_getSpaceState(game, i, j) == 2)
	{
		XandO = 'O';
	}
	else
	{
		XandO = ' ';
	}
	return XandO;
}

void boardCreation(gs_tictactoe game)
{
	int c;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("|   %c", TwoPlayerCreator(game, i, j));
		}
		printf("\n-------------------\nX: "); 
	}
}

char claimVictory(gs_tictactoe game)
{
	for (int i = 0; i < 3; i++)
	{
		//check rows
		if (gs_tictactoe_getSpaceState(game, i, 0) != 0 && gs_tictactoe_getSpaceState(game, i, 0) == gs_tictactoe_getSpaceState(game, i, 1) && gs_tictactoe_getSpaceState(game, i, 1) == gs_tictactoe_getSpaceState(game, i, 2))
		{
			return 1;
		}
		//check columns
		else if (gs_tictactoe_getSpaceState(game, 0, i) != 0 && gs_tictactoe_getSpaceState(game, 0, i) == gs_tictactoe_getSpaceState(game, 1, i) && gs_tictactoe_getSpaceState(game, 1, i) == gs_tictactoe_getSpaceState(game, 2, i))
		{
			return 1;
		}
	}
	//check diagonals
	if (gs_tictactoe_getSpaceState(game, 0, 0) != 0 && gs_tictactoe_getSpaceState(game, 0, 0) == gs_tictactoe_getSpaceState(game, 1, 1) && gs_tictactoe_getSpaceState(game, 1, 1) == gs_tictactoe_getSpaceState(game, 2, 2))
	{
		return 1;
	}
	else if (gs_tictactoe_getSpaceState(game, 0, 2) != 0 && gs_tictactoe_getSpaceState(game, 0, 2) == gs_tictactoe_getSpaceState(game, 1, 1) && gs_tictactoe_getSpaceState(game, 1, 1) == gs_tictactoe_getSpaceState(game, 2, 0))
	{
		return 1;
	}

	return 0;
}

int launchTicTacToe()
{
	gs_tictactoe game = { 0 };

	gs_tictactoe_reset(game);

	char turn = 'X';
	int x, y, rounds = 1;

	printf("Round %d\n", rounds);

	boardCreation(game);

	while (rounds <= 9 && claimVictory(game) == 0)
	{
		printf("Player %c turn", turn);

		printf("Enter a row:");
		scanf("%d", &x);

		printf("Eneter a column:");
		scanf("%d", &y);

		if (turn == 'X' && gs_tictactoe_getSpaceState(game, x, y) == 0)
		{
			gs_tictactoe_setSpaceState(game, gs_tictactoe_space_x, x, y);
			turn = 'O';
			rounds++;
		}
		else if (turn == 'O' && gs_tictactoe_getSpaceState(game, x, y) == 0)
		{
			gs_tictactoe_setSpaceState(game, gs_tictactoe_space_o, x, y);
			turn = 'X';
			rounds++;
		}
		else
		{
			printf( "ERROR! ERROR! I AM ERROR! (haha funny Zelda 2 Joke, but still...)" );
		}
		printf("Round %d\n", rounds);
		boardCreation(game);
	}

	if (turn == 'X')
	{
		printf( "Player 1 is the Winner!");
	}
	else if (turn == 'O')
	{
		printf("Player 2 is the winner!");
	}
	else
	{
		printf("GIDDYUP AND DRAW!");
	}

	gs_tictactoe_setSpaceState(game, gs_tictactoe_space_x, 0, 0);

	return 0;
}


//-----------------