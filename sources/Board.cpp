#include "Board.hpp"

using namespace std;
using namespace pandemic;

bool Board::is_clean() {
    for(auto const& x : board){
        if(x.second.diseaseLevel > 0){
            return false;
        }
    }
    return true;
}

void Board::remove_cures() {
    for(auto& x : this->cure){
        x.second = false;
    }
}

void Board::remove_stations() {
    for(auto& x : this->board){
        x.second.researchStation = false;
    }
}

int& Board::operator[](City city) {
    return board.at(city).diseaseLevel;
}

ostream& pandemic::operator<<(ostream &os, const Board &b) {
    for(auto const& x : b.board){
        os << "City name: "  +city_to_string(x.first) + ",diseaseLevel: "
        +to_string(x.second.diseaseLevel) +",Have Research Station: " +to_string(static_cast<int>(x.second.researchStation)) + "\n";
    }
    return os;
}

