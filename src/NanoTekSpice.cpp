/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Cpp file for NanoTekSpice object
*/

#include "NanoTekSpice.hpp"
#include "components/Components.hpp"
#include "components/IComponents.hpp"

void nts::NanoTekSpice::display(void) const
{
    size_t size = this->components.size();

    for (size_t i = 0; i < size; ++i) {
        if (this->components[i]->getType() == nts::Output)
            this->components[i]->displayState();
    }
}

bool nts::NanoTekSpice::setInputState(const std::string &nameInput, int value)
{
    size_t size = this->components.size();

    for (size_t i = 0; i < size; ++i) {
        if (this->components[i]->getName() == nameInput)
            return (this->components[i]->setNewState(value));
    }
    return (false);
}

void nts::NanoTekSpice::simulate(void)
{
    size_t size = this->components.size();

    for (size_t i = 0; i < size; ++i) {
        if (this->components[i]->getType() == nts::Output)
            this->components[i]->compute();
    }
}

void nts::NanoTekSpice::loop(void)
{
}

void nts::NanoTekSpice::dump(void) const
{
    size_t size = this->components.size();

    for (size_t i = 0; i < size; ++i) {
        this->components[i]->dump();
    }
}
