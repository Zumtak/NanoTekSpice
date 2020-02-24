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

    REQUIRE(inp.getPin(0).getState() == nts::UNDEFINED);
    inp.setNewState(nts::TRUE);
    REQUIRE(inp.getPin(0).getState() == nts::TRUE);
}
