// Mastermind
// Kim Sibol, Christian Wendt, Philip Whitcomb
// ECE 2524: Unix
// 
// Mastermind is a game of intelligence, where the player must guess
// the correct number sequence to win the game. Black and white pin
// variables correspond to correct guesses and number placements.
//

#include "mastermind.h"

// Generates a random string of numbers used as the random numbers
// in the game. Takes length as a parameter and returns the char array
// of numbers.
char *randomStrGen(int length)
{
	static string charset="0123456";
	char *charArray;
	charArray = new char[length]; //allocation for char array length
	srand(time(NULL));
	for(int i=0; i < 5; i++)
		charArray[i]=charset[rand() % charset.length()];

	return charArray;
}

// Main in-game method for Mastermind. 
void mastermind( istream&in, ostream&out)
{

	char *number = randomStrGen(5); //call to randomStrGen method with default length 5

	//Instructions displayed at the start of the game
	//User must type "begin" to start the game
	out << "Instructions:" << endl;
	out << "Welcome to Mastermind! You are a code breaker whose objective is to crack the secret code ";
	out << "created by Dr. Random. The code is comprised of 5 digits where each digit is between 0-6.";
	out << "With each guess you make, Dr. Random will respond with helpful clues to aid you in deducing ";
	out << "the correct code. Good luck, and let the code breaking begin!" << endl;
	out << "\n\nPlease type begin to begin the game!\n";

	//Initialization and declaration of variables
	string begin;
	string guess;
	char playagain;
	int i=0;
	int blackPin=0;
	int whitePin=0;
	int tries = 0;
	int track = 0;
	int guesses=0;
	char *ARRAY;
	ARRAY = new char[5];
	in >> begin;
	while( begin != "begin")
	{
		out << "Please type begin to begin the game!\n";
		in >> begin;
	}
	//Checks if user enters begin to start the game
	if(begin=="begin")
	{
		out << "Please enter your first guess: ";
		in >> guess;
		strcpy(ARRAY, guess.c_str());

		//Loop while guesses are still available
		while(!in.fail() && guesses < 9)
		{

			for(int j=0; j < 5; j++)
			{
				track = 1;
				if(ARRAY[j]==number[j])
				{
					blackPin++;
					track = 0;
				}
				for(int k = 0; k<5; k++)
				{
					if(ARRAY[k] == number[j] && k != j && track != 0)
					{
						whitePin++;
						track = 0;
					}
				}
			}
			if(blackPin==5 && guesses != 9)
			{
				guesses=10;
				whitePin = 0;
				tries++;
			}
			out<<"Correct number and position: " << blackPin << endl;
			out <<"Correct number, wrong position: " << whitePin <<endl;
			if(blackPin != 5)
			{
				out << "Please enter your next guess: ";
				in >> guess;
				tries++;
			}
			
			strcpy(ARRAY, guess.c_str());
			guesses++;

			if(blackPin==5)
			{
				out << "\nGame over!!!"<< endl;
				out << "It took you " << tries << " tries to guess the correct combination: ";
				for(int i=0; i<5; i++)
				{
					out << number[i];
				}
				out << '\n';
				out << "To play again type y, or type n to quit: ";
				in >> playagain;
				if(playagain == 'y' || playagain == 'Y')
				{
					guesses = 0;
					number = randomStrGen(5);
					out << "Please enter your first guess: ";
					in >> guess;
					strcpy(ARRAY, guess.c_str());
				}
			}
			if(guesses==9 && blackPin!=5)
			{
				out << "\nGame over! You couldn't crack Dr. Random's secret code: ";
				for(int i=0; i<5; i++)
				{
					out << number[i];
				}
				out <<'\n';
				out << "To play again type y, or type n to quit: ";
				in >> playagain;
				if(playagain == 'y' || playagain == 'Y')
				{
					guesses = 0;
					number = randomStrGen(5);
					out << "Please enter your first guess: ";
					in >> guess;
					strcpy(ARRAY, guess.c_str());
				}


			}
			blackPin=0;
			whitePin=0;
		}	
	}
}
