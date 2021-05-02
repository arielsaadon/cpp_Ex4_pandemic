#pragma once

#include "Player.hpp"

namespace pandemic{
    class Medic: public Player{
        std::string type = "Medic";
    public:
        Medic(Board& b,City c): Player(b,c){}

        Player& treat(City c) override;
        std::string role() override;
    };
}