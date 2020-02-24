/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Pin class functions
*/

#include <iostream>
#include <string>

#include "Pin.hpp"
#include "components/IComponents.hpp"

nts::Pin::Pin(const std::string &name, IComponent *componentOwner)
{
    this->id = name;
    this->componentOwner = componentOwner;
    this->state = nts::UNDEFINED;
}

void nts::Pin::setState(const Tristate &state)
{
    this->state = this->state << 2;
    this->state |= state;
}

nts::Tristate nts::Pin::getState(void) const
{
    nts::Tristate tmp = (nts::Tristate)(this->state & 3);
    return (tmp);
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
