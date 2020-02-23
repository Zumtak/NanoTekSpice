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
            void addPin(const nts::Pin &target, char end);
        private:
            std::vector<nts::Pin> east;
            std::vector<nts::Pin> west;
    };
}

#endif
