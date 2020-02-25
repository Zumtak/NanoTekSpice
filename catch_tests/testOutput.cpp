/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Test file for output component
*/

#include "catch.hpp"
#include "components/CompOutput.hpp"
#include "components/IComponents.hpp"

TEST_CASE("Basic output test")
{
    nts::CompOutput outputComp("my_output");

    REQUIRE(outputComp.getPin(1).getState() == nts::UNDEFINED);
    outputComp.getPin(1).setState(nts::TRUE);
    REQUIRE(outputComp.compute() == nts::TRUE);
    outputComp.getPin(1).setState(nts::FALSE);
    REQUIRE(outputComp.compute() == nts::FALSE);
}
