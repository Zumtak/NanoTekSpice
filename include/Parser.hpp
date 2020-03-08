/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <unordered_map>
#include <vector>
#include "Factory.hpp"
#include "components/IComponents.hpp"
#include "NanoTekSpice.hpp"

namespace nts {
    class Parser {
        public:
            Parser() = default;
            ~Parser() = default;
            void Parsing(const std::string &filepath);
            std::unordered_map<TYPE_COMPMAP_NANOTEK>& getComponents(void);
        private:
            bool addChipset(const nts::Factory &factory, const std::string &line);
            bool addLink(const std::string &line);
            std::unordered_map<TYPE_COMPMAP_NANOTEK> buffComps;
    };
}

#endif /* !PARSER_HPP_ */
