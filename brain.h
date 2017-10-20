/**********************
* Favour Okereke-Mba
* COMP11
* Homework 7
**********************/
#include <iostream>
#include <fstream>
#include <string>
//includes skeletons class in brain
#include "skeleton.h"

using namespace std;

#ifndef BRAIN_H_
#define BRAIN_H_

const char FILENAME[14] = "highscore.txt";
class Brain
{
private:
	//variable used to save players score as game goes on.
	int score;

	//variable used to store the players choice of board size
	int size;

	/*variable that holds highscore from previous games. It has no
	  set function because the highscore should not be manipuated*/
	int highscore;

	/*dynamic array to hold scores read in from the highscore file*/
	int *score_ray;

	//object of the skeleton class
	Skeleton board;

	/*dynamic array to hold names read in from the highscore file*/
	string *names;

    //variable to hold users choice of move.
	char user_input;
	
	//variable used to hold players name.
	string name;

	//size for array that holds scores form highscore.txt
	int score_size;
	

public:
	//costructor
	Brain();

	//destructor
	~Brain();

	//set and get fuctions
	void set_size(int);
	//int get_size();
	void set_name(string);
	int get_highscore();
	//void set_score(int);
	int get_score();

	/*the run function is called from int main and calls various
	  various functions associated with the skeleton class because the
	  skeleton classs will not be included in main*/
	void run();

	/*the print function calls the print function in the skeleton class
	  to print ht 2D game array to the screem*/
	void print();

	/*the dtermine_move function takes in the users choice a,w,s,d,h or q
	  and class functions from skeleton to implement the players choice 
	  based on the players choice. It returns -1 if the user selects an 
	  invalid input*/
	int determine_move(char);

	/*the print_highscore function prints the top five highscores and 
	  corresponding names to the screen if the user asks for it*/
	void print_highscore();

	/*the print_chighscore function prints the top score from the highscore
	  file along with the players current score at the top of the 2D game 
	  board*/
	void print_chighscore();

	/*the is_over function checks if the game is over by calling the 
	  game_over function from the skeleton class. It returns true or false*/
	bool is_over();

	/*the open_file function is called by the run function at the beginning
	  of the game and it opens the highscore and reads in the highscores and
	  names to dynamic arrays or creates the file if it doesn't exist*/
	void open_file();

	/*the newscore function checks if the players current score is the new
	  highscore and lets them know if it is. It also calls the update_file
	  function*/
	void newscore();

	/*Places the users score and name in the appropriate positon in the 
	  highscore file*/
	void update_file();
};

#endif
