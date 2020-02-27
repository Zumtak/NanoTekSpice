/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Header file for NanoTekSpice
*/

#ifndef NANOTEKSPICE_HPP_
#define NANOTEKSPICE_HPP_

#include <vector>
#include <memory>
#include "components/IComponents.hpp"

namespace nts {
    class NanoTekSpice {
        public:
            void display(void) const;
            bool setInputState(const std::string &nameOuput, int value);
            void simulate(void);
            void loop(void);
            void dump(void) const;
            void prompt(void);
        private:
            bool isGoodCommand(const std::string &name);
            std::vector<std::unique_ptr<IComponent>> components;
    };
}

#endif
