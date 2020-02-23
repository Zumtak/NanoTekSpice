/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Header file for clock component
*/

#ifndef COMPCLOCK_HPP_
#define COMPCLOCK_HPP_

#include "components/1PinComponent.hpp"

namespace nts {
    class CompClock : public Comp1Pin {
        CompClock(const std::string &name) : Comp1Pin(name, nts::Clock)
        {}
        nts::Tristate compute(std::size_t pin = 1) override;
        void dump(void) const override;
    };
}

#endif
