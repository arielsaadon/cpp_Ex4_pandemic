#include "Player.hpp"
#include <algorithm>
#include <vector>

using namespace std;
using namespace pandemic;

void Player::remove_cards() {
    for(bool& x : this->cards){
        x = false;
    }
}

Player& Player::take_card(City c) {
    this->board.cards.at(c) = false;
    this->cards.at(c) = true;
    return *this;
}

Player& Player::build() {
    if(this->cards.at(this->currentCity)){
        this->board.board.at(this->currentCity).researchStation = true;
        this->cards.at(this->currentCity) = false;
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
    if(this->cards.at(c)){
        this->currentCity = c;
        this->cards.at(c) = false;
    } else{
        throw invalid_argument{"You do not have the card of "+ pandemic::city_to_string(c)};
    }
    return *this;
}

Player& Player::fly_charter(City c) {
    if(this->cards.at(this->currentCity)){
        this->cards.at(this->currentCity) = false;
        this->currentCity = c;
    } else{
        throw invalid_argument{"You do not have the card of "+ pandemic::city_to_string(this->currentCity)};
    }
    return *this;
}

Player& Player::fly_shuttle(City c) {
    if(this->currentCity == c){
        throw invalid_argument{"cannot fly from city to it self"};
    }
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

vector<City> Player::cardsSameColor(Board &b, const array<bool,ALL_CARDS> &cards, Color c) {
    vector<City> vec;
    for(auto const& x : b.board){
        if(cards.at(x.first) && x.second.color == c){
            vec.push_back(x.first);
        }
    }
    return vec;
}

Player& Player::discover_cure(Color c) {
    if(this->board.board.at(this->currentCity).researchStation){
        vector<City> vec = cardsSameColor(this->board,this->cards, c);
        if(vec.size() >= CARDS_DROP){
            this->board.cure.at(c) = true;
            for (size_t i = 0; i < CARDS_DROP; i++) {
                this->cards.at(vec[i]) = false;
            }
        } else{
            throw invalid_argument{"You only have " +to_string(vec.size()) +" " +color_to_string(c) +" cards remaining"};
        }
    } else{
        throw invalid_argument{"In " +city_to_string(this->currentCity) +" dont have Research Station"};
    }
    return *this;
}

string Player::role() {
    return "";
}
