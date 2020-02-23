/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Header for 4001 component
*/

#ifndef COMP4001_HPP_
#define COMP4001_HPP_

#include "IComponents.hpp"
#include "components/14PinsComponents.hpp"

namespace nts {
    class Comp4001 : public Comp14Pins {
        Comp4001(const std::string &name) : Comp14Pins(name, nts::Comp4001)
        {}
        nts::Tristate compute(std::size_t pin = 1) override;
        void dump(void) const override;
    };
}

#endif
