/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** 14Pins Components class header
*/

#ifndef _16PINSCOMPONENTS_HPP_
#define _16PINSCOMPONENTS_HPP_

#include "components/Components.hpp"
#include <string>

namespace nts {
    class Comp16Pins : public Component<16> {
        public:
            Comp16Pins(const std::string &name, nts::ComponentType type);
    };
}

#endif
