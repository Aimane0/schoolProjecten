#ifndef rock_paper_scissor_hpp
#define rock_paper_scissor_hpp
#include <iostream>
#include <string>

class rock_paper_scissor
{
private:

    std::string _playerName;

    struct Choices
    {
        std::string computerChoice;
        std::string playerChoice;
        std::string winner;
    };
    Choices choices;

    void computerChoice();
    void playerChoice();
    void determineWinner();

public:
    rock_paper_scissor(std::string playerName);

    void play();
};

#endif