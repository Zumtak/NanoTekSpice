/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Test file for Clock component
*/

#include "catch.hpp"
#include "components/CompClock.hpp"

TEST_CASE("Basic Clock test")
{
    nts::CompClock clock("my_clock");

    REQUIRE(clock.getPin(1).getState() == nts::FALSE);
    clock.compute();
    REQUIRE(clock.getPin(1).getState() == nts::TRUE);
}
