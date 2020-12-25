/* Turtle
Fall 2018
Mikita Popel */
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// This function makes the Turtle Change direction
int changeDirection(int changeDirection, int direction){
	if (changeDirection == 3)
	{
		direction = direction + 1;
		if (direction == 4)
			direction = 0;
	}
	if (changeDirection == 4)
	{
		direction = direction - 1;
			if (direction == -1)
				direction = 3;
	}
	return direction;
}

// This function moves the Turtle in the X direction
int moveTurtlex(int direction, int turtlex){
	if (direction == 0){
		turtlex = turtlex + 1;
		if (turtlex > 24)
			turtlex = 24;
	}
	if (direction == 2){
		turtlex = turtlex - 1;
		if (turtlex < 0)
			turtlex = 0;
	}
	return turtlex;
}

// This function moves the Turtle in the Y direction
int moveTurtley(int direction, int turtley){
	if (direction == 1){
		turtley = turtley + 1;
		if (turtley > 24)
			turtley = 24;
	}
	if (direction == 3){
		turtley = turtley - 1;
		if (turtley < 0)
			turtley = 0;
	}
	return turtley;
	
}

// This function prints the board to the terminal
void printBoard(int board[25][25]){
	
	printf("                        1                   2\n");
	printf("    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4\n");
	printf("   +-------------------------------------------------+\n");
	for (int j = 0; j < 25; j++){
		printf(" %2d|", j);
		for (int i = 0; i < 25; i++){
			if (board[j][i]==0)
				printf(" ");
			if (board[j][i]==1)
				printf("*");
			if (i < 24){
				printf(" ");
			}
		}
		printf("|%-2d\n", j);
	}
	printf("   +-------------------------------------------------+\n");
	printf("    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4\n");
	printf("                        1                   2\n");	
	return;
}


// This program reads in the commands from a .dat file and behaves accordingly to the commands that are entered by the user
int main(void){
	printf(" EGRE245 Proj. #6 - M. Popel\n");
	int board[25][25] = {0};
	int i, j, cmd, turtlex, turtley, direction, move;
	bool pendown = 0;
	direction = 0;
	turtlex = 0;
	turtley = 0;
	cmd = 0;
	
	while (cmd != 9){									//typing nine ends the loop and stops reading in commands, so did not think it was necessary to make its own case
		scanf("%d", &cmd);
		switch (cmd) {
			case 1:										//pen up command
			pendown = 0;
			break;
			
			case 2:										//pen down command
			pendown = 1;
			board[turtley][turtlex] = 1;
			break;
			
			case 3:										//turn right 90 degrees command
			direction = changeDirection(cmd, direction);
			break;
			
			case 4:										//turn left 90 degrees command
			direction = changeDirection(cmd, direction);
			break;
			
			case 5:										//move forward x spaces command
			scanf("%d", &move);
			for(i = 0; i < move; i++){
				turtlex = moveTurtlex(direction, turtlex);
				turtley = moveTurtley(direction, turtley);
				if (pendown)
					board[turtley][turtlex] = 1;
			}
			break;
			
			case 6:										//output the board command
			printBoard(board);
			break;
		}
	}
	
	
	
	
	return 0;
}