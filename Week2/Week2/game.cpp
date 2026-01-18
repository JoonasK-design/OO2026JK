#include "game.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

Game::Game(int maxnum)
{
    maxNumber = maxnum;
    numOfGuesses = 0;
    randomNumber = (rand() % maxnum)+1;
    playerGuess = 0;

    cout << "GAME CONSTRUCTOR: object initialized with " << maxNumber << " as a maximum value" << endl;
}

Game::~Game()
{
    cout << "GAME DESTRUCTOR: object cleared from stack memory" << endl;
}

void Game::play()
{
    cout << "Give your guess between 1 - " << maxNumber << endl;

    while (playerGuess != randomNumber) {
        cout << "Give a number: ";
        cin >> playerGuess;
        numOfGuesses++;

        if (playerGuess < randomNumber) {
            cout << "Your guess is too small" << endl;
        }
        else if (playerGuess > randomNumber) {
            cout << "Your guess is too big" << endl;
        }
        else {
            cout << "Your guess is right = " << randomNumber << endl;
        }
    }
    printGameResult();
}

void Game::printGameResult()
{
    cout << "You guessed the right answer = " << randomNumber << " with " << numOfGuesses << " guesses" << endl;
}
