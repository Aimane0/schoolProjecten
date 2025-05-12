#include "rock_paper_scissor.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib> // For srand() and rand()
#include <ctime>   // For time()

rock_paper_scissor::rock_paper_scissor(std::string playerName) : _playerName(playerName) {}

void rock_paper_scissor::computerChoice()
{
    std::vector<std::string> localChoices = {"rock", "paper", "scissor"};
    int randomIndex = rand() % localChoices.size();
    choices.computerChoice = localChoices[randomIndex];
}

void rock_paper_scissor::playerChoice()
{
    std::string _playerChoice;
    std::cout << "Select rock, paper or scissor!" << "\n";
    getline(std::cin, _playerChoice);
    std::transform(_playerChoice.begin(), _playerChoice.end(), _playerChoice.begin(), ::tolower);
    choices.playerChoice = _playerChoice;
}

void rock_paper_scissor::determineWinner()
{
    if (choices.playerChoice == choices.computerChoice)
    {
        choices.winner = "IT IS A DRAW!";
    }
    else if ((choices.playerChoice == "rock" && choices.computerChoice == "scissor") ||
             (choices.playerChoice == "paper" && choices.computerChoice == "rock") ||
             (choices.playerChoice == "scissor" && choices.computerChoice == "paper"))
    {
        choices.winner = "PLAYER WINS!";
    }
    else
    {
        choices.winner = "COMPUTER WINS!";
    }
}

void rock_paper_scissor::play()
{
    std::cout << "Hello " << _playerName << "\n";
    computerChoice();
    playerChoice();
    determineWinner();
    std::cout << "computer choice: " << choices.computerChoice << "\n";
    std::cout << "player choice: " << choices.playerChoice << "\n";
    std::cout << "winner choice: " << choices.winner << "\n";
}
