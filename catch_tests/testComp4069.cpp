/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Tests for 4069 component
*/

#include "catch.hpp"
#include "components/Comp4069.hpp"
#include "components/IComponents.hpp"

TEST_CASE("Test component 4069 integrity and basic methods")
{
    nts::Comp4069 component("my_component");

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

// ===================== ENTRY TRUE ===========================

TEST_CASE("(true) Simple NOT with output 2")
{
    nts::Comp4069 component("my_component");

    component.getPin(1).setState(nts::TRUE);
    REQUIRE(component.compute(2) == nts::FALSE);
    REQUIRE(component.getPin(2).getState() == nts::FALSE);
}

TEST_CASE("(true) Simple NOT with output 4")
{
    nts::Comp4069 component("my_component");

    component.getPin(3).setState(nts::TRUE);
    REQUIRE(component.compute(4) == nts::FALSE);
    REQUIRE(component.getPin(4).getState() == nts::FALSE);
}

TEST_CASE("(true) Simple NOT with output 6")
{
    nts::Comp4069 component("my_component");

    component.getPin(5).setState(nts::TRUE);
    REQUIRE(component.compute(6) == nts::FALSE);
    REQUIRE(component.getPin(6).getState() == nts::FALSE);
}

TEST_CASE("(true) Simple NOT with output 8")
{
    nts::Comp4069 component("my_component");

    component.getPin(9).setState(nts::TRUE);
    REQUIRE(component.compute(8) == nts::FALSE);
    REQUIRE(component.getPin(8).getState() == nts::FALSE);
}

TEST_CASE("(true) Simple NOT with output 10")
{
    nts::Comp4069 component("my_component");

    component.getPin(11).setState(nts::TRUE);
    REQUIRE(component.compute(10) == nts::FALSE);
    REQUIRE(component.getPin(10).getState() == nts::FALSE);
}

TEST_CASE("(true) Simple NOT with output 13")
{
    nts::Comp4069 component("my_component");

    component.getPin(13).setState(nts::TRUE);
    REQUIRE(component.compute(12) == nts::FALSE);
    REQUIRE(component.getPin(12).getState() == nts::FALSE);
}

// ===================== ENTRY FALSE ===========================

TEST_CASE("(false) Simple NOT with output 2")
{
    nts::Comp4069 component("my_component");

    component.getPin(1).setState(nts::FALSE);
    REQUIRE(component.compute(2) == nts::TRUE);
    REQUIRE(component.getPin(2).getState() == nts::TRUE);
}

TEST_CASE("(false) Simple NOT with output 4")
{
    nts::Comp4069 component("my_component");

    component.getPin(3).setState(nts::FALSE);
    REQUIRE(component.compute(4) == nts::TRUE);
    REQUIRE(component.getPin(4).getState() == nts::TRUE);
}

TEST_CASE("(false) Simple NOT with output 6")
{
    nts::Comp4069 component("my_component");

    component.getPin(5).setState(nts::FALSE);
    REQUIRE(component.compute(6) == nts::TRUE);
    REQUIRE(component.getPin(6).getState() == nts::TRUE);
}

TEST_CASE("(false) Simple NOT with output 8")
{
    nts::Comp4069 component("my_component");

    component.getPin(9).setState(nts::FALSE);
    REQUIRE(component.compute(8) == nts::TRUE);
    REQUIRE(component.getPin(8).getState() == nts::TRUE);
}

TEST_CASE("(false) Simple NOT with output 10")
{
    nts::Comp4069 component("my_component");

    component.getPin(11).setState(nts::FALSE);
    REQUIRE(component.compute(10) == nts::TRUE);
    REQUIRE(component.getPin(10).getState() == nts::TRUE);
}

TEST_CASE("(false) Simple NOT with output 13")
{
    nts::Comp4069 component("my_component");

    component.getPin(13).setState(nts::FALSE);
    REQUIRE(component.compute(12) == nts::TRUE);
    REQUIRE(component.getPin(12).getState() == nts::TRUE);
}
