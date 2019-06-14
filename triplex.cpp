#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // print story to terminal
    if(Difficulty < 2)
    {
    std::cout << "\n\nThis nexus contains six walls of security.\n";
    std::cout << "Can you bypass them?\n";
    std::cout << "Each wall contains three hidden numbers that is the code.\n";
    std::cout << "The code will become more difficult as you delve deeper into nexus.\n";
    std::cout << "Please input the code with spaces between each integer or on separate lines in order for them to be read properly by nexus.\n";
    std::cout << "If you fail, nexus will freeze your soul within it's confines for all eternity.\n";
    std::cout << "Good luck.\n\n";
    std::cout << "Level  " << Difficulty <<std::endl;
    }
}
bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    // 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA+CodeB+CodeC;
    const int CodeProduct = CodeA*CodeB*CodeC;

    // print CodeSum and CodeProduct to the terminal
    std::cout << "\n+ There are 3 numbers in the code";
    std::cout << "\n+ The numbers add up to: " << CodeSum;
    std::cout << "\n+ The numbers multiply to give: " << CodeProduct <<std::endl;
    std::cout << "\n Code input: ";

    // player guesses
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    
    int GuessSum = GuessA+GuessB+GuessC;
    int GuessProduct = GuessA*GuessB*GuessC;

    // print win/loss messages
    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nSecurity Wall Level " << Difficulty;
        std::cout << " Bypass\n";
        return true;
    }
    else
    {
        std::cout << "\nYOU are WRONG. ABORT! ABORT!\n";
        return false;
    }
}

int main ()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxLevel = 6;
    while (LevelDifficulty <= MaxLevel) // loop game until completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //clears errors
        std::cin.ignore(); //discards buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }
    std::cout << "...\nNexus...\n ...shutting down\n";
    return 0;
}