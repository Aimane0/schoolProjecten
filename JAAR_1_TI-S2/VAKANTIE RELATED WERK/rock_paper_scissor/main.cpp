#include "rock_paper_scissor.hpp"
#include <iostream>
#include <string>

int main()
{
    std::string playerName;

    std::cout << "What is your name?" << "\n";

    getline(std::cin, playerName);

    rock_paper_scissor game(playerName);
    while (true)
    {
        game.play();
    }
    return 0;
}