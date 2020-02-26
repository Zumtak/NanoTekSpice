/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Main function
*/

#include <iostream>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cerr << "Error : No arguments provided\nUsage : ./nanotekspice [NTS_FILE] {INPUT(S) VALUES}" << std::endl;
        return (84);
    }
    return 0;
}
