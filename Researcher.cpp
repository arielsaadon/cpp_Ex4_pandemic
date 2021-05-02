#include "Researcher.hpp"

using namespace std;
using namespace pandemic;

Player& Researcher::discover_cure(Color c) {
    vector<City> vec = Player::cardsSameColor(this->board,this->cards, c);
    if(vec.size() >= 5){
        this->board.cure.at(c) = true;
        for (int i = 0; i < 5; i++) {
            this->cards[vec[i]] = false;
        }
    } else{
        throw invalid_argument{"You only have " +to_string(vec.size()) +pandemic::color_to_string(c) +" cards remaining"};
    }
    return *this;
}

std::string Researcher::role() {
    return this->type;
}
