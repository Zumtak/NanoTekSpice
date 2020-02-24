/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Test file for false component
*/

#include "catch.hpp"
#include "components/CompFalse.hpp"

TEST_CASE("Basic false test")
{
    nts::CompFalse falseComp("my_false");

    REQUIRE(falseComp.getPin(1).getState() == nts::FALSE);
}
