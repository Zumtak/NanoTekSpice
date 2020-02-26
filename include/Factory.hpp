/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Header file for factory class
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include <memory>
#include "components/Components.hpp"

namespace nts {
    #define MAP_TYPE std::string, std::unique_ptr<nts::IComponent> (*)(const std::string &)
    class Factory {
        public:
            static std::unique_ptr<IComponent> createComponent(const std::string &type,
                    const std::string &value);
            static nts::ComponentType getTypeFromString(const std::string &compName);
    };
}

#endif
