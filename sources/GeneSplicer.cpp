#include "GeneSplicer.hpp"

using namespace std;
using namespace pandemic;

vector<City> vecCards(Board& b,const array<bool,ALL_CARDS> &cards){
    vector<City> vec;
    for(auto const& x : b.board){
        if(cards.at(x.first)){
            vec.push_back(x.first);
        }
    }
    return vec;
}

Player& GeneSplicer::discover_cure(Color c) {
    if(this->board.board.at(this->currentCity).researchStation){
        vector<City> vec = vecCards(this->board,this->cards);
        if(vec.size() >= CARDS_DROP){
            for (size_t i = 0; i < CARDS_DROP; i++) {
                this->cards.at(vec[i]) = false;
            }
        } else{
            throw invalid_argument{"You only have " +to_string(vec.size()) +" cards remaining"};
        }
    } else{
        throw invalid_argument{"In " +city_to_string(this->currentCity) +" dont have Research Station"};
    }
    return *this;
}

std::string GeneSplicer::role() {
    return this->type;
}
