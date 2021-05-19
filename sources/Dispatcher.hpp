#pragma once

#include "Player.hpp"

namespace pandemic{
    class Dispatcher: public Player{
        std::string type = "Dispatcher";
    public:
        Dispatcher(Board& b,City c): Player(b,c){}

        Player& fly_direct(City c) override;
        std::string role() override;
    };
}