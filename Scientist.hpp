#pragma once

#include "Player.hpp"

namespace pandemic{
    class Scientist: public Player{
        std::string type = "Scientist";
        int discover_cure_operation;

    public:
        Scientist(Board& b,City c,int n): Player(b,c), discover_cure_operation(n){}

        Player& discover_cure(Color c) override;
        std::string role() override;
    };
}