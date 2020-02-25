/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Tests for component 4071
*/

#include "catch.hpp"
#include "components/Comp4071.hpp"
#include "components/IComponents.hpp"

TEST_CASE("Test component 4071 integrity and basic methods")
{
    nts::Comp4071 component("my_component");

    for (size_t i = 1; i < component.getPins().size() + 1; ++i) {
        REQUIRE(component.getPin(i).getState() == nts::UNDEFINED);
    }
    for (size_t i = 1; i < component.getPins().size() + 1; ++i) {
        REQUIRE(component.getPin(i).getId() == component.getName() +  ":" + std::to_string(i));
    }
    for (size_t i = 1; i < component.getPins().size() + 1; ++i) {
        component.getPin(i).setState(nts::Tristate::TRUE);
    }
    for (size_t i = 1; i < component.getPins().size() + 1; ++i) {
        REQUIRE(component.getPin(i).getState() == nts::Tristate::TRUE);
    }
    REQUIRE(component.getName() == "my_component");
}

// ========= OUPUT 3 TESTS =========

TEST_CASE("Simple OR with output 3 : 1 | 1 => 1")
{
    nts::Comp4071 component("my_component");

    component.getPin(1).setState(nts::TRUE);
    component.getPin(2).setState(nts::TRUE);
    REQUIRE(component.compute(3) == nts::TRUE);
    REQUIRE(component.getPin(3).getState() == nts::TRUE);
}

TEST_CASE("Simple OR with output 3 : 1 | 0 => 1")
{
    nts::Comp4071 component("my_component");

    component.getPin(1).setState(nts::TRUE);
    component.getPin(2).setState(nts::FALSE);
    REQUIRE(component.compute(3) == nts::TRUE);
    REQUIRE(component.getPin(3).getState() == nts::TRUE);
}

TEST_CASE("Simple OR with ouput 3 : 0 | 1 => 1")
{
    nts::Comp4071 component("my_component");

    component.getPin(1).setState(nts::FALSE);
    component.getPin(2).setState(nts::TRUE);
    REQUIRE(component.compute(3) == nts::TRUE);
    REQUIRE(component.getPin(3).getState() == nts::TRUE);
}

TEST_CASE("Simple OR with output 3 : 0 | 0 => 0")
{
    nts::Comp4071 component("my_component");

    component.getPin(1).setState(nts::FALSE);
    component.getPin(2).setState(nts::FALSE);
    REQUIRE(component.compute(3) == nts::FALSE);
    REQUIRE(component.getPin(3).getState() == nts::FALSE);
}

// =========================

// ========= OUPUT 4 TESTS =========

TEST_CASE("Simple OR with output 4 : 1 | 1 => 1")
{
    nts::Comp4071 component("my_component");

    component.getPin(5).setState(nts::TRUE);
    component.getPin(6).setState(nts::TRUE);
    REQUIRE(component.compute(4) == nts::TRUE);
    REQUIRE(component.getPin(4).getState() == nts::TRUE);
}

TEST_CASE("Simple OR with output 4 : 1 | 0 => 1")
{
    nts::Comp4071 component("my_component");

    component.getPin(5).setState(nts::TRUE);
    component.getPin(6).setState(nts::FALSE);
    REQUIRE(component.compute(4) == nts::TRUE);
    REQUIRE(component.getPin(4).getState() == nts::TRUE);
}

TEST_CASE("Simple OR with ouput 4 : 0 | 1 => 1")
{
    nts::Comp4071 component("my_component");

    component.getPin(5).setState(nts::FALSE);
    component.getPin(6).setState(nts::TRUE);
    REQUIRE(component.compute(4) == nts::TRUE);
    REQUIRE(component.getPin(4).getState() == nts::TRUE);
}

TEST_CASE("Simple OR with output 4 : 0 | 0 => 0")
{
    nts::Comp4071 component("my_component");

    component.getPin(5).setState(nts::FALSE);
    component.getPin(6).setState(nts::FALSE);
    REQUIRE(component.compute(4) == nts::FALSE);
    REQUIRE(component.getPin(4).getState() == nts::FALSE);
}

// =========================

// ========= OUPUT 10 TESTS =========

TEST_CASE("Simple OR with output 10 : 1 | 1 => 1")
{
    nts::Comp4071 component("my_component");

    component.getPin(8).setState(nts::TRUE);
    component.getPin(9).setState(nts::TRUE);
    REQUIRE(component.compute(10) == nts::TRUE);
    REQUIRE(component.getPin(10).getState() == nts::TRUE);
}

TEST_CASE("Simple OR with output 10 : 1 | 0 => 1")
{
    nts::Comp4071 component("my_component");

    component.getPin(8).setState(nts::TRUE);
    component.getPin(9).setState(nts::FALSE);
    REQUIRE(component.compute(10) == nts::TRUE);
    REQUIRE(component.getPin(10).getState() == nts::TRUE);
}

TEST_CASE("Simple OR with ouput 10 : 0 | 1 => 1")
{
    nts::Comp4071 component("my_component");

    component.getPin(8).setState(nts::FALSE);
    component.getPin(9).setState(nts::TRUE);
    REQUIRE(component.compute(10) == nts::TRUE);
    REQUIRE(component.getPin(10).getState() == nts::TRUE);
}

TEST_CASE("Simple OR with output 10 : 0 | 0 => 0")
{
    nts::Comp4071 component("my_component");

    component.getPin(8).setState(nts::FALSE);
    component.getPin(9).setState(nts::FALSE);
    REQUIRE(component.compute(10) == nts::FALSE);
    REQUIRE(component.getPin(10).getState() == nts::FALSE);
}

// =========================

// ========= OUPUT 11 TESTS =========

TEST_CASE("Simple OR with output 11 : 1 | 1 => 1")
{
    nts::Comp4071 component("my_component");

    component.getPin(12).setState(nts::TRUE);
    component.getPin(13).setState(nts::TRUE);
    REQUIRE(component.compute(11) == nts::TRUE);
    REQUIRE(component.getPin(11).getState() == nts::TRUE);
}

TEST_CASE("Simple OR with output 11 : 1 | 0 => 1")
{
    nts::Comp4071 component("my_component");

    component.getPin(12).setState(nts::TRUE);
    component.getPin(13).setState(nts::FALSE);
    REQUIRE(component.compute(11) == nts::TRUE);
    REQUIRE(component.getPin(11).getState() == nts::TRUE);
}

TEST_CASE("Simple OR with ouput 11 : 0 | 1 => 1")
{
    nts::Comp4071 component("my_component");

    component.getPin(12).setState(nts::FALSE);
    component.getPin(13).setState(nts::TRUE);
    REQUIRE(component.compute(11) == nts::TRUE);
    REQUIRE(component.getPin(11).getState() == nts::TRUE);
}

TEST_CASE("Simple OR with output 11 : 0 | 0 => 0")
{
    nts::Comp4071 component("my_component");

    component.getPin(12).setState(nts::FALSE);
    component.getPin(13).setState(nts::FALSE);
    REQUIRE(component.compute(11) == nts::FALSE);
    REQUIRE(component.getPin(11).getState() == nts::FALSE);
}

// =========================
