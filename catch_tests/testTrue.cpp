/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Test file for true component
*/

#include "catch.hpp"
#include "components/CompTrue.hpp"

TEST_CASE("Basic true test")
{
    nts::CompTrue trueComp("my_true");

    REQUIRE(trueComp.getPin(1).getState() == nts::TRUE);
}
