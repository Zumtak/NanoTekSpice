/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Cpp file for clock components
*/

#include "components/CompClock.hpp"
#include "components/IComponents.hpp"

nts::Tristate nts::CompClock::compute(std::size_t pin)
{
    (void)pin;
    nts::Tristate tmp = this->IOPins[0].getState();

    if (tmp == nts::TRUE)
        this->IOPins[0].setState(nts::FALSE);
    else if (tmp == nts::FALSE)
        this->IOPins[0].setState(nts::TRUE);
    return (tmp);
}
