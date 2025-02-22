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

    if (pin == 3) {
        if (this->IOPins[0].getWire() != nullptr)
            this->IOPins[0].getWire()->computeOtherComponent(this->IOPins[0]);
        if (this->IOPins[1].getWire() != nullptr)
            this->IOPins[1].getWire()->computeOtherComponent(this->IOPins[1]);
        tmp = (nts::Tristate)!(this->IOPins[0].getState() | this->IOPins[1].getState());
    } else if (pin == 4) {
        if (this->IOPins[4].getWire() != nullptr)
            this->IOPins[4].getWire()->computeOtherComponent(this->IOPins[4]);
        if (this->IOPins[5].getWire() != nullptr)
            this->IOPins[5].getWire()->computeOtherComponent(this->IOPins[5]);
        tmp = (nts::Tristate)!(this->IOPins[4].getState() | this->IOPins[5].getState());
    } else if (pin == 10) {
        if (this->IOPins[7].getWire() != nullptr)
            this->IOPins[7].getWire()->computeOtherComponent(this->IOPins[7]);
        if (this->IOPins[8].getWire() != nullptr)
            this->IOPins[8].getWire()->computeOtherComponent(this->IOPins[8]);
        tmp = (nts::Tristate)!(this->IOPins[7].getState() | this->IOPins[8].getState());
    } else if (pin == 11) {
        if (this->IOPins[11].getWire() != nullptr)
            this->IOPins[11].getWire()->computeOtherComponent(this->IOPins[11]);
        if (this->IOPins[12].getWire() != nullptr)
            this->IOPins[12].getWire()->computeOtherComponent(this->IOPins[12]);
        tmp = (nts::Tristate)!(this->IOPins[11].getState() | this->IOPins[12].getState());
    }
    if (tmp != nts::UNDEFINED && (pin == 3 || pin == 4 || pin == 10 || pin == 11))
        this->getPin(pin).setState(tmp);
    return (tmp);
}
