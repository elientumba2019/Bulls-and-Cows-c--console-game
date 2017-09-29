/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>	
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();


FBullCowGame BCGame; // instantiate a new game

// the entry point for our application
int main()
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	}
	while (bPlayAgain);

	return 0; // exit the application
}

 
// introduce the game
void PrintIntro()
{
	
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}


void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	
	// loop for the number of turns asking for guesses
	
	//loop asking for guesses until the game is won, 
	//there are still turns
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() < MaxTries) {
		FText Guess = GetValidGuess(); // TODO make loop checking valid

		// submit valid guess to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);


		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";


	}
	
	PrintGameSummary();
	return;
}




//loop continually untill a valid guess is enterred 
FText GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess = "";


	do {
		int32 CurrentTry = BCGame.GetCurrentTry();

		// get a guess from the player
		std::cout << "Try " << CurrentTry << ". Enter your guess: ";
		
		std::getline(std::cin, Guess);


		 Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{

		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength()
				<< " Letter word !" << std::endl;
			break;



		case EGuessStatus::Not_Isogram:
			std::cout << "THe input is not an isogram , Enter a new word" << std::endl;
			break;


		case EGuessStatus::Not_Lowercase:
			std::cout << "Your word is not a lower case word , Please change : " << std::endl;
			break;


		default:
			// assume the guess is valid
			break;

		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); // keep looping untill no errors are found
	
	return Guess;
}



bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word(y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}



void PrintGameSummary() 
{

	if (BCGame.IsGameWon()) {
		std::cout << "WELL DONE YOU WIN" << std::endl;
	}

	else
	{
		std::cout << "Better luck next Time !"  << std::endl;
	}
}
