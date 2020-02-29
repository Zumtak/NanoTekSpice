/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Main function
*/

#include <iostream>
#include "Factory.hpp"
#include "NanoTekSpice.hpp"
#include "components/ComponentType.hpp"
#include "components/CompClock.hpp"

int main(int argc, char *argv[])
{
    (void)argv;
    nts::NanoTekSpice NanoTek;

    if (argc < 2) {
        std::cerr << "Error : No arguments provided\nUsage : ./nanotekspice [NTS_FILE] {INPUT(S) VALUES}" << std::endl;
        return (84);
    }
    //NanoTek.prompt();
    nts::CompClock clock("tutu");
    clock.dump();
    clock.compute();
    clock.dump();
    return (0);
}
