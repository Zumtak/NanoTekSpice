/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Cpp class declaring 16 pins components
*/

#include "components/16PinsComponents.hpp"

nts::Comp16Pins::Comp16Pins(const std::string &name, nts::ComponentType type)
    : Component(name, type, std::array<Pin, 16>{{{name + ":1", nullptr, 1},
                                     {name + ":2", nullptr, 2},
                                     {name + ":3", nullptr, 3},
                                     {name + ":4", nullptr, 4},
                                     {name + ":5", nullptr, 5},
                                     {name + ":6", nullptr, 6},
                                     {name + ":7", nullptr, 7},
                                     {name + ":8", nullptr, 8},
                                     {name + ":9", nullptr, 9},
                                     {name + ":10", nullptr, 10},
                                     {name + ":11", nullptr, 11},
                                     {name + ":12", nullptr, 12},
                                     {name + ":13", nullptr, 13},
                                     {name + ":14", nullptr, 14},
                                     {name + ":15", nullptr, 15},
                                     {name + ":16", nullptr, 16}}}) {
    for (int i = 0; i < 16; ++i) {
        this->IOPins[i].setOwnerComp(this);
    }
}
