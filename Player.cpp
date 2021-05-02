#include "Player.hpp"
#include <algorithm>
#include <vector>

using namespace std;
using namespace pandemic;


Player& Player::take_card(City c) {
    this->board.cards[c] = false;
    this->cards[c] = true;
    return *this;
}

Player& Player::build() {
    if(this->cards[this->currentCity]){
        this->board.board.at(this->currentCity).researchStation = true;
        this->cards[this->currentCity] = false;
    } else{
        throw invalid_argument{"You do not have the "+ pandemic::city_to_string(this->currentCity) +" card"};
    }
    return *this;
}

Player& Player::drive(City c) {
    vector<City> vec = this->board.board.at(this->currentCity).cityNeighbours;
    auto it = find(vec.begin(), vec.end(), c);
    if(it == vec.end()){
        throw invalid_argument{pandemic::city_to_string(this->currentCity) +" is not connected to " +pandemic::city_to_string(c)};
    }
    this->currentCity = c;
    return *this;
}

Player& Player::fly_direct(City c) {
    if(this->cards[c]){
        this->currentCity = c;
        this->cards[c] = false;
    } else{
        throw invalid_argument{"You do not have the card of "+ pandemic::city_to_string(c)};
    }
    return *this;
}

Player& Player::fly_charter(City c) {
    if(this->cards[this->currentCity]){
        this->currentCity = c;
        this->cards[this->currentCity] = false;
    } else{
        throw invalid_argument{"You do not have the card of "+ pandemic::city_to_string(this->currentCity)};
    }
    return *this;
}

Player& Player::fly_shuttle(City c) {
    if(this->board.board.at(this->currentCity).researchStation && this->board.board.at(c).researchStation){
        this->currentCity = c;
    } else{
        throw invalid_argument{"In "+ pandemic::city_to_string(this->currentCity) +" or " +pandemic::city_to_string(c) +" dont have a Research station"};
    }
    return *this;
}

Player& Player::treat(City c) {
    if(c != this->currentCity){
        throw invalid_argument{"You are not in " +city_to_string(c)};
    }
    if(this->board.board.at(c).diseaseLevel == 0){
        throw invalid_argument{"No more cubes remain in "+city_to_string(c)};
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

vector<City> Player::cardsSameColor(Board &b, const bool *cards, Color c) {
    vector<City> vec;
    for(auto const& x : b.board){
        if(cards[x.first] && x.second.color == c){
            vec.push_back(x.first);
        }
    }
    return vec;
}

Player& Player::discover_cure(Color c) {
    if(this->board.board.at(this->currentCity).researchStation){
        vector<City> vec = cardsSameColor(this->board,this->cards, c);
        if(vec.size() >= 5){
            this->board.cure.at(c) = true;
            for (int i = 0; i < 5; i++) {
                this->cards[vec[i]] = false;
            }
        } else{
            throw invalid_argument{"You only have " +to_string(vec.size()) +" " +pandemic::color_to_string(c) +" cards remaining"};
        }
    }
    return *this;
}

string Player::role() {
    return "";
}
