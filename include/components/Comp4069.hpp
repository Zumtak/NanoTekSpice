/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Header file for 4069 component
*/

#ifndef COMP4069_HPP_
#define COMP4069_HPP_

#include "components/14PinsComponents.hpp"

namespace nts {
    class Comp4069 : public Comp14Pins {
        public:
            Comp4069(const std::string &name) : Comp14Pins(name, nts::COMP4069)
            {
                pinNames = {"A", "!A", "B", "!B", "C", "!C", "Vss", "E",
                "!E", "F", "!F", "G", "!G", "Vdd"};
            }
            nts::Tristate compute(std::size_t pin = 1) override;
    };
}

#endif
