#include <algorithm>
#include "FieldDoctor.hpp"

using namespace std;
using namespace pandemic;

bool nearbyCity(Board& b , City cc,City c){
    vector<City> vec =  b.board.at(cc).cityNeighbours;
    return find(vec.begin(),vec.end(),c)!=vec.end();
}

Player& FieldDoctor::treat(City c) {
    if(!nearbyCity(this->board,this->currentCity,c)){
        throw invalid_argument{pandemic::city_to_string(this->currentCity) +" is not nearby to " +pandemic::city_to_string(c)};
    }
    if(this->board.board.at(c).diseaseLevel == 0){
        throw invalid_argument{"No more cubes remain in "+pandemic::city_to_string(c)};
    }
    if(this->board.board.at(c).diseaseLevel > 0){
        if(this->board.cure[this->board.board.at(c).color]){
            this->board.board.at(c).diseaseLevel = 0;
        } else {
            this->board.board.at(c).diseaseLevel -= 1;
        }
    }
    return *this;
}

string FieldDoctor::role() {
    return this->type;
}
