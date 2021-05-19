#pragma once

#include "Player.hpp"

namespace pandemic{
    class GeneSplicer: public Player{
        std::string type = "GeneSplicer";
    public:
        GeneSplicer(Board& b,City c): Player(b,c){}

        Player& discover_cure(Color c) override;
        std::string role() override;
    };
}