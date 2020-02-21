/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** IComponents.hpp
*/

#ifndef ICOMPONENTS_HPP_
#define ICOMPONENTS_HPP_

#include <cstddef>
#include <string>

namespace nts {

    enum Tristate {
        UNDEFINED = 2,
        TRUE = true,
        FALSE = false
    };

    class IComponent {
       public:
           virtual ~IComponent() = default;
       public:
           virtual nts::Tristate compute(std::size_t pin = 1) = 0;
           virtual void setLink(std::size_t pin, nts::IComponent& other,
                   std::size_t otherPin) = 0;
           virtual void dump() const = 0;
    };
}
#endif /* ifndef ICOMPONENTS_HPP_ */
