/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Cpp file for output components
*/

#include <iostream>
#include "components/CompOutput.hpp"

void nts::CompOutput::displayState(void) const
{
    std::cout << this->getName() << ": " << this->IOPins[0].getState() << std::endl;
}

void nts::CompOutput::dump(void) const
{
}
