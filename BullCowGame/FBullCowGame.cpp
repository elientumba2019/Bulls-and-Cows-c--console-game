#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }



void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	FBullCowGame::MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	FBullCowGame::MyHiddenWord = HIDDEN_WORD;

	FBullCowGame::MyCurrentTry = 1;
	FBullCowGame::bGameIsWon = false;
	return;
}




//returns an enumeration
EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false)//if the guess isnt anisogram 
	{
		return EGuessStatus::Not_Isogram;
	}

	else if (false)//if the guess is not all lower case
	{
		return EGuessStatus::Not_Isogram;
	}
		
	else if (Guess.length() != FBullCowGame::GetHiddenWordLength())//if the guess length is 
	{
		return EGuessStatus::Wrong_Length;
	}
		
	else//otherwise
	{
	
		return EGuessStatus::OK;
	}	 
}




bool FBullCowGame::IsGameWon() const
{
	return FBullCowGame::bGameIsWon;
}







// receives a VALID guess, incriments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); // assuming the same length as guess


	// loop through all letters in the hidden word
	for (int32 MYHWChar = 0; MYHWChar < WordLength; MYHWChar++) 
	{
		// compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) 
		{
			// if they match then
			if (Guess[GChar] == MyHiddenWord[MYHWChar]) {
				if (MYHWChar == GChar) { // if they're in the same place
					BullCowCount.Bulls++; // incriment bulls
				}
				else {
					BullCowCount.Cows++; // must be a cow
				}
			}
		}
	}



	//handling win condition
	if (BullCowCount.Bulls == WordLength) {
		FBullCowGame::bGameIsWon = true;
	}
	else {
		FBullCowGame::bGameIsWon = false;
	}
	return BullCowCount;
}




//returns the length of the hidden word
int32 FBullCowGame::GetHiddenWordLength() const {return FBullCowGame::MyHiddenWord.length();}
