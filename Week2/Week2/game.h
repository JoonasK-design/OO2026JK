#ifndef GAME_H
#define GAME_H

class Game
{
public:

    Game(int);
    ~Game();
    void play();

private:

    int maxNumber;
    int playerGuess;
    int randomNumber;
    int numOfGuesses;
    void printGameResult();

};

#endif // GAME_H
