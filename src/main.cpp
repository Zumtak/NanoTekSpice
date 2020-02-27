/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Main function
*/

#include "NanoTekSpice.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    (void) argv;
    nts::NanoTekSpice NanoTek;
    if (argc < 2) {
        std::cerr << "Error : No arguments provided\nUsage : ./nanotekspice [NTS_FILE] {INPUT(S) VALUES}" << std::endl;
        return (84);
    }
    NanoTek.prompt();
    return (0);
}
