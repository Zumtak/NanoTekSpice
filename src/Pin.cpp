/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Pin class functions
*/

#include "Pin.hpp"
#include "IComponents.hpp"

nts::Pin::Pin(const std::string &name, IComponent *componentOwner)
{
    this->id = name;
    this->componentOwner = componentOwner;
}

void nts::Pin::setState(const Tristate &state)
{
    this->state = this->state << 2;
    this->state |= state;
}

nts::Tristate nts::Pin::getState(void) const
{
    nts::Tristate tmp = (nts::Tristate)(this->state & 252);
    return (tmp);
}

void nts::Pin::setWire(Wire *wire)
{
    if (wire == nullptr)
        return;
    this->wire = wire;
}

Wire *nts::Pin::getWire(void) const
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
