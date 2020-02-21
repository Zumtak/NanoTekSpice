/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** 14Pins Components class header
*/

#ifndef _14PINSCOMPONENTS_HPP_
#define _14PINSCOMPONENTS_HPP_

#include "Components.hpp"
#include <array>

namespace nts {
    class Comp14Pins : public Component<14> {
        public:
            Comp14Pins(const std::string &name, nts::ComponentType type);
    };
}

#endif
