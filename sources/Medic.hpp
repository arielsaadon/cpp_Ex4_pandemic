#pragma once

#include "Player.hpp"

namespace pandemic{
    class Medic: public Player{
        std::string type = "Medic";
    public:
        Medic(Board& b,City c): Player(b,c){}

        Player& drive(City c) override;
        Player& fly_direct(City c) override;
        Player& fly_charter(City c) override;
        Player& fly_shuttle(City c) override;

        Player& treat(City c) override;
        std::string role() override;
    };
}