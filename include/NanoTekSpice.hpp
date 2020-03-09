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

    #define TYPE_COMPMAP_NANOTEK std::string, std::unique_ptr<nts::IComponent>

    class NanoTekSpice {
        public:
            void display(void);
            bool setInputState(const std::string &nameOuput, int value);
            void setInputState(char **argv);
            void simulate(void);
            void loop(void);
            void dump(void);
            void prompt(void);
            void addComponents(std::unordered_map<std::string, std::unique_ptr<IComponent>> comps);
        protected:
            bool isGoodCommand(const std::string &name);
            std::unordered_map<std::string, std::unique_ptr<IComponent>> components;
    };
}

#endif
