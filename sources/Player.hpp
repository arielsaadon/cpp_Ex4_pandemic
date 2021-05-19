#pragma once

#include <string>
#include <utility>

#include "Board.hpp"

namespace pandemic{
    class Player{
    protected:
        Board& board;
        City currentCity;
        std::array<bool, ALL_CARDS> cards{false};

        static std::vector<City> cardsSameColor(Board &b, const std::array<bool,ALL_CARDS> &cards, Color c);
    public:
        Player(Board& b,City c): board(b), currentCity(c){}
        virtual ~Player()= default;
        void remove_cards();

        Player& take_card(City c);
        virtual Player& build();
        virtual Player& drive(City c);
        virtual Player& fly_direct(City c);
        virtual Player& fly_charter(City c);
        virtual Player& fly_shuttle(City c);
        virtual Player& treat(City c);
        virtual Player& discover_cure(Color c);
        virtual std::string role();
    };
}