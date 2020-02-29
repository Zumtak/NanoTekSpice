/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Header for 4001 component
*/

#ifndef COMP4001_HPP_
#define COMP4001_HPP_

#include "components/14PinsComponents.hpp"

namespace nts {
    class Comp4001 : public Comp14Pins {
        public:
            Comp4001(const std::string &name) : Comp14Pins(name, nts::COMP4001)
            {
                pinNames = {"1A", "1B", "1Y", "2Y", "2A", "2B", "Vss", "3A",
                "3B", "3Y", "4Y", "4A", "4B", "Vdd"};
            }
            nts::Tristate compute(std::size_t pin = 1) override;
    };
}

#endif
