/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Cpp file for 4069 component
*/

#include "components/Comp4069.hpp"

nts::Tristate nts::Comp4069::compute(std::size_t pin)
{
    nts::Tristate tmp = nts::UNDEFINED;

    if (pin == 2 || pin == 4 || pin == 6)
        tmp = (nts::Tristate)!(this->IOPins[pin - 2].getState());
    else if (pin == 8 || pin == 10 || pin == 12)
        tmp = (nts::Tristate)!(this->IOPins[pin].getState());
    if (tmp != nts::UNDEFINED)
        this->IOPins[pin - 1].setState(tmp);
    return (tmp);
}

void nts::Comp4069::dump() const
{
}
