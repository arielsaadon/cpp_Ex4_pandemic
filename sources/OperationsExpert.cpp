#include "OperationsExpert.hpp"

using namespace std;
using namespace pandemic;

Player& OperationsExpert::build() {
    this->board.board.at(this->currentCity).researchStation = true;
    return *this;
}

string OperationsExpert::role() {
    return this->type;
}
