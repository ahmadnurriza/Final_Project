	/*
		Note :
		1	= the road that has been passed
		0	= roads
		2	= walls
	*/
#include<stdio.h>

int maze[13][29]={													
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,2},
	{2,0,2,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,2,0,0,0,2,0,0,0,2,0,2},
	{2,0,0,0,2,2,0,2,2,2,2,2,0,2,0,2,2,0,2,0,2,0,2,2,2,0,0,0,2},
	{2,0,2,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,2,0,0,0,2,0,2,0,2,2,2},
	{2,0,2,0,0,2,2,2,2,0,2,0,2,2,0,2,2,0,0,0,2,0,0,0,2,0,0,0,2},
	{2,2,2,2,0,0,2,0,2,0,0,0,0,0,0,2,0,0,2,2,2,0,2,0,2,0,2,0,2},
	{2,2,0,0,0,2,0,0,2,2,0,2,2,2,2,2,2,2,2,0,0,0,2,2,2,2,2,0,2},
	{2,0,0,2,2,2,2,0,0,2,0,2,0,0,0,2,2,0,0,0,2,2,2,0,2,0,2,0,2},
	{2,2,0,0,0,0,0,2,0,0,0,2,2,2,0,0,0,2,2,0,2,0,0,0,2,0,0,0,2},
	{2,0,0,2,0,2,0,2,2,2,0,2,0,0,0,2,0,0,2,0,0,0,2,0,2,0,2,0,2},
	{2,2,2,2,0,2,0,2,0,0,0,0,0,2,0,2,2,0,2,0,2,0,2,2,2,0,2,0,2},
	{2,0,0,0,0,2,0,0,0,2,0,2,0,0,0,0,0,0,2,0,2,0,0,0,0,0,2,0,2},
	{2,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	};

int ways(int row, int column);
	
int copy[13][29];	
int i, j, finish, start;
int a=1, b=1;
	
int main()
{
	printf("\n\n");

	for(i=0; i<13; i++)											// to print maze
	{
		printf("\t\t");
		for(j=0; j<29; j++)
		{
			if(maze[i][j]==0)
			{
				printf("  ");
			}
			else
			{
				printf("%c%c",215,215);
			}
		}
		printf("\n");
	}
	
	printf("\n");												// make copy and change all of value to 0
	
	for(j=0; j<29; j++)											// to find coordinat finish and start
	{
		if(maze[0][j]==0)
		{
			finish=j;
		}
		
		if(maze[12][j]==0)
		{
			start = j;
		}
	}
	printf("\t\tcoordinate start	= (%d,12)\n\t\tcoordinate finish	= (%d,0)\n\n",start,finish);		// to print coordinate start and finish
	
	for(i=0; i<13; i++)											// to print copy of maze using 0
	{
		printf("\t\t");
		for(j=0; j<29; j++)
		{
			copy[i][j]=0;
			printf("%2d",copy[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	if(ways(0,finish))											// to find ways with compare array of ways and maze
	{
		for(i=0; i<13; i++)
		{
			for(j=0; j<29; j++)
			{
				if(copy[i][j]==1 && maze[i][j]==0)
				{
					maze[i][j] = copy[i][j];
				}
			}

		}
	}
	printf("\n");
	
	for(i=0; i<13; i++)											// to print maze after compare with copy using number
	{
		printf("\t\t");
		for(j=0; j<29; j++)
		{
			printf("%2d",maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	for(i=0; i<13; i++)											// if there is value 0 in left or right side, program will print "Coordinate Input and Output Undefined"
	{
		if(maze[i][0] == 0 || maze[i][28] == 0 || maze[i][0] == 1 || maze[i][28] == 1)
		{
			printf("------------------------------Coordinat Input and Output Undefined-------------------------------------------------------");
			return 0;
		}
	}
	
	for(j=0; j<29; j++)											// to know how many output in maze. If maze has more than 1 output, the program will print "There are more than 1 Output"
	{
		if(maze[0][j]==0)
		{
			a++;
			if(a>1)
			{
				printf("---------------------------------There are more than 1 Output--------------------------------------------\n");
				return 0;
			}
		}
		
		if(maze[12][j]==0)									// to know how many input in maze. If maze has more than 1 input, the program will print "There are more than 1 Input"
		{
			b++;
			if(b>1)
			{
				printf("---------------------------------There are more than 1 Input--------------------------------------------\n");
				return 0;
			}

		}
	}
	
	if(maze[0][finish]==1)
	{	
		printf("\n");
		printf("---------------------------------The Maze Solution is--------------------------------------------\n\n");
		for(i=0; i<13; i++)											// to print maze wall using ASCII to shown wall
		{
			printf("\t\t");
			for(j=0; j<29; j++)
			{
				if(maze[i][j]!=0 && maze[i][j]!=1)
				{
					printf("%c%c",215,215);							// 215 is ASCII code to print wall
				}
				if(maze[i][j]==1)
				{
					printf("1 ");									// to print solution direction from start to finish
				}
				if(maze[i][j]==0)
				{
					printf("  ");
				}
			}
			printf("\n");
		}
	}
	else
	{
		printf("---------------------------------Paths is not found-------------------------------------------------");
	}	
}


int ways(int row, int column)
{
	for(j=0; j<29; j++)											// to determine where is coordinate of start 							
	{
		if(maze[12][j]==0)
		{
			start = j;
		}
	}
	
	if(row==12 && column==start)								// change value of start from 0 to 1
	{
		copy[row][column]=1;
		return 1;
	}
		
	if(0<=row<13 && 0<=column<29 && copy[row][column] == 0 && maze[row][column]==0)	
	{
	copy[row][column] = 1;
	if(ways(row+1, column))										// move to downward and give value 1
		return 1;
	if(ways(row, column-1))										// move to leftward and give value 1
		return 1;
	if(ways(row-1, column))										// move to upward and give value 1
		return 1;
	if(ways(row, column+1))										// move to rightward and give value 1
		return 1;
	copy[row][column] = 0;
		return 0;
	}
	return 0;

}	



