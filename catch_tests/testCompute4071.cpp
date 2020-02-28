/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Test for component 4071
*/

#include "catch.hpp"
#include "components/Comp4071.hpp"
#include "components/CompFalse.hpp"
#include "components/CompOutput.hpp"
#include "components/CompTrue.hpp"
#include "components/IComponents.hpp"

// ====================== Component 4071 : pin 3 ======================

TEST_CASE("Simple compute 4071 component : output 3 -> (1 | 1) = 1")
{
    nts::CompTrue i1("t1");
    nts::CompTrue i2("t2");
    nts::Comp4071 component("4071");
    nts::CompOutput o1("o1");

    i1.setLink(1, &component, 1);
    i2.setLink(1, &component, 2);
    component.setLink(3, &o1, 1);
    REQUIRE(o1.compute(1) == nts::TRUE);
    REQUIRE(component.getPin(3).getState() == nts::TRUE);
}

TEST_CASE("Simple compute 4071 component : output 3 -> (1 | 0) = 1")
{
    nts::CompTrue i1("t1");
    nts::CompFalse i2("f2");
    nts::Comp4071 component("4071");
    nts::CompOutput o1("o1");

    i1.setLink(1, &component, 1);
    i2.setLink(1, &component, 2);
    component.setLink(3, &o1, 1);
    REQUIRE(o1.compute(1) == nts::TRUE);
    REQUIRE(component.getPin(3).getState() == nts::TRUE);
}

TEST_CASE("Simple compute 4071 component : output 3 -> (0 | 1) = 1")
{
    nts::CompFalse i1("t1");
    nts::CompTrue i2("f2");
    nts::Comp4071 component("4071");
    nts::CompOutput o1("o1");

    i1.setLink(1, &component, 1);
    i2.setLink(1, &component, 2);
    component.setLink(3, &o1, 1);
    REQUIRE(o1.compute(1) == nts::TRUE);
    REQUIRE(component.getPin(3).getState() == nts::TRUE);
}

TEST_CASE("Simple compute 4071 component : output 3 -> (0 | 0) = 0")
{
    nts::CompFalse i1("t1");
    nts::CompFalse i2("f2");
    nts::Comp4071 component("4071");
    nts::CompOutput o1("o1");

    i1.setLink(1, &component, 1);
    i2.setLink(1, &component, 2);
    component.setLink(3, &o1, 1);
    REQUIRE(o1.compute(1) == nts::FALSE);
    REQUIRE(component.getPin(3).getState() == nts::FALSE);
}

// ====================== Component 4071 : pin 4 ======================

TEST_CASE("Simple compute 4071 component : output 4 -> (1 | 1) = 1")
{
    nts::CompTrue i1("t1");
    nts::CompTrue i2("t2");
    nts::Comp4071 component("4071");
    nts::CompOutput o1("o1");

    i1.setLink(1, &component, 5);
    i2.setLink(1, &component, 6);
    component.setLink(4, &o1, 1);
    REQUIRE(o1.compute(1) == nts::TRUE);
    REQUIRE(component.getPin(4).getState() == nts::TRUE);
}

TEST_CASE("Simple compute 4071 component : output 4 -> (1 | 0) = 1")
{
    nts::CompTrue i1("t1");
    nts::CompFalse i2("f2");
    nts::Comp4071 component("4071");
    nts::CompOutput o1("o1");

    i1.setLink(1, &component, 5);
    i2.setLink(1, &component, 6);
    component.setLink(4, &o1, 1);
    REQUIRE(o1.compute(1) == nts::TRUE);
    REQUIRE(component.getPin(4).getState() == nts::TRUE);
}

TEST_CASE("Simple compute 4071 component : output 4 -> (0 | 1) = 1")
{
    nts::CompFalse i1("t1");
    nts::CompTrue i2("f2");
    nts::Comp4071 component("4071");
    nts::CompOutput o1("o1");

    i1.setLink(1, &component, 5);
    i2.setLink(1, &component, 6);
    component.setLink(4, &o1, 1);
    REQUIRE(o1.compute(1) == nts::TRUE);
    REQUIRE(component.getPin(4).getState() == nts::TRUE);
}

TEST_CASE("Simple compute 4071 component : output 4 -> (0 | 0) = 0")
{
    nts::CompFalse i1("t1");
    nts::CompFalse i2("f2");
    nts::Comp4071 component("4071");
    nts::CompOutput o1("o1");

    i1.setLink(1, &component, 5);
    i2.setLink(1, &component, 6);
    component.setLink(4, &o1, 1);
    REQUIRE(o1.compute(1) == nts::FALSE);
    REQUIRE(component.getPin(4).getState() == nts::FALSE);
}

// ====================== Component 4071 : pin 10 ======================

TEST_CASE("Simple compute 4071 component : output 10 -> (1 | 1) = 1")
{
    nts::CompTrue i1("t1");
    nts::CompTrue i2("t2");
    nts::Comp4071 component("4071");
    nts::CompOutput o1("o1");

    i1.setLink(1, &component, 8);
    i2.setLink(1, &component, 9);
    component.setLink(10, &o1, 1);
    REQUIRE(o1.compute(1) == nts::TRUE);
    REQUIRE(component.getPin(10).getState() == nts::TRUE);
}

TEST_CASE("Simple compute 4071 component : output 10 -> (1 | 0) = 1")
{
    nts::CompTrue i1("t1");
    nts::CompFalse i2("f2");
    nts::Comp4071 component("4071");
    nts::CompOutput o1("o1");

    i1.setLink(1, &component, 8);
    i2.setLink(1, &component, 9);
    component.setLink(10, &o1, 1);
    REQUIRE(o1.compute(1) == nts::TRUE);
    REQUIRE(component.getPin(10).getState() == nts::TRUE);
}

TEST_CASE("Simple compute 4071 component : output 10 -> (0 | 1) = 1")
{
    nts::CompFalse i1("t1");
    nts::CompTrue i2("f2");
    nts::Comp4071 component("4071");
    nts::CompOutput o1("o1");

    i1.setLink(1, &component, 8);
    i2.setLink(1, &component, 9);
    component.setLink(10, &o1, 1);
    REQUIRE(o1.compute(1) == nts::TRUE);
    REQUIRE(component.getPin(10).getState() == nts::TRUE);
}

TEST_CASE("Simple compute 4071 component : output 10 -> (0 | 0) = 0")
{
    nts::CompFalse i1("t1");
    nts::CompFalse i2("f2");
    nts::Comp4071 component("4071");
    nts::CompOutput o1("o1");

    i1.setLink(1, &component, 8);
    i2.setLink(1, &component, 9);
    component.setLink(10, &o1, 1);
    REQUIRE(o1.compute(1) == nts::FALSE);
    REQUIRE(component.getPin(10).getState() == nts::FALSE);
}

// ====================== Component 4071 : pin 11 ======================

TEST_CASE("Simple compute 4071 component : output 11 -> (1 | 1) = 1")
{
    nts::CompTrue i1("t1");
    nts::CompTrue i2("t2");
    nts::Comp4071 component("4071");
    nts::CompOutput o1("o1");

    i1.setLink(1, &component, 12);
    i2.setLink(1, &component, 13);
    component.setLink(11, &o1, 1);
    REQUIRE(o1.compute(1) == nts::TRUE);
    REQUIRE(component.getPin(11).getState() == nts::TRUE);
}

TEST_CASE("Simple compute 4071 component : output 11 -> (1 | 0) = 1")
{
    nts::CompTrue i1("t1");
    nts::CompFalse i2("f2");
    nts::Comp4071 component("4071");
    nts::CompOutput o1("o1");

    i1.setLink(1, &component, 12);
    i2.setLink(1, &component, 13);
    component.setLink(11, &o1, 1);
    REQUIRE(o1.compute(1) == nts::TRUE);
    REQUIRE(component.getPin(11).getState() == nts::TRUE);
}

TEST_CASE("Simple compute 4071 component : output 11 -> (0 | 1) = 1")
{
    nts::CompFalse i1("t1");
    nts::CompTrue i2("f2");
    nts::Comp4071 component("4071");
    nts::CompOutput o1("o1");

    i1.setLink(1, &component, 12);
    i2.setLink(1, &component, 13);
    component.setLink(11, &o1, 1);
    REQUIRE(o1.compute(1) == nts::TRUE);
    REQUIRE(component.getPin(11).getState() == nts::TRUE);
}

TEST_CASE("Simple compute 4071 component : output 11 -> (0 | 0) = 0")
{
    nts::CompFalse i1("t1");
    nts::CompFalse i2("f2");
    nts::Comp4071 component("4071");
    nts::CompOutput o1("o1");

    i1.setLink(1, &component, 12);
    i2.setLink(1, &component, 13);
    component.setLink(11, &o1, 1);
    REQUIRE(o1.compute(1) == nts::FALSE);
    REQUIRE(component.getPin(11).getState() == nts::FALSE);
}
