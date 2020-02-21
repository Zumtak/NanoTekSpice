/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Cpp class declaring 24 pins components
*/

#include "components/24PinsComponents.hpp"

nts::Comp24Pins::Comp24Pins(const std::string &name, nts::ComponentType type)
    : Component(name, type, std::array<Pin, 24>{{{name + ":1", nullptr},
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
                                     {name + ":14", nullptr},
                                     {name + ":15", nullptr},
                                     {name + ":16", nullptr},
                                     {name + ":17", nullptr},
                                     {name + ":18", nullptr},
                                     {name + ":19", nullptr},
                                     {name + ":20", nullptr},
                                     {name + ":21", nullptr},
                                     {name + ":22", nullptr},
                                     {name + ":23", nullptr},
                                     {name + ":24", nullptr}}}) {
    for (int i = 0; i < 24; ++i) {
        this->IOPins[i].setOwnerComp(this);
    }
}
