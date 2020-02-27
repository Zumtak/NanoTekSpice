/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Cpp file for NanoTekSpice object
*/

#include <regex>
#include <iostream>
#include "NanoTekSpice.hpp"
#include "components/ComponentType.hpp"
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

void nts::NanoTekSpice::prompt(void)
{
    std::string command;

    std::cout << "NanoTekSpice > ";
    while (std::getline(std::cin, command) && command != "exit") {
        if (this->isGoodCommand(command) == false)
            std::cerr << command + " : Invalid command or component name\n";
        std::cout << "NanoTekSpice > ";
    }
    std::cout << std::endl;
}

bool nts::NanoTekSpice::isGoodCommand(const std::string &cmd)
{
    size_t size = this->components.size();
    std::string compName = std::regex_replace(cmd, std::regex("=(.*)"), "");

    for (size_t i = 0; i < size; ++i) {
        if (compName == this->components[i]->getName() && this->components[i]->getType() == nts::Input) {
            this->setInputState(compName, std::stoi(std::regex_replace(cmd, std::regex("(.*)="), "")));
            return (true);
        }
    }
    if (cmd != "exit" && cmd != "display" && cmd != "simulate" && cmd != "loop" && cmd != "dump")
        return (false);
    return (true);
}
