/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Wire cpp file
*/

#include <iostream>
#include "Wire.hpp"
#include "Pin.hpp"
#include "components/IComponents.hpp"

nts::Wire::Wire() : east{"", nullptr, 0}, west{"", nullptr, 0}
{
}

void nts::Wire::addPin(const nts::Pin &me, const nts::Pin &target)
{
    this->west = me;
    this->east = target;
}

nts::Pin &nts::Wire::getOtherPin(const nts::Pin &me)
{
    if (this->east.getId() == me.getId())
        return (this->west);
    return (this->east);
}

nts::Tristate nts::Wire::computeOtherComponent(nts::Pin &me)
{
    nts::Tristate tmp = nts::UNDEFINED;

    if (this->east.getId() == me.getId()) {
        tmp = this->west.getOwnerComponent()->compute(this->west.getNbId());
        this->east.setState(tmp);
        me.setState(tmp);
        return (tmp);
    }
    tmp = this->east.getOwnerComponent()->compute(this->east.getNbId());
    this->west.setState(tmp);
    me.setState(tmp);
    return (tmp);
}
