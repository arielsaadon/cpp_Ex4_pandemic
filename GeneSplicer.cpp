#include "GeneSplicer.hpp"

using namespace std;
using namespace pandemic;

vector<City> vecCards(Board& b,const bool* cards){
    vector<City> vec;
    for(auto const& x : b.board){
        if(cards[x.first]){
            vec.push_back(x.first);
        }
    }
    return vec;
}

Player& GeneSplicer::discover_cure(Color c) {
    if(this->board.board.at(this->currentCity).researchStation){
        vector<City> vec = vecCards(this->board,this->cards);
        if(vec.size() >= 5){
            for (int i = 0; i < 5; i++) {
                this->cards[vec[i]] = false;
            }
        } else{
            throw invalid_argument{"You only have " +to_string(vec.size()) +" cards remaining"};
        }
    }
    return *this;
}

std::string GeneSplicer::role() {
    return this->type;
}
