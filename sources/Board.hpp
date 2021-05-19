#pragma once

#include "City.hpp"
#include "Color.hpp"

#include <map>
#include <utility>
#include <vector>
#include <string>

const int ALL_CARDS = 48;
const int CARDS_DROP = 5;

namespace pandemic{
    struct Parameters {
        std::vector<City> cityNeighbours;
        Color color;
        int diseaseLevel = 0;
        bool researchStation = false;
        explicit Parameters(std::vector<City> cityNeighbours, Color color) : cityNeighbours(std::move(cityNeighbours)) , color{color}{}
    };

    class Board{
    public:
        std::array<bool, ALL_CARDS> cards{true};
        std::map<Color,bool> cure = {{Color::Blue, false},{Color::Yellow, false},{Color::Black, false},{Color::Red, false}};
        std::map<City,struct Parameters> board = {
                {City::Algiers, Parameters({City::Madrid, City::Paris, City::Istanbul, City::Cairo} , Color::Black)},
                {City::Atlanta, Parameters({City::Chicago, City::Miami , City::Washington}, Color::Blue)},
                {City::Baghdad, Parameters({City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi}, Color::Black)},
                {City::Bangkok, Parameters({City::Kolkata ,City::Chennai, City::Jakarta ,City::HoChiMinhCity, City::HongKong}, Color::Red)},
                {City::Beijing, Parameters({City::Shanghai, City::Seoul}, Color::Red)},
                {City::Bogota,  Parameters({City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires}, Color::Yellow)},
                {City::BuenosAires, Parameters({City::Bogota, City::SaoPaulo}, Color::Yellow)},
                {City::Cairo,Parameters({City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh}, Color::Black)},
                {City::Chennai, Parameters({City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta}, Color::Black)},
                {City::Chicago, Parameters({City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal}, Color::Blue)},
                {City::Delhi, Parameters({City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata}, Color::Black)},
                {City::Essen, Parameters({City::London, City::Paris, City::Milan, City::StPetersburg}, Color::Blue)},
                {City::HoChiMinhCity, Parameters({City::Jakarta, City::Bangkok, City::HongKong, City::Manila}, Color::Red)},
                {City::HongKong, Parameters({City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei}, Color::Red)},
                {City::Istanbul, Parameters({City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow}, Color::Black)},
                {City::Jakarta, Parameters({City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney}, Color::Red)},
                {City::Johannesburg, Parameters({City::Kinshasa, City::Khartoum}, Color::Yellow)},
                {City::Karachi, Parameters({City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi}, Color::Black)},
                {City::Khartoum, Parameters({City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg}, Color::Yellow)},
                {City::Kinshasa, Parameters({City::Lagos, City::Khartoum, City::Johannesburg}, Color::Yellow)},
                {City::Kolkata, Parameters({City::Delhi, City::Chennai, City::Bangkok, City::HongKong}, Color::Black)},
                {City::Lagos, Parameters({City::SaoPaulo, City::Khartoum, City::Kinshasa}, Color::Yellow)},
                {City::Lima, Parameters({City::MexicoCity, City::Bogota, City::Santiago}, Color::Yellow)},
                {City::London, Parameters({City::NewYork, City::Madrid, City::Essen, City::Paris}, Color::Blue)},
                {City::LosAngeles, Parameters({City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney}, Color::Yellow)},
                {City::Madrid, Parameters({City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers}, Color::Blue)},
                {City::Manila, Parameters({City::HongKong, City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney}, Color::Red)},
                {City::MexicoCity, Parameters({City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota}, Color::Yellow)},
                {City::Miami, Parameters({City::Atlanta, City::MexicoCity, City::Washington, City::Bogota}, Color::Yellow)},
                {City::Milan, Parameters({City::Essen, City::Paris, City::Istanbul}, Color::Blue)},
                {City::Montreal, Parameters({City::Chicago, City::Washington, City::NewYork}, Color::Blue)},
                {City::Moscow, Parameters({City::StPetersburg, City::Istanbul, City::Tehran}, Color::Black)},
                {City::Mumbai, Parameters({City::Karachi, City::Delhi, City::Chennai}, Color::Black)},
                {City::NewYork, Parameters({City::Montreal, City::Washington, City::London, City::Madrid}, Color::Blue)},
                {City::Osaka, Parameters({City::Taipei, City::Tokyo}, Color::Red)},
                {City::Paris, Parameters({City::Algiers, City::Essen, City::Madrid, City::Milan, City::London}, Color::Blue)},
                {City::Riyadh, Parameters({City::Baghdad, City::Cairo, City::Karachi}, Color::Black)},
                {City::SanFrancisco, Parameters({City::LosAngeles, City::Chicago, City::Tokyo, City::Manila}, Color::Blue)},
                {City::Santiago, Parameters({City::Lima}, Color::Yellow)},
                {City::SaoPaulo, Parameters({City::Bogota, City::BuenosAires, City::Lagos, City::Madrid}, Color::Yellow)},
                {City::Seoul, Parameters({City::Beijing, City::Shanghai, City::Tokyo}, Color::Red)},
                {City::Shanghai, Parameters({City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo}, Color::Red)},
                {City::StPetersburg, Parameters({City::Essen, City::Istanbul, City::Moscow}, Color::Blue)},
                {City::Sydney, Parameters({City::Jakarta, City::Manila, City::LosAngeles}, Color::Red)},
                {City::Taipei, Parameters({City::Shanghai, City::HongKong, City::Osaka, City::Manila}, Color::Red)},
                {City::Tehran, Parameters({City::Baghdad, City::Moscow, City::Karachi, City::Delhi}, Color::Black)},
                {City::Tokyo, Parameters({City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco}, Color::Red)},
                {City::Washington, Parameters({City::Atlanta, City::NewYork, City::Montreal, City::Miami}, Color::Blue)}
        };
        bool is_clean();
        void remove_cures();
        void remove_stations();

        int& operator[](City city);
        friend std::ostream& operator<< (std::ostream& os, const Board& b);
    };
}