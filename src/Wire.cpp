/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Wire cpp file
*/

#include "Wire.hpp"
#include "Pin.hpp"

nts::Wire::Wire() : east{"", nullptr}, west{"", nullptr}
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
