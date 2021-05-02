#include "Scientist.hpp"

using namespace std;
using namespace pandemic;

Player& Scientist::discover_cure(Color c){
    if(this->board.board.at(this->currentCity).researchStation){
        vector<City> vec = Player::cardsSameColor(this->board,this->cards, c);
        if(vec.size() >= this->discover_cure_operation){
            this->board.cure.at(c) = true;
            for (int i = 0; i < this->discover_cure_operation; i++) {
                this->cards[vec[i]] = false;
            }
        } else{
            throw invalid_argument{"You only have " +to_string(vec.size()) +pandemic::color_to_string(c) +" cards remaining"};
        }
    }
    return *this;
}

std::string Scientist::role() {
    return this->type;
}