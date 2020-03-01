/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <vector>
#include "components/IComponents.hpp"

namespace nts {
    class Parser {
    public:
        Parser() = default;
        ~Parser() = default;
        bool Parsing(std::string filepath, nts::IComponent comp);
    };
}

#endif /* !PARSER_HPP_ */
