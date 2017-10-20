/**********************
* Favour Okereke-Mba
* COMP11
* Homework 7
**********************/
#include <iostream>
#include <fstream>
#include <string>
//includes skeletons class in brain
#include "brain.h"
#include "skeleton.h"

using namespace std;

//Default Constructor
Brain::Brain()
{
	score = 0;
	size = 4;
	highscore = 0;
	score_ray = NULL;
	names = NULL;
	user_input = ' ';
	score_size = 0;
	//FILENAME = "highscore.txt";
}

//Default Destructor
Brain::~Brain()
{
	if (score_ray != NULL)
		delete []score_ray;

	if (names != NULL)
		delete []names;
}

/*Function: set_size
  Returns: nothing 
  Paremeters: users choice of board size
  Does: sets size to users choice.
*/
void Brain::set_size(int nsize)
{
	size = nsize;
	return;
}

/*
int Brain::get_size()
{
	return size;
}
*/

/*Function: set_name
  Returns: nothing
  Paremeters: users name
  Does: sets name to users name.
*/
void Brain::set_name(string pname)
{
	name = pname;
	return;
}

/*Function: get_highscore
  Returns: returns current higschore
  Paremeters: nothing
  Does: returns current higschore
*/
int Brain::get_highscore()
{
	return highscore;
}

/*Function: get_score
  Returns: returns users score 
  Paremeters: nothing 
  Does: returns users score
*/
int Brain::get_score()
{
	return score;
}

/*Function: run
  Returns: nothing
  Paremeters: nothing 
  Does: Calls set_size, create_board and populate in skeleton class
        Also calls open_file, print_chighscore, and print in brain class.
*/
void Brain::run()
{
	board.set_size(size);
	board.create_board();
	board.populate();
	open_file();
	print_chighscore();
	print();
	return;
}

/*Function: print
  Returns: nothing
  Paremeters: nothing
  Does: calls print function in skeleton class to print board
*/
void Brain::print()
{
	board.print();
	return;
}

/*Function: determine move
  Returns: an int to determine if user passed in a valid input
  Paremeters: users choice of move
  Does: calls a move function based on users choice of move or
        pronts highscore or quits.
*/
int Brain::determine_move(char choice)
{
	user_input = choice;
	switch (choice)
	{
		case 'w':
		case 'W':
				board.movew();
				break;
		case 'a':
		case 'A':
				board.movea();
				break;
		case 's':
		case 'S':
				board.moves();
				break;
		case 'd':
		case 'D':
				board.moved();
				break;
		case 'h':
		case 'H':
				print_highscore();
				break;
		case 'q':
		case 'Q':
				cout << "YOU QUIT!!" << endl;
				break;
	default:
			cout << "Invalid choice." << endl;
			return -1;
	}
	return 1;
}

/*Function: print_highscore
  Returns: nothing 
  Paremeters: nothing
  Does: prints the top five highscores when user enters h 
*/
void Brain::print_highscore()
{
	/*if-else statements to print the apropriate number of 
	  number of highscores based on the number of highscores
	  in the highscore file.*/
    if (score_size <= 1)
    {
    	cout << "There are no highscores now." << endl;
    }
	else if (score_size <= 5)
	{
		cout << "Name" << "\t" << "Score" << endl;
		for (int i = 0; i < score_size - 1; i++)
			cout << names[i]  << "\t" << score_ray[i] << endl;
	}
	else
	{
		cout << "Name" << "\t" << "Score" << endl;
		for (int i = 0; i < 5; i++)
			cout << names[i]  << "\t" << score_ray[i] << endl;
	}
	return;
}

/*Function: print_chighscore
  Returns: nothing
  Paremeters:nothing 
  Does: prints the current highscore along with the users score
*/
void Brain::print_chighscore()
{
	score = board.get_score();
	highscore = score_ray[0];
	cout << "Highescore: " << highscore << endl;
	cout << "Your score: " << score << endl;
	return;
}

/*Function: is_over
  Returns: a boolean-true if game is over and false if not.
  Paremeters: nothing 
  Does: calls game_over in skeleton class and quits the game
        if the user enters q
*/
bool Brain::is_over()
{
	int check;
	check = board.game_over();
	if(user_input == 'q' || user_input == 'Q')
		check = 1;
	if(check == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*Function: open_file
  Returns: nothing
  Paremeters: nothing
  Does: opens highscore file and reads in the scores to a dynamically
        created array along with their names in a dynamicaly created 
        array of strings. It also creates the highscore file if it does
        not exist in the directry.
*/
void Brain::open_file()
{
	ifstream infile;
	infile.open(FILENAME);
	if (!infile.is_open())
	{
		//creating highscore file if it doesn't exist in the directry.
		ofstream outfile;
		outfile.open(FILENAME);
		outfile << "System" << " " << "0" << endl;
		outfile << "-1";
		outfile.close();
		infile.open(FILENAME);
		if (!infile.is_open())
		{
			cerr << "ERROR!!" << endl;
			return;
		}
	}
	
	string temp_n;
	int score;
	while (!infile.eof())
	{
		infile >> temp_n >> score;
		if (temp_n == "-1")
			break;
		score_size ++;
	}

	infile.close();
	infile.open(FILENAME);
	if (!infile.is_open())
	{
		cerr << "ERROR!!" << endl;
		return;
	}
	/*creating dyamic array to hold the name and scores from 
	  highscore.txt and reades in them into the apropriate arrays
	*/
	score_ray = new int[score_size + 1];
	names = new string[score_size + 1];
	for (int i = 0; i < score_size; i++)
	{
		infile >> names[i] >> score_ray[i];
	}

	infile.close();
	return;
}

/*Function: update_file
  Returns: nothing 
  Paremeters: nothing
  Does: places the users name and score in the apropriate 
        poaition in the arrays for scores and names and then
        writes them to the file. 
*/
void Brain::update_file()
{
	int loc = 0;
	//looping through to find the location for the new score.
	for (int i = 0; i < score_size; i++)
	{
		if(score_ray[i] <= score)
		{
			loc = i;
			break;
		}
	}
	
	//moving every other score and name to leave the spot needed empty.
	for (int i = score_size; i > loc; i--)
	{
		score_ray[i] = score_ray[i -1];
		names[i] = names[i -1];
	}

	//placing the name and score in their apropriate positions.
	score_ray[loc] = score;
	names[loc] = name;

	//writing the newly updated array to highscore.txt.
	ofstream outfile;
	outfile.open(FILENAME);
	if (!outfile.is_open())
	{
		cerr << "Error opening file\n";
		return;
	}
	for (int i = 0; i < score_size + 1; i++)
		outfile << names[i] << " " << score_ray[i] << endl;
	
	outfile << "-1";
	outfile.close();

	return;
}

/*Function: newscore 
  Returns: nothing 
  Paremeters: nothing
  Does:checks if the has the new highscore, calls update file,
       then prints the top five scores of the newly created 
       highscore file.
*/
void Brain::newscore()
{
	if (score > highscore)
	{
		cout << "You have the new high score." << endl;
	}
	else if (score == highscore)
	{
		cout << "You have a joint high score." << endl;
	}
	update_file();
	score_size = score_size + 1;
	print_highscore();
	return;
}
