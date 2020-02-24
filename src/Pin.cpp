/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Pin class functions
*/

#include <iostream>

#include "Pin.hpp"
#include "components/IComponents.hpp"

nts::Pin::Pin(const std::string &name, IComponent *componentOwner)
{
    this->id = name;
    this->componentOwner = componentOwner;
    this->currentState = nts::Tristate::UNDEFINED;
    this->oldState = nts::Tristate::UNDEFINED;
}

void nts::Pin::setState(Tristate state)
{
    this->oldState = this->currentState;
    this->currentState = state;
}

nts::Tristate nts::Pin::getState(void) const
{
    return (this->currentState);
}

void nts::Pin::setWire(Wire *wire)
{
    if (wire == nullptr)
        return;
    this->wire = wire;
}

nts::Wire *nts::Pin::getWire(void) const
{
    return (this->wire);
}

void nts::Pin::setOwnerComp(nts::IComponent *owner)
{
    if (owner == nullptr)
        return;
    this->componentOwner = owner;
}

nts::IComponent *nts::Pin::getOwnerComponent(void) const
{
    return (this->componentOwner);
}

std::string nts::Pin::getId(void) const
{
    return (this->id);
}
