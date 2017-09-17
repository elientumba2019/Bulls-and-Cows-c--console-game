#pragma once
#include <string>






using FString = std::string;
using int32 = int;

// all values intialised to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};


//enumeration for guess validity
enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};






class FBullCowGame
{
public:
	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	//method for returning a word's length
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	
	void Reset(); // TODO make a more rich return value.
	EGuessStatus CheckGuessValidity(FString) const; 
	FBullCowCount SubmitValidGuess(FString);


// ^^ Please try and ignore this and focus on the interface above ^^
private:
	// see constructor for initialisation
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};