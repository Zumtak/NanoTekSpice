/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Pin Header
*/

#ifndef PIN_HPP_
#define PIN_HPP_

#include <functional>
#include "components/IComponents.hpp"

namespace nts {
    class Wire;
    class Pin {
        public:
            Pin(const std::string &id, IComponent *componentOwner);
            void setState(const Tristate &state);
            Tristate getState(void) const;
            void setWire(nts::Wire *target);
            Wire *getWire(void) const;
            void setOwnerComp(IComponent *owner);
            IComponent *getOwnerComponent(void) const;
        private:
            std::string id;
            char state = nts::Tristate::UNDEFINED;
            IComponent *componentOwner;
            nts::Wire *wire = nullptr;
    };
}
#endif
