/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Test file for output component
*/

#include "catch.hpp"
#include "components/CompOutput.hpp"

TEST_CASE("Basic output test")
{
    nts::CompOutput outputComp("my_output");

    REQUIRE(outputComp.getPin(0).getState() == nts::UNDEFINED);
}
