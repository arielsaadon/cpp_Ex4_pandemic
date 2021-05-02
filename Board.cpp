#include "Board.hpp"
#include <string>

using namespace std;
using namespace pandemic;

bool Board::is_clean() {
    for(auto const& x : board){
        if(x.second.diseaseLevel > 0)
            return false;
    }
    return true;
}

int& Board::operator[](City city) {
    return board.at(city).diseaseLevel;
}

ostream& pandemic::operator<<(ostream &os, const Board &b) {
    for(auto const& x : b.board){
        os << "City name: "  +pandemic::city_to_string(x.first) + ",diseaseLevel: "
        +to_string(x.second.diseaseLevel) +",Have Research Station: " +to_string(x.second.researchStation) + "\n";
    }
    return os;
}

