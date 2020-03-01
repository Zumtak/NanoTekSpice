/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Header file for NanoTekSpice
*/

#ifndef NANOTEKSPICE_HPP_
#define NANOTEKSPICE_HPP_

#include <vector>
#include <unordered_map>
#include <memory>
#include "components/IComponents.hpp"

namespace nts {
    class NanoTekSpice {
        public:
            void display(void);
            bool setInputState(const std::string &nameOuput, int value);
            void simulate(void);
            void loop(void);
            void dump(void);
            void prompt(void);
            void addComponent(std::unique_ptr<IComponent> comp);
            size_t getComponent(const std::string &name);
        private:
            bool isGoodCommand(const std::string &name);
            std::unordered_map<size_t, std::unique_ptr<IComponent>> components;
    };
}

#endif
