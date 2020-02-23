/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Header file for 4011 component
*/

#ifndef COMP4011_HPP_
#define COMP4011_HPP_

#include "components/14PinsComponents.hpp"

namespace nts {
    class Comp4011 : public Comp14Pins {
        Comp4011(const std::string &name) : Comp14Pins(name, nts::Comp4011)
        {}
        nts::Tristate compute(std::size_t pin = 1) override;
        void dump() const override;
    };
}

#endif
