#include "Dispatcher.hpp"

using namespace std;
using namespace pandemic;

Player& Dispatcher::fly_direct(City c) {
    if(this->currentCity == c){
        throw invalid_argument{"cannot fly from city to it self"};
    }
    if(this->board.board.at(this->currentCity).researchStation){
        this->currentCity = c;
    }
    else if(this->cards.at(c)){
        this->currentCity = c;
        this->cards.at(c) = false;
    } else{
        throw invalid_argument{"You do not have the card of "+city_to_string(c) +" Or do not have a Research Station in " +city_to_string(this->currentCity)};
    }    
    return *this;
}

string Dispatcher::role() {
    return this->type;
}
