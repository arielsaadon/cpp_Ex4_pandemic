#pragma once

#include "Player.hpp"

namespace pandemic{
    class Researcher: public Player{
        std::string type = "Researcher";
    public:
        Researcher(Board& b,City c): Player(b,c){}

        Player& discover_cure(Color c) override;
        std::string role() override;
    };
}