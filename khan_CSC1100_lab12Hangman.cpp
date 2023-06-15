/*Taaseen khan */



#include <iostream>
#include <fstream> 

using namespace std;

void intro()
{
	cout << "Welcome to hangman...Guess a country Name" << endl;
	cout << "Each letter is represented by a star." << endl;
	cout << "You have to type only one letter in one try" << endl;
	cout << "You have 5 tries to try and guess the word." << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    
};

int checkLetter (char guess, string word, string &hidden)
{
	
	int matches=0;
	
	for (int i = 0; i< word.length(); i++)
	{
		
		if (guess == hidden[i])
			return 0;
		
		if (guess == word[i])
		{
			hidden[i] = guess;
			matches++;
		}
	}
	return matches;
}

int main()
{   
    string word;
    int guesses = 5;
    char guess;
    int wrong;

    string words[] =
    {
        "japan",
        "turkey",
        "nepal",
        "malaysia",
        "philippines",
        "australia",
        "america",
        "ethiopia",
        "oman",
        "indonesia"
    };
    
    
    intro();
    
    srand(time(NULL));
    int n = rand()% 10;
    word = words[n];

    string hidden(word.length(),'*');
    
    while(guesses > 0){
        cout << "\n" << hidden << endl;
        cout << "\nTake a guess: ";
        cin >> guess;

        if(checkLetter(guess, word, hidden)){   
            cout << "\nYou found a letter! Isn't that exciting!" << endl;
            cout << "You have " << guesses << " guesses remaining." << endl;
        }else{
    		cout << endl << "Whoops! That letter isn't in there!" << endl;
    		guesses--;
    		cout << "You have " << guesses << " guesses remaining." << endl;
    		continue;
        }
        
        if(hidden == word){
            cout << "Yeah, you got it!";
            break;
        }
    };
    
    if(guesses == 0){
        cout << "\nOut of guesses: " << guesses << endl;
        cout << "The word was: " << word;
    };
	  
};
