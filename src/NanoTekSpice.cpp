/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Cpp file for NanoTekSpice object
*/

#include <algorithm>
#include <memory>
#include <regex>
#include <iostream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <vector>
#include "NanoTekSpice.hpp"
#include "components/ComponentType.hpp"
#include "components/Components.hpp"
#include "components/IComponents.hpp"

void nts::NanoTekSpice::display(void)
{
    for (std::unordered_map<TYPE_COMPMAP_NANOTEK>::iterator it = this->components.begin();
            it != this->components.end(); ++it) {
        if (it->second->getType() == nts::Output)
            it->second->displayState();
    }
}

bool nts::NanoTekSpice::setInputState(const std::string &nameInput, int value)
{
    auto it = this->components.find(nameInput);

    if (it == this->components.end())
        return (false);
    return (it->second->setNewState(value));
}

void nts::NanoTekSpice::simulate(void)
{
    for (std::unordered_map<TYPE_COMPMAP_NANOTEK>::iterator it = this->components.begin();
            it != this->components.end(); ++it) {
        if (it->second->getType() == nts::Output)
            it->second->compute();
    }
}

void nts::NanoTekSpice::loop(void)
{
    while (1) {
        this->simulate();
    }
}

void nts::NanoTekSpice::dump(void)
{
    for (std::unordered_map<TYPE_COMPMAP_NANOTEK>::iterator it = this->components.begin();
            it != this->components.end(); ++it) {
        std::cout << it->second->getName() << " ("
        << nts::ComponentTypeString[it->second->getType()] << ")" << " :\n";
        it->second->dump();
        std::cout << "\n" << std::endl;
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
    std::string compName = std::regex_replace(cmd, std::regex("=(.*)"), "");
    std::unordered_map<std::string, void (nts::NanoTekSpice::*)(void)>
    mapFunc {
        {"display", &nts::NanoTekSpice::display},
        {"simulate", &nts::NanoTekSpice::simulate},
        {"loop", &nts::NanoTekSpice::loop},
        {"dump", &nts::NanoTekSpice::dump}
    };

    for (std::unordered_map<TYPE_COMPMAP_NANOTEK>::iterator it = this->components.begin();
            it != this->components.end(); ++it) {
        if (compName == it->second->getName() && it->second->getType() == nts::Input) {
            this->setInputState(compName, std::stoi(std::regex_replace(cmd, std::regex("(.*)="), "")));
            return (true);
        }
    }
    auto it = mapFunc.find(cmd);
    if (it == mapFunc.end())
        return (false);
    (this->*(it->second))();
    return (true);
}

void nts::NanoTekSpice::addComponents(std::unordered_map<TYPE_COMPMAP_NANOTEK> comps)
{
    for (std::unordered_map<TYPE_COMPMAP_NANOTEK>::iterator it = comps.begin();
            it != comps.end(); ++it) {
        this->components[it->first] = std::move(it->second);
    }
}
