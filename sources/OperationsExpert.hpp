#pragma once

#include "Player.hpp"

namespace pandemic{
    class OperationsExpert: public Player{
        std::string type = "OperationsExpert";
    public:
        OperationsExpert(Board& b,City c): Player(b,c){}

        Player& build() override;
        std::string role() override;
    };
}