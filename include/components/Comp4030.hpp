/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Header file for 4030 component
*/

#ifndef COMP4030_HPP_
#define COMP4030_HPP_

#include "components/14PinsComponents.hpp"

namespace nts {
    class Comp4030 : public Comp14Pins {
        public:
            Comp4030(const std::string &name) : Comp14Pins(name, nts::COMP4030)
            {
                pinNames = {"A", "B", "^AB", "^CD", "C", "D", "Vss", "E",
                "F", "^EF", "^GH", "G", "H", "Vdd"};
            }
            nts::Tristate compute(std::size_t pin = 1) override;
    };
}

#endif
