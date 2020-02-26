/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Components Header
*/

#ifndef COMPONENTS_HPP_
#define COMPONENTS_HPP_

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
            std::string getName(void) const
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

                --pin;
                --otherPin;
                Component<TNbPins>* otherCmp = dynamic_cast<Component *>(other);
                if (otherCmp->getPin(otherPin).getWire() != nullptr)
                    return;
                if (this->IOPins.size() < pin || otherCmp->getPins().size() < otherPin
                || pin < 0 || otherPin < 0)
                    return;
                if (this->IOPins[pin].getWire() == nullptr) {
                    this->IOPins[pin].setWire(new nts::Wire());
                }
                tmp = this->IOPins[pin].getWire();
                tmp->addPin(this->IOPins[pin], 0);
                tmp->addPin(otherCmp->getPin(otherPin), 1);
            }
            std::array<Pin, TNbPins> &getPins(void)
            {
                return (this->IOPins);
            }
            Pin &getPin(std::size_t pin = 1)
            {
                if (pin < 1)
                    return (this->IOPins[0]);
                return (this->IOPins[pin - 1]);
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
