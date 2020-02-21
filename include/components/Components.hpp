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
        protected:
            std::string name;
            nts::ComponentType type;
            std::array<Pin, TNbPins> IOPins;
    };
}

#endif
