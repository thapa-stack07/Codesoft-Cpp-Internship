#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
        cout << "Secret Number = " << secretNumber << endl;

    int guess;
    int attempts = 0;
    bool hasGuessedCorrectly = false;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I've selected a number between 1 and 100. Try to guess it." << endl;

    while (!hasGuessedCorrectly) {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess == secretNumber) {
            hasGuessedCorrectly = true;
            cout << "Congratulations! You've guessed the number in " << attempts << " attempts." << endl;
        } else if (guess < secretNumber) {
            cout << "Try a higher number." << endl;
        } else {
            cout << "Try a lower number." << endl;
        }
    }

    return 0;
}