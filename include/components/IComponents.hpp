/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** IComponents.hpp
*/

#ifndef ICOMPONENTS_HPP_
#define ICOMPONENTS_HPP_

#include <string>
#include "ComponentType.hpp"

namespace nts {

    enum Tristate {
        UNDEFINED = 2,
        TRUE = true,
        FALSE = false
    };

    class Pin;
    class IComponent {
       public:
           virtual ~IComponent() = default;
           virtual nts::Tristate compute(std::size_t pin = 1) = 0;
           virtual void setLink(std::size_t pin, nts::IComponent *other,
                   std::size_t otherPin) = 0;
           virtual std::string getName(void) const = 0;
           virtual nts::ComponentType getType(void) const = 0;
           virtual void displayState(void) const = 0;
           virtual bool setNewState(int state) = 0;
           virtual Pin &getPin(std::size_t pin = 1) = 0;
           virtual size_t getNbPins(void) const = 0;
           virtual void dump() const = 0;
    };
}
#endif /* ifndef ICOMPONENTS_HPP_ */
