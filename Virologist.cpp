#include "Virologist.hpp"

using namespace std;
using namespace pandemic;

Player& Virologist::treat(City c) {
    if(this->board.board.at(c).diseaseLevel == 0){
        throw invalid_argument{"No more cubes remain in "+pandemic::city_to_string(c)};
    }
    if(!this->cards[c]){
        throw invalid_argument{"You dont have a card "+pandemic::city_to_string(c)};
    }
    if(this->board.board.at(c).diseaseLevel > 0){
        if(this->board.cure[this->board.board.at(c).color]){
            this->board.board.at(c).diseaseLevel = 0;
            this->cards[c] = false;
        } else {
            this->board.board.at(c).diseaseLevel -= 1;
            this->cards[c] = false;
        }
    }
    return *this;
}

std::string Virologist::role() {
    return this->type;
}


