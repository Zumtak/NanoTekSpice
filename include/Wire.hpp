/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Wire header
*/

#ifndef WIRE_HPP_
#define WIRE_HPP_

#include <vector>
#include "Pin.hpp"

namespace nts {
    class Wire {
        public:
            Wire();
            void addPin(const nts::Pin &me ,const nts::Pin &target);
            nts::Pin &getOtherPin(const nts::Pin &me);
        private:
            nts::Pin east;
            nts::Pin west;
    };
}

#endif
