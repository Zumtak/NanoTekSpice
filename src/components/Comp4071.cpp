/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Cpp file for component 4071
*/

#include "components/Comp4071.hpp"
#include "components/IComponents.hpp"

nts::Tristate nts::Comp4071::compute(std::size_t pin)
{
    nts::Tristate tmp = nts::UNDEFINED;

    if (pin == 3)
        tmp = (nts::Tristate)((this->IOPins[0].getState() & 1) | (this->IOPins[1].getState() & 1));
    else if (pin == 4)
        tmp = (nts::Tristate)((this->IOPins[4].getState() & 1) | (this->IOPins[5].getState() & 1));
    else if (pin == 10)
        tmp = (nts::Tristate)((this->IOPins[7].getState() & 1) | (this->IOPins[8].getState() & 1));
    else if (pin == 11)
        tmp = (nts::Tristate)((this->IOPins[11].getState() & 1) | (this->IOPins[12].getState() & 1));
    if (tmp != nts::UNDEFINED && (pin == 3 || pin == 4 || pin == 10 || pin == 11))
        this->IOPins[pin - 1].setState(tmp);
    return (tmp);
}

void nts::Comp4071::dump() const
{
}
