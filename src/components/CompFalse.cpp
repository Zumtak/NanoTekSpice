/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Cpp file for false components
*/

#include "components/CompFalse.hpp"
#include "components/IComponents.hpp"

nts::Tristate nts::CompFalse::compute(size_t pin)
{
    (void) pin;
    return (nts::FALSE);
}

void nts::CompFalse::dump(void) const
{
}
