#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
using namespace std;

int main() {
    int secretNumber, guess;

    
    // Seed the random number generator with current time
    srand(time(0));
    secretNumber = rand() % 100 + 1; // Random number between 1 and 100

    cout << "Guess the Number Game!" << endl;
    cout << "I'm thinking of a number between 1 and 100." << endl;

    // Loop until correct guess
    do {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number correctly!" << endl;
        }

    } while (guess != secretNumber);

    return 0;
}