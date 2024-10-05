#include <iostream>
#include <cstdlib> 
#include <ctime>   

using namespace std;

void numberGuessingGame() {
    
    srand(static_cast<unsigned int>(time(0)));
    
    
    int randomNumber = rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I'm thinking of a number between 1 and 1000." << endl;

    while (guess != randomNumber) {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You've guessed the correct number in " << attempts << " attempts." << endl;
        }
    }
}

int main() {
    numberGuessingGame();
    return 0;
}
