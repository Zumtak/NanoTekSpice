/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Cpp class declaring 1 pin components
*/

#include "components/1PinComponent.hpp"
#include "components/Components.hpp"

nts::Comp1Pin::Comp1Pin(const std::string &name, nts::ComponentType type)
    : Component(name, type, std::array<Pin, 1>{{{name + ":1", nullptr, 1}}})
{
    this->IOPins[0].setOwnerComp(this);
}
