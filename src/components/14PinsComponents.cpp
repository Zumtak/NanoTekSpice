/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Cpp class declaring 14 pins components
*/

#include "components/14PinsComponents.hpp"

nts::Comp14Pins::Comp14Pins(const std::string &name, nts::ComponentType type)
    : Component(name, type,
                std::array<Pin, 14>{{{name + ":1", nullptr, 1},
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
                                     {name + ":14", nullptr, 14}}}) {
    for (int i = 0; i < 14; ++i) {
        this->IOPins[i].setOwnerComp(this);
    }
}
