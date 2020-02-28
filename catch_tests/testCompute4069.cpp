/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Tests for compute method of 409 component
*/

#include "catch.hpp"
#include "components/Comp4069.hpp"
#include "components/CompTrue.hpp"
#include "components/CompFalse.hpp"
#include "components/CompOutput.hpp"
#include "components/IComponents.hpp"

// ====================== Component 4069 : pin 2 ======================

TEST_CASE("Simple compute 4069 component : output 2 -> !1 = 0 ; !0 = 1")
{
    nts::CompTrue i1("t1");
    nts::CompFalse i2("t2");
    nts::Comp4069 component1("4069");
    nts::Comp4069 component2("4069");
    nts::CompOutput o1("o1");
    nts::CompOutput o2("o2");

    i1.setLink(1, &component1, 1);
    i2.setLink(1, &component2, 1);
    component1.setLink(2, &o1, 1);
    component2.setLink(2, &o2, 1);
    REQUIRE(o1.compute(1) == nts::FALSE);
    REQUIRE(o2.compute(1) == nts::TRUE);
    REQUIRE(component1.getPin(2).getState() == nts::FALSE);
    REQUIRE(component2.getPin(2).getState() == nts::TRUE);
}

// ====================== Component 4069 : pin 4 ======================

TEST_CASE("Simple compute 4069 component : output 4 -> !1 = 0 ; !0 = 1")
{
    nts::CompTrue i1("t1");
    nts::CompFalse i2("t2");
    nts::Comp4069 component1("4069");
    nts::Comp4069 component2("4069");
    nts::CompOutput o1("o1");
    nts::CompOutput o2("o2");

    i1.setLink(1, &component1, 3);
    i2.setLink(1, &component2, 3);
    component1.setLink(4, &o1, 1);
    component2.setLink(4, &o2, 1);
    REQUIRE(o1.compute(1) == nts::FALSE);
    REQUIRE(o2.compute(1) == nts::TRUE);
    REQUIRE(component1.getPin(4).getState() == nts::FALSE);
    REQUIRE(component2.getPin(4).getState() == nts::TRUE);
}

// ====================== Component 4069 : pin 6 ======================

TEST_CASE("Simple compute 4069 component : output 6 -> !1 = 0 ; !0 = 1")
{
    nts::CompTrue i1("t1");
    nts::CompFalse i2("t2");
    nts::Comp4069 component1("4069");
    nts::Comp4069 component2("4069");
    nts::CompOutput o1("o1");
    nts::CompOutput o2("o2");

    i1.setLink(1, &component1, 5);
    i2.setLink(1, &component2, 5);
    component1.setLink(6, &o1, 1);
    component2.setLink(6, &o2, 1);
    REQUIRE(o1.compute(1) == nts::FALSE);
    REQUIRE(o2.compute(1) == nts::TRUE);
    REQUIRE(component1.getPin(6).getState() == nts::FALSE);
    REQUIRE(component2.getPin(6).getState() == nts::TRUE);
}

// ====================== Component 4069 : pin 8 ======================

TEST_CASE("Simple compute 4069 component : output 8 -> !1 = 0 ; !0 = 1")
{
    nts::CompTrue i1("t1");
    nts::CompFalse i2("t2");
    nts::Comp4069 component1("4069");
    nts::Comp4069 component2("4069");
    nts::CompOutput o1("o1");
    nts::CompOutput o2("o2");

    i1.setLink(1, &component1, 9);
    i2.setLink(1, &component2, 9);
    component1.setLink(8, &o1, 1);
    component2.setLink(8, &o2, 1);
    REQUIRE(o1.compute(1) == nts::FALSE);
    REQUIRE(o2.compute(1) == nts::TRUE);
    REQUIRE(component1.getPin(8).getState() == nts::FALSE);
    REQUIRE(component2.getPin(8).getState() == nts::TRUE);
}

// ====================== Component 4069 : pin 10 ======================

TEST_CASE("Simple compute 4069 component : output 10 -> !1 = 0 ; !0 = 1")
{
    nts::CompTrue i1("t1");
    nts::CompFalse i2("t2");
    nts::Comp4069 component1("4069");
    nts::Comp4069 component2("4069");
    nts::CompOutput o1("o1");
    nts::CompOutput o2("o2");

    i1.setLink(1, &component1, 11);
    i2.setLink(1, &component2, 11);
    component1.setLink(10, &o1, 1);
    component2.setLink(10, &o2, 1);
    REQUIRE(o1.compute(1) == nts::FALSE);
    REQUIRE(o2.compute(1) == nts::TRUE);
    REQUIRE(component1.getPin(10).getState() == nts::FALSE);
    REQUIRE(component2.getPin(10).getState() == nts::TRUE);
}

// ====================== Component 4069 : pin 12 ======================

TEST_CASE("Simple compute 4069 component : output 12 -> !1 = 0 ; !0 = 1")
{
    nts::CompTrue i1("t1");
    nts::CompFalse i2("t2");
    nts::Comp4069 component1("4069");
    nts::Comp4069 component2("4069");
    nts::CompOutput o1("o1");
    nts::CompOutput o2("o2");

    i1.setLink(1, &component1, 13);
    i2.setLink(1, &component2, 13);
    component1.setLink(12, &o1, 1);
    component2.setLink(12, &o2, 1);
    REQUIRE(o1.compute(1) == nts::FALSE);
    REQUIRE(o2.compute(1) == nts::TRUE);
    REQUIRE(component1.getPin(12).getState() == nts::FALSE);
    REQUIRE(component2.getPin(12).getState() == nts::TRUE);
}
