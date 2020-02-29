/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Cpp file for factory class
*/

#include <algorithm>
#include <memory>
#include <unordered_map>
#include "Factory.hpp"
#include "components/CompFalse.hpp"
#include "components/CompInput.hpp"
#include "components/CompTrue.hpp"
#include "components/ComponentType.hpp"
#include "components/Components.hpp"
#include "components/CompClock.hpp"
#include "components/CompOutput.hpp"
#include "components/Comp4001.hpp"
#include "components/Comp4011.hpp"
#include "components/Comp4030.hpp"
#include "components/Comp4069.hpp"
#include "components/Comp4071.hpp"
#include "components/Comp4081.hpp"

template <typename T>
static std::unique_ptr<nts::IComponent> genComponent(const std::string &name)
{
    return (std::make_unique<T>(name));
}

std::unique_ptr<nts::IComponent> nts::Factory::createComponent(const std::string &type,
        const std::string &value)
{
    std::unordered_map<MAP_TYPE>::iterator it;
    std::unordered_map<MAP_TYPE>
    compMap {
        {"clock", genComponent<CompClock>},
        {"input", genComponent<CompInput>},
        {"true", genComponent<CompTrue>},
        {"false", genComponent<CompFalse>},
        {"output", genComponent<CompOutput>},
        {"4001", genComponent<Comp4001>},
        {"4011", genComponent<Comp4011>},
        {"4030", genComponent<Comp4030>},
        {"4069", genComponent<Comp4069>},
        {"4071", genComponent<Comp4071>},
        {"4081", genComponent<Comp4081>}
    };
    it = compMap.find(type);
    if (it == compMap.end()) {
        return (compMap["input"](value)); // MUST THROW EXCEPTION HERE
    }
    return (compMap[type](value));
}

nts::ComponentType nts::Factory::getTypeFromString(const std::string &compName)
{
    size_t i = 0;
    size_t size = ComponentTypeString.size();

    while (i < size && ComponentTypeString[i] != compName)
        ++i;
    return ((nts::ComponentType)i);
}
