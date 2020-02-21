/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** 24Pins Components class header
*/

#ifndef _24PINSCOMPONENTS_HPP_
#define _24PINSCOMPONENTS_HPP_

#include "Components.hpp"
#include <array>

namespace nts {
    class Comp24Pins : public Component<24> {
        public:
            Comp24Pins(const std::string &name, nts::ComponentType type);
    };
}

#endif
