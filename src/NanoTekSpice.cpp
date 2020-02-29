/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Cpp file for NanoTekSpice object
*/

#include <algorithm>
#include <deque>
#include <functional>
#include <memory>
#include <regex>
#include <iostream>
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
    while (1) {
        this->simulate();
    }
}

void nts::NanoTekSpice::dump(void)
{
    size_t size = this->components.size();

    for (size_t i = 0; i < size; ++i) {
        std::cout << this->components[i].get()->getName() << " ("
        << nts::ComponentTypeString[this->components[i].get()->getType()] << ")" << " :\n";
        this->components[i]->dump();
        std::cout << "\n";
    }
    std::cout << std::endl;
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
    std::unordered_map<std::string, void (nts::NanoTekSpice::*)(void)>
    mapFunc {
        {"display", &nts::NanoTekSpice::display},
        {"simulate", &nts::NanoTekSpice::simulate},
        {"loop", &nts::NanoTekSpice::loop},
        {"dump", &nts::NanoTekSpice::dump}
    };

    for (size_t i = 0; i < size; ++i) {
        if (compName == this->components[i]->getName() && this->components[i]->getType() == nts::Input) {
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

void nts::NanoTekSpice::addComponent(std::unique_ptr<nts::IComponent> comp)
{
    this->components.emplace(this->components.size(), std::move(comp));
}
