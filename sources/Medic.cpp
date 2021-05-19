#include "Medic.hpp"

using namespace std;
using namespace pandemic;

Player& Medic::drive(City c) {
    vector<City> vec = this->board.board.at(this->currentCity).cityNeighbours;
    auto it = find(vec.begin(), vec.end(), c);
    if(it == vec.end()){
        throw invalid_argument{pandemic::city_to_string(this->currentCity) +" is not connected to " +pandemic::city_to_string(c)};
    }
    if (this->board.cure[this->board.board.at(c).color]){
            this->board.board.at(c).diseaseLevel = 0;
    }
    this->currentCity = c;
    return *this;
}

Player& Medic::fly_direct(City c) {
    if(this->cards.at(c)){
        this->currentCity = c;
        this->cards.at(c) = false;
        if (this->board.cure[this->board.board.at(c).color]){
            this->board.board.at(c).diseaseLevel = 0;
        }
    } else{
        throw invalid_argument{"You do not have the card of "+ pandemic::city_to_string(c)};
    }
    return *this;
}

Player& Medic::fly_charter(City c) {
    if(this->cards.at(this->currentCity)){
        this->cards.at(this->currentCity) = false;
        this->currentCity = c;
        if (this->board.cure[this->board.board.at(c).color]){
            this->board.board.at(c).diseaseLevel = 0;
        }
    } else{
        throw invalid_argument{"You do not have the card of "+ pandemic::city_to_string(this->currentCity)};
    }
    return *this;
}

Player& Medic::fly_shuttle(City c) {
    if(this->board.board.at(this->currentCity).researchStation && this->board.board.at(c).researchStation){
        this->currentCity = c;
        if (this->board.cure[this->board.board.at(c).color]){
            this->board.board.at(c).diseaseLevel = 0;
        }
    } else{
        throw invalid_argument{"In "+ pandemic::city_to_string(this->currentCity) +" or " +pandemic::city_to_string(c) +" dont have a Research station"};
    }
    return *this;
}

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
