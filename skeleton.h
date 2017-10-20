using namespace std;

#ifndef SKELETON_H_
#define SKELETON_H_

class Skeleton
{
private:
	//poiter used to create the 2D array that is used to play.
	int **board;

	//variable used to store the players choice of board size
	int size;

	/*variable used to save players score as game goes on.
	This attribute has no set function because there is no need to
	set the score. The score is computred as game goes on*/
	int score;

public:
	//constructor
	Skeleton();

	//destructor
	~Skeleton();

	/*move functions move according to the players choice and
	updates the players score after each move*/
	void movew();
	void movea();
	void moves();
	void moved();

	/*Corresponding add functions for move functions*/
	int addw();
	int adda();
	int adds();
	int addd();

	//set and get functions
	void set_size(int);
	int get_size();
	int get_score();

	/*the populate function popultes the 2D board with X and puts
	  in the first 2's randomly*/ 
	void populate();

	/*the print function prints the 2D board*/
	void print();

	/*the random function places either a 2 or 4 randomly in the 2D
	 board*/
	void random();

	/*The create_board function creates the 2D array*/
	void create_board();

	/*the game_over function loops through the 2D array and checks if
	 the board is full with no move to make. Returns a 1 for game over
	 and a 0 for game goes on*/
	int game_over();
};

#endif
