/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Cpp file for component 4001
*/

#include "components/Comp4001.hpp"

nts::Tristate nts::Comp4001::compute(std::size_t pin)
{
    nts::Tristate tmp = nts::UNDEFINED;

    if (pin == 3)
        tmp = (nts::Tristate)!(this->IOPins[0].getState() | this->IOPins[1].getState());
    else if (pin == 4)
        tmp = (nts::Tristate)!(this->IOPins[4].getState() | this->IOPins[5].getState());
    else if (pin == 10)
        tmp = (nts::Tristate)!(this->IOPins[7].getState() | this->IOPins[8].getState());
    else if (pin == 11)
        tmp = (nts::Tristate)!(this->IOPins[11].getState() | this->IOPins[12].getState());
    if (tmp != nts::UNDEFINED && (pin == 3 || pin == 4 || pin == 10 || pin == 11))
        this->getPin(pin).setState(tmp);
    return (tmp);
}

void nts::Comp4001::dump(void) const
{
}
