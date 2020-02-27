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
#include <array>
#include "Pin.hpp"
#include "Wire.hpp"
#include "IComponents.hpp"
#include "ComponentType.hpp"

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
        protected:
            std::string name;
            nts::ComponentType type;
            std::array<Pin, TNbPins> IOPins;
    };
}

#endif
