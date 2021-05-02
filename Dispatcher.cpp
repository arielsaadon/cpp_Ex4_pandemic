#include "Dispatcher.hpp"

using namespace std;
using namespace pandemic;

Player& Dispatcher::fly_direct(City c) {
    if(this->board.board.at(this->currentCity).researchStation){
        this->currentCity = c;
    } else{
        throw invalid_argument{"Do not have a Research Station in "+ pandemic::city_to_string(this->currentCity)};
    }
    return *this;
}

string Dispatcher::role() {
    return this->type;
}
