#include "mastermind.h"

char *randomStrGen(int length)
{
	static string charset="0123456";
	char *charArray;
	charArray = new char[length];
	srand(time(NULL));
	for(int i=0; i < 5; i++)
		charArray[i]=charset[rand() % charset.length()];

	return charArray;
}


void mastermind( istream&in, ostream&out)
{
	char *number = randomStrGen(5);
	for(int i=0; i<5; i++)
	{
		out << number[i];
	}
	out << "Instructions:" << endl;
	out << "Welcome to Mastermind! You are a code breaker whose objective is to crack the secret code ";
	out << "created by the two best Unix students in the world! The code is cracked when you duplicate ";
	out << "the exact colors and their positions of the secret code. To crack the code, you will make a guess ";
	out << "to which the game will respond with helpful clues to aid you in guessing the secret code. ";
	out << "If the game responds with a 1, you have guessed the right color and right position. ";
	out << "If the game responds with a 0, you have guessed the right color but wrong position. ";
	out << "From these clues you deduce aspects of the code and then make a new guess. ";

	out << "\n\nPlease type begin to begin the game!\n";
	
	string begin;
	string guess;
	int i=0;
	int blackPin=0;
	int whitePin=0;
	int tries = 0;
	int none=0;
	int track = 0;
	int guesses=0;
	char *ARRAY;
	ARRAY = new char[5];
	in >> begin;
	if(begin=="begin")
	{
		out << "Please enter your first guess: ";
		in >> guess;
		strcpy(ARRAY, guess.c_str());

		while(!in.fail() && guesses < 10)
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
					if(ARRAY[j] == number[k] && k != j && track != 0)
					{
						whitePin++;
						track = 0;
					}
				}
			}
			if(blackPin==5)
			{
				guesses=10;
				whitePin = 0;
				tries++;
			}

			out<<"Correct number and position: " << blackPin << endl;
			out <<"Correct number, wrong position: " << whitePin << endl;
			if(blackPin != 5)
			{
				out << "Please enter your next guess: ";
				in >> guess;
				tries++;
			}
			strcpy(ARRAY, guess.c_str());
			guesses++;
			blackPin=0;
			whitePin=0;
		}
		

		out << "Game Over!!!!!" << endl;
		out << "It took you " << tries << " tries to guess the correct combination" << endl;

	}
}
