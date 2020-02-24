/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Header file for false components
*/

#ifndef COMPFALSE_HPP_
#define COMPFALSE_HPP_

#include "components/1PinComponent.hpp"

namespace nts {
    class CompFalse : public Comp1Pin {
        public:
            CompFalse(const std::string &name) : Comp1Pin(name, nts::False)
            {
                this->IOPins[0].setState(nts::FALSE);
            }
            nts::Tristate compute(std::size_t pin = 1) override;
            void dump(void) const override;
    };
}

#endif
