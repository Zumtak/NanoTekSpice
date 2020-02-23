/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Cpp file for input component
*/

#include "components/CompInput.hpp"
#include "components/IComponents.hpp"

nts::Tristate nts::CompInput::compute(std::size_t pin)
{
    (void)pin;
    return (this->IOPins[0].getState());
}

bool nts::CompInput::setNewState(int state)
{
    if (state == -1)
        state = nts::Tristate::UNDEFINED;
    if (state > 2 || state < -1)
        return (false);
    this->IOPins[0].setState((nts::Tristate)state);
    return (true);
}

void nts::CompInput::dump(void) const
{
}
