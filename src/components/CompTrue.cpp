/*
** EPITECH PROJECT, 2019
** NanoTekSpie
** File description:
** Cpp file for true components
*/

#include "components/CompTrue.hpp"

nts::Tristate nts::CompTrue::compute(std::size_t pin)
{
    (void)pin;
    return (nts::TRUE);
}

void nts::CompTrue::dump(void) const
{
}
