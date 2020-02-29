/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Header file for input components
*/

#ifndef COMPINPUT_HPP_
#define COMPINPUT_HPP_

#include "components/1PinComponent.hpp"

namespace nts {
    class CompInput : public Comp1Pin {
        public:
            CompInput(const std::string &name) : Comp1Pin(name, nts::Input)
            {}
            nts::Tristate compute(std::size_t pin = 1) override;
            bool setNewState(int state) override;
    };
}

#endif
