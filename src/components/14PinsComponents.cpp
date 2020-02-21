/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Cpp class declaring 14 pins components
*/

#include "components/14PinsComponents.hpp"

nts::Comp14Pins::Comp14Pins(const std::string &name, nts::ComponentType type)
    : Component(name, type,
                std::array<Pin, 14>{{{name + ":1", nullptr},
                                     {name + ":2", nullptr},
                                     {name + ":3", nullptr},
                                     {name + ":4", nullptr},
                                     {name + ":5", nullptr},
                                     {name + ":6", nullptr},
                                     {name + ":7", nullptr},
                                     {name + ":8", nullptr},
                                     {name + ":9", nullptr},
                                     {name + ":10", nullptr},
                                     {name + ":11", nullptr},
                                     {name + ":12", nullptr},
                                     {name + ":13", nullptr},
                                     {name + ":14", nullptr}}}) {
    for (int i = 0; i < 14; ++i) {
        this->IOPins[i].setOwnerComp(this);
    }
}
