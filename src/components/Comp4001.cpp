/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Cpp file for component 4001
*/

#include "components/Comp4001.hpp"
#include "Wire.hpp"

nts::Tristate nts::Comp4001::compute(std::size_t pin)
{
    if (pin == 1)
        return ((nts::Tristate)!(this->IOPins[0].getState() || this->IOPins[0].getState()));
    else if (pin == 2)
        return ((nts::Tristate)!(this->IOPins[5].getState() || this->IOPins[6].getState()));
    else if (pin == 3)
        return ((nts::Tristate)!(this->IOPins[8].getState() || this->IOPins[9].getState()));
    else
        return ((nts::Tristate)!(this->IOPins[12].getState() || this->IOPins[13].getState()));
}

void nts::Comp4001::dump(void) const
{
}
