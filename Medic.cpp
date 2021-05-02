#include "Medic.hpp"

using namespace std;
using namespace pandemic;

Player& Medic::treat(City c) {
    if(c != this->currentCity){
        throw invalid_argument{"You are not in " +pandemic::city_to_string(c)};
    }
    if(this->board.board.at(c).diseaseLevel == 0){
        throw invalid_argument{"No more cubes remain in "+pandemic::city_to_string(c)};
    }
    if(this->board.board.at(c).diseaseLevel > 0){
        this->board.board.at(c).diseaseLevel = 0;
    }
    return *this;
}

string Medic::role() {
    return this->type;
}
