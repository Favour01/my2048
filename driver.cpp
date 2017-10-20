/**********************
* Favour Okereke-Mba
* COMP11
* Homework 7
**********************/
#include <iostream>
#include <string>
#include "brain.h"

using namespace std;

int main()
{
	int size, redo = 1;
	char choice;
	bool fail = false;
	string name;
	Brain game;

	cout <<"Lets play a game of 2048.\n"
		 <<"Instructions:\n"
		 <<"w for up\n"
		 <<"a for left\n"
		 <<"s for down\n"
		 <<"d for right\n"
		 <<"h to see the top-5 high scores\n"
		 <<"q to quit and record your current score in the high-score file\n";
	cout <<"What size of board do you want to play with:" << endl;
	cin >> size;

	//using set function to set size of board in brain class
	game.set_size(size);
	//calling run function in brain class which calls other functions.
	game.run();

	//while loop to make sure games runs till user looses.
	while(fail == false)
	{
		//do-wile loop to make sure user enters a valid character 
		do
		{
			cout << "What's your move:" << endl;
			cin >> choice;
			redo = game.determine_move(choice);
		}while(redo == -1);

		/*calling print_chighscore to print cirrent highscore
		  and players score.*/
		game.print_chighscore();

		//calling print function to print top five highscores
		game.print();

		//calling is_over function to check if game is over.
		fail = game.is_over();
	}

	//if conditon to print GAME OVER
	if ( choice != 'q')
		cout << "GAME OVER!\n";

	cout << "What is your name?" << endl;
	cin >> name;

	//setting name in brain class to users name
	game.set_name(name);
	/*calling newscore funstion in brain class which updates
	  highscore file and calls other functions.*/
	game.newscore(); 
	return 0;
}
