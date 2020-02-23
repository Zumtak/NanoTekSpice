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

namespace nts {
    enum ComponentType {
        Clock = 0,
        Input,
        True,
        False,
        Output,
        Comp4001,
        Comp4008,
        Comp4011,
        Comp4013,
        Comp4017,
        Comp4030,
        Comp4040,
        Comp4069,
        Comp4071,
        Comp4081,
        Comp4094,
        Comp4514,
        Comp4801,
        Comp2716
    };
    std::array<std::string, 19> const ComponentTypeString {
        "Clock",
        "Input",
        "True",
        "False",
        "Output",
        "Comp4001",
        "Comp4008",
        "Comp4011",
        "Comp4013",
        "Comp4017",
        "Comp4030",
        "Comp4040",
        "Comp4069",
        "Comp4071",
        "Comp4081",
        "Comp4094",
        "Comp4514",
        "Comp4801",
        "Comp2716"
    };
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
            nts::ComponentType getType(void) const
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
            std::array<Pin, TNbPins> getPins(void)
            {
                return (this->IOPins);
            }
            Pin getPin(std::size_t pin = 1)
            {
                if (this->IOPins.size() > pin)
                    return (this->IOPins[1]);
                return (this->IOPins[pin]);
            }
        protected:
            std::string name;
            nts::ComponentType type;
            std::array<Pin, TNbPins> IOPins;
    };
}

#endif
