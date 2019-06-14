#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // print story to terminal
    std::cout << "\n\nThe world is on the brink of apocalypse.\n";
    std::cout << "You must stop it.\n";
    std::cout << "Hack into the Nexus of Self Righteous Behavior's core; reverse the flow and implode the system!\n";
    std::cout << "You will need to bypass the many walls of security blocking you.\n";
    std::cout << "Take your time. Be patient. Think clearly.\n";
    std::cout << "If you fail, the Nexus will explode and radiate outwards into all of humanity.\n";
    std::cout << "Only you can save us.\n\n";
    std::cout << "Level  " << Difficulty <<std::endl;
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
        std::cout << "\nYOU are WRONG. ABORT! ABORT!\n";
        return true;
    }
    else
    {
        std::cout << "\nI am RIGHT! YOU are LOST...\n";
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