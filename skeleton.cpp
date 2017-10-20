/**********************
* Favour Okereke-Mba
* COMP11
* Homework 7
**********************/
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "skeleton.h"


using namespace std;


//Default constructor
Skeleton::Skeleton()
{
	board = NULL;
	size = 4;
	score = 0;

}

//Default destructor
Skeleton::~Skeleton()
{
	if(board != NULL)
	{
		for(int i = 0; i < size; i++)
			delete[] board[i];
		delete []board;
	}
}

/*Function: movew
  Returns: Void function
  Paremeters: Nothing 
  Does: Moves everything up
  		Calls up add function (addw)
  		calls random() function
*/
void Skeleton::movew()
{
	int k, ran, c = 0;
    for(int i = 0; i < size; i++)
    {
        if (board[0][i] != 1)
            k = 1;
        else
            k = 0;
 
        for(int j = 1; j < size; j++)
        {
            if (board[j][i] == 1)
                continue;
            else if((board[j][i] != 1) && ( j == k))
                k++;
            else if (board[j][i] != 1)
            {
                board[k][i] = board[j][i];
                board[j][i] = 1;
                k++;
                c++;
            }
        }
    }
    //calling up add function
    ran = addw();
    if ( c > 0 || ran == 1)
    	random();

	return;
}

/*Function: addw
  Returns: int to determine if two squares were added
  Paremeters: nothing 
  Does: After the move up function moves, it calls the add function
        to add squares that are equal and next to each other. The 
        add function returns a 1 if two squares were added and a 0
        if none were added.
*/
int Skeleton::addw()
{
	int c = 0;
	for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if ((board[j][i] == board[j + 1][i]) && (board[j][i] != 1))
            {
                board[j][i] = board[j][i] + board[j + 1][i];
                c++;
                score = score + board[j][i];
                board[j + 1][i] = 1;
                //moving squares to fill up empty spot after addition 
                for (int a = j + 1; a < size - 1; a++)
                {
                    board[a][i] = board[a + 1][i];
                    board[a + 1][i] = 1;
                }
            }
            else
                continue;
        }
    }
    if (c > 0)
    	return 1;
    else 
		return 0;
}

/*Function: movea
  Returns: Void function
  Paremeters: Nothing 
  Does: Moves everything to the left
  		Calls left add function (adda)
  		calls random() function
*/
void Skeleton::movea()
{
	int k, ran, c = 0;
    for(int i = 0; i < size; i++)
    {
        if (board[i][0] != 1)
            k = 1;
        else
            k = 0;
        
        for(int j = 1; j < size; j++)
        {
            if (board[i][j] == 1)
                continue;
            else if((board[i][j] != 1) && ( j == k))
                k++;
            else if (board[i][j] != 1)
            {
                board[i][k] = board[i][j];
                board[i][j] = 1;
                k++;
                c++;
            }
        }
    }

    ran = adda();
    if (c > 0 || ran == 1)
    	random();
    
	return;
}

/*Function: adda
  Returns: int to determine if two squares were added
  Paremeters: nothing 
  Does: After the move left function moves, it calls the add function
        to add squares that are equal and next to each other. The 
        add function returns a 1 if two squares were added and a 0
        if none were added.
*/
int Skeleton::adda()
{
	int c = 0;
	for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if ((board[i][j] == board[i][j + 1]) && (board[i][j] != 1))
            {
                board[i][j] = board[i][j] + board[i][j + 1];
                c++;
                score = score + board[i][j];
                board[i][j + 1] = 1;
                //moving squares to fill up empty spot after addition
                for (int a = j + 1; a < size - 1; a++)
                {
                    board[i][a] = board[i][a + 1];
                    board[i][a + 1] = 1;
                }
            }
            else
                continue;
        }
    }
    if ( c > 0)
    	return 1;
    else
    	return 0;
}

/*Function: moves
  Returns: Void function
  Paremeters: Nothing 
  Does: Moves everything down
  		Calls down add function (adds)
  		calls random() function
*/
void Skeleton::moves()
{
	int k, ran, c  = 0;
    for(int i = 0; i < size; i++)
    {
        if (board[size -1][i] != 1)
            k = size - 2;
        else
            k = size - 1;
        
        for(int j = size - 2; j >= 0; j--)
        {
            if (board[j][i] == 1)
                continue;
            else if((board[j][i] != 1) && ( j == k))
                k--;
            else if (board[j][i] != 1)
            {
                board[k][i] = board[j][i];
                board[j][i] = 1;
                k--;
                c++;
            }
        }
    }

    ran = adds();
    if (c > 0 || ran == 1)
    	random();
    
	return;
}

/*Function: adds
  Returns: int to determine if two squares were added
  Paremeters: nothing 
  Does: After the move down function moves, it calls the add function
        to add squares that are equal and next to each other. The 
        add function returns a 1 if two squares were added and a 0
        if none were added.
*/
int Skeleton::adds()
{
	int c = 0;
	for (int i = 0; i < size; i++)
    {
        for (int j = size -1; j >= 1; j--)
        {
            if ((board[j][i] == board[j - 1][i]) && (board[j][i] != 1))
            {
                board[j][i] = board[j][i] + board[j - 1][i];
                c++;
                score = score + board[j][i];
                board[j - 1][i] = 1;
                //moving squares to fill up empty spot after addition
                for (int a = j - 1; a >= 1; a--)
                {
                    board[a][i] = board[a - 1][i];
                    board[a - 1][i] = 1;
                }
            }
            else
                continue;
        }
    }
    if ( c > 0)
    	return 1;
    else
    	return 0;
}

/*Function: moved
  Returns: Void function
  Paremeters: Nothing 
  Does: Moves everything to the right
  		Calls right add function (adds)
  		calls random() function
*/
void Skeleton::moved()
{
	int k, ran, c = 0;
    for(int i = 0; i < size; i++)
    {
        if (board[i][size -1] != 1)
            k = size - 2;
        else
            k = size - 1;
        
        for(int j = size - 2; j >= 0; j--)
        {
            if (board[i][j] == 1)
                continue;
            else if((board[i][j] != 1) && ( j == k))
                k--;
            else if (board[i][j] != 1)
            {
                board[i][k] = board[i][j];
                board[i][j] = 1;
                k--;
                c++;
            }
        }
    }
    
    ran = addd();
    if (c > 0 || ran == 1)
		random();
	
	return;
}

/*Function: addd
  Returns: int to determine if two squares were added
  Paremeters: nothing 
  Does: After the move right function moves, it calls the add function
        to add squares that are equal and next to each other. The 
        add function returns a 1 if two squares were added and a 0
        if none were added.
*/
int Skeleton::addd()
{
	int c = 0;
	for (int i = 0; i < size; i++)
    {
        for (int j = size -1; j >=0; j--)
        {
            if ((board[i][j] == board[i][j - 1]) && (board[i][j] != 1))
            {
                board[i][j] = board[i][j] + board[i][j-1];
                c++;
                score = score + board[i][j];
                board[i][j-1] = 1;
                //moving squares to fill up empty spot after addition
                for (int a = j-1; a >= 1; a--)
                {
                    board[i][a] = board[i][a - 1];
                    board[i][a - 1] = 1;
                }
            }
            else
                continue;
        }
    }
    if (c > 0)
    	return 1;
    else
    	return 0;
}

/*Function: set_size
  Returns: nothing
  Paremeters: users choice for size of board
  Does: Sets size to users choice and makes sure the user
  		does not pick a board that is too big or small.
*/
void Skeleton::set_size(int nsize)
{
	if(nsize <= 1 || nsize >=20)
	{
		cout << "Not acceptable size.\n"
		     << "Size of board set to a default of 4.\n";
		size = 4; 
	}
	else
		size = nsize;

	return;
}

/*Function: get_size
  Returns: returns the size of the board.
  Paremeters: nothing
  Does:returns the size of the board.
*/
int Skeleton::get_size()
{
	return size;
}

/*Function: get_score
  Returns: returns the users current score 
  Paremeters: nothing 
  Does: returns the users current score 
*/
int Skeleton::get_score()
{
	return score;
}

/*Function: populate
  Returns: nothing
  Paremeters: nothing 
  Does: Populates the board with 1's and places 2
  		2's randomly on the board.
*/
void Skeleton::populate()
{
	for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            board[i][j] = 1;

    int count = 0;
    srand(time(NULL));
    while(count < 2)
    {
        int a = rand()% size;
        int j = rand()% size;
        if (board[a][j] == 1)
        {
            board[a][j] = 2;
            count++;
        }
    }
	return;
}

/*Function: print
  Returns: nothing
  Paremeters: noting
  Does: Prints the 2d array with X's where there are 1's
        and prints every other number.
*/
void Skeleton::print()
{
	for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
        	if(board[i][j] == 1)
        		cout << "X" << "\t";
        	else
        		cout << board[i][j] << "\t";
        }
        cout << endl;
    }
	return;
}

/*Function: random
  Returns: nothing 
  Paremeters: nothing 
  Does: places either a 2 or a 4 randomly on the edge of the baord.
*/
void Skeleton::random()
{
	int redo = -1, i, j, n, num;
	srand(time(NULL));
    n = 1 + rand()% 10;
    if(n == 10)
    	num = 4;
    else
    	num = 2;
	do
	{
    	i = rand()% size;
    	if (i == 0 || i == size - 1)
    		j = rand()% size;
    	if (i > 0 && i < size - 1)
    	{
    		n = rand()% 2;
    		if (n == 0)
    			j = 0;
    		else if (n == 1)
    			j = size - 1;
    	}

    	if (board[i][j] == 1)
    	{
    		board[i][j] = num;
    		redo = 1;
    	}
    	else
    		redo = -1;

	}while(redo == -1);
	return;
}

/*Function: create_board
  Returns: nothing
  Paremeters: nothing
  Does: creates the 2d array (board)
*/
void Skeleton::create_board()
{
	board = new int*[size];
	for (int i = 0; i < size; i++)
		board[i] = new int[size];
	return;
}

/*Function: game_over
  Returns: returns 1 if game is over and 0 if not
  Paremeters: nothing 
  Does: Loops through the board to see if it is full with
  		no possible move.
*/
int Skeleton::game_over()
{
	int countx = 0;
	//looping through the board to check if it is full
	
	for(int i = 0; i < size; i++)
    {
    	for(int j = 0; j < size; j++)
    	{
    		if(board[i][j] > 1)
    			countx++;
    	}
    }

    //if statement to check for possible moves if the board is full
    if (countx == (size * size))
    {
    	//loopin gthrough the biard checkinh for possible moves=.
    	for(int i = 0; i < size; i++)
    	{
    		for(int j = 0; j < size - 1; j++)
    		{
    			if(board[i][j] == board[i][j + 1])
    				return 0;
    			if(board[j][i] == board[j + 1][i])
    				return 0;
    		}
    	}
    	return 1;
	}
	else
		return 0;
}
