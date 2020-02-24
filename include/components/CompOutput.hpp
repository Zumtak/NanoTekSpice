/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Header file for output components
*/

#ifndef COMPOUTPUT_HPP_
#define COMPOUTPUT_HPP_

#include "components/1PinComponent.hpp"

namespace nts {
    class CompOutput : public Comp1Pin {
        public:
            CompOutput(const std::string &name) : Comp1Pin(name, nts::Output)
            {}
            nts::Tristate compute(std::size_t pin = 1) override;
            void displayState(void) const;
            void dump(void) const override;
    };
}

#endif
