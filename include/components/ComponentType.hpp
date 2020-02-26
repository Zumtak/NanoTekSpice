/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Define type string and enum for components
*/

#ifndef COMPONENTTYPE_HPP_
#define COMPONENTTYPE_HPP_

#include <string>
#include <array>

namespace nts {
    enum ComponentType {
        Clock = 0,
        Input,
        True,
        False,
        Output,
        COMP4001,
        COMP4008,
        COMP4011,
        COMP4013,
        COMP4017,
        COMP4030,
        COMP4040,
        COMP4069,
        COMP4071,
        COMP4081,
        COMP4094,
        COMP4514,
        COMP4801,
        COMP2716,
        UNKNOW
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

}

#endif
