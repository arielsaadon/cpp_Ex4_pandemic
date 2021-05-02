#pragma once

#include <string>
#include <utility>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    class Player{
    protected:
        Board& board;
        City currentCity;
        bool cards[ALL_CARDS] = {false};

        static std::vector<City> cardsSameColor(Board& b,const bool* cards, Color c);
    public:
        Player(Board& b,City c): board(b), currentCity(c){}
        virtual ~Player()= default;

        Player& take_card(City c);
        virtual Player& build();
        Player& drive(City c);
        virtual Player& fly_direct(City c);
        Player& fly_charter(City c);
        Player& fly_shuttle(City c);
        virtual Player& treat(City c);
        virtual Player& discover_cure(Color c);
        virtual std::string role();
    };
}