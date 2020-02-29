/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** 1Pins Components class header
*/

#ifndef _1PINSCOMPONENTS_HPP_
#define _1PINSCOMPONENTS_HPP_

#include "components/Components.hpp"
#include <string>

namespace nts {
    class Comp1Pin : public Component<1> {
        public:
            Comp1Pin(const std::string &name, nts::ComponentType type);
            void dump(void) const override;
    };
}

#endif
