/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Cpp file for output components
*/

#include "components/CompOutput.hpp"

void nts::CompOutput::displayState(void) const
{
    std::cout << this->getName() << ": " << this->IOPins[0].getState() << std::endl;
}

nts::Tristate nts::CompOutput::compute(std::size_t pin)
{
    Wire *tmp = this->getPin(pin).getWire();

    if (tmp != nullptr)
        this->getPin(pin).setState(this->getPin(pin).getWire()->computeOtherComponent(this->getPin(pin)));
    return (this->getPin(pin).getState());
}
