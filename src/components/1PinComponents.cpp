/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Cpp class declaring 1 pin components
*/

#include "components/1PinComponent.hpp"
#include "components/Components.hpp"

nts::Comp1Pin::Comp1Pin(const std::string &name, nts::ComponentType type)
    : Component(name, type, std::array<Pin, 1>{{{name + ":1", nullptr, 1}}})
{
    this->IOPins[0].setOwnerComp(this);
}

void nts::Comp1Pin::dump(void) const
{
    nts::Tristate tmp = nts::UNDEFINED;

    std::cout << std::setw(18) << "----------" << "\n";
    std::cout << std::setw(8) << std::right << "|";
    std::cout << std::setw(11) << std::right << "|";
    std::cout << "\n";
    tmp = this->IOPins[0].getState();
    if (tmp == 2)
        std::cout << std::setw(3) << std::right << YELLOW
                  << "(" + std::to_string(tmp) + ")";
    else if (tmp == 1)
        std::cout << std::setw(3) << std::right << GREEN
                  << "(" + std::to_string(tmp) + ")";
    else
        std::cout << std::setw(3) << std::right << RED
                  << "(" + std::to_string(tmp) + ")";
    std::cout << RESET;
    std::cout << std::setw(2) << std::right << pinNames[0];
    std::cout << std::setw(2) << std::right << "--|";
    std::cout << std::setw(2) << std::right << std::to_string(1);
    std::cout << std::setw(9) << std::right << "|";
    std::cout << "\n";
    std::cout << std::setw(8) << std::right << "|";
    std::cout << std::setw(11) << std::right << "|";
    std::cout << "\n";
    std::cout << std::setw(18) << "----------" << "\n";
}
