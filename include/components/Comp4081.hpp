/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Header file for component 4081
*/

#ifndef COMP4081_HPP_
#define COMP4081_HPP_

#include "components/14PinsComponents.hpp"
#include "components/IComponents.hpp"

namespace nts {
    class Comp4081 : public Comp14Pins {
        public:
            Comp4081(const std::string &name) : Comp14Pins(name, nts::COMP4081)
            {}
            nts::Tristate compute(std::size_t pin = 1) override;
            void dump() const override;
    };
}

#endif
