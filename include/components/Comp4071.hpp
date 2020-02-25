/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Header file for component 4071
*/

#ifndef COMP4071_HPP_
#define COMP4071_HPP_

#include "components/14PinsComponents.hpp"
#include "components/IComponents.hpp"

namespace nts {
    class Comp4071 : public Comp14Pins {
        public:
            Comp4071(const std::string &name) : Comp14Pins(name, nts::COMP4071)
            {}
            nts::Tristate compute(std::size_t pin = 1) override;
            void dump() const override;
    };
}

#endif
