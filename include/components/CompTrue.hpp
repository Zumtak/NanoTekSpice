/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Header file for true components
*/

#ifndef COMPTRUE_HPP_
#define COMPTRUE_HPP_

#include "components/1PinComponent.hpp"

namespace nts {
    class CompTrue : public Comp1Pin {
        public:
            CompTrue(const std::string &name) : Comp1Pin(name, nts::Input)
            {
                this->IOPins[0].setState(nts::TRUE);
            }
            nts::Tristate compute(std::size_t pin = 1) override;
            void dump(void) const override;
    };
}

#endif
