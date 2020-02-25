/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Test file for Input component
*/

#include "catch.hpp"
#include "components/CompInput.hpp"
#include "components/IComponents.hpp"

TEST_CASE("Basic input test")
{
    nts::CompInput inp("my_input");

    REQUIRE(inp.getPin(1).getState() == nts::Tristate::UNDEFINED);
    REQUIRE(inp.setNewState(nts::TRUE) == true);
    REQUIRE(inp.getPin(1).getState() == nts::Tristate::TRUE);
    REQUIRE(inp.setNewState(-1) == true);
    REQUIRE(inp.getPin(1).getState() == nts::Tristate::UNDEFINED);
    REQUIRE(inp.setNewState(69) == false);
}
