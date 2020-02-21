/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Wire cpp file
*/

#include "Wire.hpp"
#include "Pin.hpp"

void nts::Wire::addPin(const nts::Pin &target, char end)
{
    if (end == 0)
        this->west.push_back(target);
    else
        this->east.push_back(target);
}
