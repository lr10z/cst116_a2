//
//  Assignment 2 - Leander Rodriguez
//  
//  CST 116 - C++ Programming I
//
//  Due Date:  Sunday, October 21st by 11:59pm
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using  namespace  std;



//Process user guess

void processGuess( int guess, int answer )
{
	if  ( guess  <  answer  &&  guess  !=  answer ) 
		cout  <<  "Too low."  <<  endl  <<  endl;

	else if ( guess  >  answer  &&  guess  !=  answer )
		cout  <<  "Too high."  <<  endl  <<  endl;
}



//Get user guess

void userGuess( int answer )
{
	int guess;
	int totalGuesses;
	
	totalGuesses = 0;
	
	do
	{
		cout  <<  "Enter your guess: ";
		cin   >>  guess;

		processGuess( guess, answer ); 
		++totalGuesses;

	}	while( guess  !=  answer );

	
	cout  <<  "Correct. You got it in "  <<  totalGuesses  
		  <<  " guesses."  <<  endl  <<  endl;
}



//Start Game

void playGame()
{
	//Get max number

    int max;
	int answer;

	cout  <<  endl;
	cout  <<  "What's the maximum random number value: ";
	cin   >>  max;
	cout  <<  endl;


	//Generate random number

	srand( (unsigned) time(0) );
	answer = rand() % max  +  1; 



	//Calculate expected amount of guesses

	int amountOFguesses = 0;
	double num;

	do
	{		
		++amountOFguesses;
		num = pow (2.0, amountOFguesses);

	}	while( num < max );

	cout  <<  "You can do it in "  <<  amountOFguesses 
		  <<  " guesses or less."  <<  endl  
		  <<  endl;



	//Get user guess
	userGuess(answer);
}



//Play again?

void playAgain()
{
	char c;

	do
	{
		cout  <<  "Do you want to play again (y/n): ";
		cin >> c;

		if  ( c == 'y' )
		{
		playGame();
		}
	
		else if ( c == 'n' )
		{
		cout  <<  "Thanks for playing."  <<  endl  <<  endl;
		}

		else
		{
		//it's neither
		}

	}	while( c  ==  'y' );

}



int  main() 
{
	cout  <<  endl;

	playGame();
	playAgain();
	
	return  0;

}