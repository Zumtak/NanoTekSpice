/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Components Header
*/

#ifndef COMPONENTS_HPP_
#define COMPONENTS_HPP_

#include <cstddef>
#include <iostream>
#include <iomanip>
#include <array>
#include <string_view>
#include "Pin.hpp"
#include "Wire.hpp"
#include "IComponents.hpp"
#include "ComponentType.hpp"
#include "Color.hpp"

namespace nts {
    template <size_t TNbPins>
    class Component : public IComponent {
        public:
            Component(const std::string &name, nts::ComponentType type, const std::array<Pin, TNbPins> &IOPins)
                : name(name), type(type), IOPins(IOPins)
            {}
            std::string getName(void) const override
            {
                return (this->name);
            }
            nts::ComponentType getType(void) const override
            {
                return (this->type);
            }
            void setLink(std::size_t pin, nts::IComponent *other, std::size_t otherPin) override
            {
                Wire *tmp = nullptr;

                if (other->getPin(otherPin).getWire() != nullptr)
                    return;
                if (this->getPin(pin).getWire() == nullptr) {
                    this->getPin(pin).setWire(new Wire());
                }
                tmp = this->getPin(pin).getWire();
                tmp->addPin(this->getPin(pin), other->getPin(otherPin));
                other->getPin(otherPin).setWire(tmp);
            }
            std::array<Pin, TNbPins> &getPins(void)
            {
                return (this->IOPins);
            }
            Pin &getPin(std::size_t pin = 1) override
            {
                if (pin < 1 || pin > this->IOPins.size())
                    return (this->IOPins[0]);
                return (this->IOPins[pin - 1]);
            }
            size_t getNbPins() const override
            {
                return (this->IOPins.size());
            }
            void displayState(void) const override
            {}
            bool setNewState(int state) override
            {
                (void)state;
                return (true);
            }
            void dump() const override
            {
                nts::Tristate tmp = nts::UNDEFINED;

                std::cout << std::setw(34) << "--------------------" << "\n";
                std::cout << std::setw(14) << std::right << "|";
                std::cout << std::setw(21) << std::right << "|";
                std::cout << "\n";
                for (size_t i = 0; i < TNbPins / 2; ++i) {
                    tmp = this->IOPins[i].getState();
                    if (tmp == 2)
                        std::cout << std::setw(7) << std::right << YELLOW << "(" + std::to_string(tmp) + ")";
                    else if (tmp == 1)
                        std::cout << std::setw(7) << std::right << GREEN << "(" + std::to_string(tmp) + ")";
                    else
                        std::cout << std::setw(7) << std::right << RED << "(" + std::to_string(tmp) + ")";
                    std::cout << RESET;
                    std::cout << std::setw(4) << std::right << pinNames[i];
                    std::cout << std::setw(5) << std::right << "--|";
                    std::cout << std::setw(3) << std::right << std::to_string(i + 1);
                    std::cout << std::setw(16) << std::right << std::to_string(i + (TNbPins / 2 + 1));
                    std::cout << std::setw(6) << std::left << " |--";
                    std::cout << std::setw(4) << std::left << pinNames[i + (TNbPins / 2)];
                    tmp = this->IOPins[i + (TNbPins / 2)].getState();
                    if (tmp == 2)
                        std::cout << std::left << YELLOW << "(" + std::to_string(tmp) + ")";
                    else if (tmp == 1)
                        std::cout << std::left << GREEN << "(" + std::to_string(tmp) + ")";
                    else
                        std::cout << std::left << RED << "(" + std::to_string(tmp) + ")";
                    std::cout << RESET;
                    std::cout << "\n";
                    std::cout << std::setw(14) << std::right << "|";
                    std::cout << std::setw(21) << std::right << "|";
                    std::cout << "\n";
                }
                std::cout << std::setw(34) << "--------------------" << "\n";
            }
        protected:
            std::string name;
            nts::ComponentType type;
            std::array<Pin, TNbPins> IOPins;
            std::array<std::string_view, TNbPins> pinNames;
    };
}

#endif
