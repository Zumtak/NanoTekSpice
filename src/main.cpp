/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Main function
*/

#include <iostream>
#include "Factory.hpp"
#include "NanoTekSpice.hpp"
#include "Parser.hpp"
#include "components/Comp4001.hpp"
#include "components/ComponentType.hpp"
#include "components/CompClock.hpp"
#include "components/IComponents.hpp"

int main(int argc, char *argv[])
{
    nts::Parser parser;
    nts::NanoTekSpice NanoTek;

    if (argc < 2) {
        std::cerr << "Error : No arguments provided\nUsage : ./nanotekspice [NTS_FILE] {INPUT(S) VALUES}" << std::endl;
        return (84);
    }
    parser.Parsing(argv[1]);
    NanoTek.addComponents(std::move(parser.getComponents()));
    NanoTek.prompt();
    return (0);
}
