/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Cpp file for component 4081
*/

#include "components/Comp4081.hpp"
#include "components/IComponents.hpp"

nts::Tristate nts::Comp4081::compute(std::size_t pin)
{
    nts::Tristate tmp = nts::UNDEFINED;

    if (pin == 3) {
        if (this->IOPins[0].getWire() != nullptr)
            this->IOPins[0].getWire()->computeOtherComponent(this->IOPins[0]);
        if (this->IOPins[1].getWire() != nullptr)
            this->IOPins[1].getWire()->computeOtherComponent(this->IOPins[1]);
        tmp = (nts::Tristate)((this->IOPins[0].getState() & 1) & (this->IOPins[1].getState() & 1));
    } else if (pin == 4) {
        if (this->IOPins[4].getWire() != nullptr)
            this->IOPins[4].getWire()->computeOtherComponent(this->IOPins[4]);
        if (this->IOPins[5].getWire() != nullptr)
            this->IOPins[5].getWire()->computeOtherComponent(this->IOPins[5]);
        tmp = (nts::Tristate)((this->IOPins[4].getState() & 1) & (this->IOPins[5].getState() & 1));
    } else if (pin == 10) {
        if (this->IOPins[7].getWire() != nullptr)
            this->IOPins[7].getWire()->computeOtherComponent(this->IOPins[7]);
        if (this->IOPins[8].getWire() != nullptr)
            this->IOPins[8].getWire()->computeOtherComponent(this->IOPins[8]);
        tmp = (nts::Tristate)((this->IOPins[7].getState() & 1) & (this->IOPins[8].getState() & 1));
    } else if (pin == 11) {
        if (this->IOPins[11].getWire() != nullptr)
            this->IOPins[11].getWire()->computeOtherComponent(this->IOPins[11]);
        if (this->IOPins[12].getWire() != nullptr)
            this->IOPins[12].getWire()->computeOtherComponent(this->IOPins[12]);
        tmp = (nts::Tristate)((this->IOPins[11].getState() & 1) & (this->IOPins[12].getState() & 1));
    }
    if (tmp != nts::UNDEFINED && (pin == 3 || pin == 4 || pin == 10 || pin == 11))
        this->IOPins[pin - 1].setState(tmp);
    return (tmp);
}

void nts::Comp4081::dump() const
{
}
