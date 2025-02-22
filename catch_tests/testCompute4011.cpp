/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** Medium tests components : Compute
*/

#include "catch.hpp"
#include "components/Comp4011.hpp"
#include "components/CompFalse.hpp"
#include "components/CompOutput.hpp"
#include "components/CompTrue.hpp"
#include "components/IComponents.hpp"

// ====================== Component 4011 : pin 3 ======================

TEST_CASE("Simple compute 4011 component : output 3 -> !(1 & 1) = 0")
{
    std::unique_ptr<nts::IComponent> i1 = std::make_unique<nts::CompTrue>("t1");
    std::unique_ptr<nts::IComponent> i2 = std::make_unique<nts::CompTrue>("t2");
    std::unique_ptr<nts::IComponent> component = std::make_unique<nts::Comp4011>("4011");
    std::unique_ptr<nts::IComponent> o1 = std::make_unique<nts::CompOutput>("o1");

    i1->setLink(1, component, 1);
    i2->setLink(1, component, 2);
    component->setLink(3, o1, 1);
    REQUIRE(o1->compute(1) == nts::FALSE);
    REQUIRE(component->getPin(3).getState() == nts::FALSE);
}

TEST_CASE("Simple compute 4011 component : output 3 -> !(1 & 0) = 1")
{
    std::unique_ptr<nts::IComponent> i1 = std::make_unique<nts::CompTrue>("t1");
    std::unique_ptr<nts::IComponent> i2 = std::make_unique<nts::CompFalse>("f2");
    std::unique_ptr<nts::IComponent> component = std::make_unique<nts::Comp4011>("4011");
    std::unique_ptr<nts::IComponent> o1 = std::make_unique<nts::CompOutput>("o1");

    i1->setLink(1, component, 1);
    i2->setLink(1, component, 2);
    component->setLink(3, o1, 1);
    REQUIRE(o1->compute(1) == nts::TRUE);
    REQUIRE(component->getPin(3).getState() == nts::TRUE);
}

TEST_CASE("Simple compute 4011 component : output 3 -> !(0 & 1) = 1")
{
    std::unique_ptr<nts::IComponent> i1 = std::make_unique<nts::CompFalse>("t1");
    std::unique_ptr<nts::IComponent> i2 = std::make_unique<nts::CompTrue>("f2");
    std::unique_ptr<nts::IComponent> component = std::make_unique<nts::Comp4011>("4011");
    std::unique_ptr<nts::IComponent> o1 = std::make_unique<nts::CompOutput>("o1");

    i1->setLink(1, component, 1);
    i2->setLink(1, component, 2);
    component->setLink(3, o1, 1);
    REQUIRE(o1->compute(1) == nts::TRUE);
    REQUIRE(component->getPin(3).getState() == nts::TRUE);
}

TEST_CASE("Simple compute 4011 component : output 3 -> !(0 & 0) = 1")
{
    std::unique_ptr<nts::IComponent> i1 = std::make_unique<nts::CompFalse>("t1");
    std::unique_ptr<nts::IComponent> i2 = std::make_unique<nts::CompFalse>("f2");
    std::unique_ptr<nts::IComponent> component = std::make_unique<nts::Comp4011>("4011");
    std::unique_ptr<nts::IComponent> o1 = std::make_unique<nts::CompOutput>("o1");

    i1->setLink(1, component, 1);
    i2->setLink(1, component, 2);
    component->setLink(3, o1, 1);
    REQUIRE(o1->compute(1) == nts::TRUE);
    REQUIRE(component->getPin(3).getState() == nts::TRUE);
}

// ====================== Component 4011 : pin 4 ======================

TEST_CASE("Simple compute 4011 component : output 4 -> !(1 & 1) = 0")
{
    std::unique_ptr<nts::IComponent> i1 = std::make_unique<nts::CompTrue>("t1");
    std::unique_ptr<nts::IComponent> i2 = std::make_unique<nts::CompTrue>("t2");
    std::unique_ptr<nts::IComponent> component = std::make_unique<nts::Comp4011>("4011");
    std::unique_ptr<nts::IComponent> o1 = std::make_unique<nts::CompOutput>("o1");

    i1->setLink(1, component, 5);
    i2->setLink(1, component, 6);
    component->setLink(4, o1, 1);
    REQUIRE(o1->compute(1) == nts::FALSE);
    REQUIRE(component->getPin(4).getState() == nts::FALSE);
}

TEST_CASE("Simple compute 4011 component : output 4 -> !(1 & 0) = 1")
{
    std::unique_ptr<nts::IComponent> i1 = std::make_unique<nts::CompTrue>("t1");
    std::unique_ptr<nts::IComponent> i2 = std::make_unique<nts::CompFalse>("f2");
    std::unique_ptr<nts::IComponent> component = std::make_unique<nts::Comp4011>("4011");
    std::unique_ptr<nts::IComponent> o1 = std::make_unique<nts::CompOutput>("o1");

    i1->setLink(1, component, 5);
    i2->setLink(1, component, 6);
    component->setLink(4, o1, 1);
    REQUIRE(o1->compute(1) == nts::TRUE);
    REQUIRE(component->getPin(4).getState() == nts::TRUE);
}

TEST_CASE("Simple compute 4011 component : output 4 -> !(0 & 1) = 1")
{
    std::unique_ptr<nts::IComponent> i1 = std::make_unique<nts::CompFalse>("t1");
    std::unique_ptr<nts::IComponent> i2 = std::make_unique<nts::CompTrue>("f2");
    std::unique_ptr<nts::IComponent> component = std::make_unique<nts::Comp4011>("4011");
    std::unique_ptr<nts::IComponent> o1 = std::make_unique<nts::CompOutput>("o1");

    i1->setLink(1, component, 5);
    i2->setLink(1, component, 6);
    component->setLink(4, o1, 1);
    REQUIRE(o1->compute(1) == nts::TRUE);
    REQUIRE(component->getPin(4).getState() == nts::TRUE);
}

TEST_CASE("Simple compute 4011 component : output 4 -> !(0 & 0) = 1")
{
    std::unique_ptr<nts::IComponent> i1 = std::make_unique<nts::CompFalse>("t1");
    std::unique_ptr<nts::IComponent> i2 = std::make_unique<nts::CompFalse>("f2");
    std::unique_ptr<nts::IComponent> component = std::make_unique<nts::Comp4011>("4011");
    std::unique_ptr<nts::IComponent> o1 = std::make_unique<nts::CompOutput>("o1");

    i1->setLink(1, component, 5);
    i2->setLink(1, component, 6);
    component->setLink(4, o1, 1);
    REQUIRE(o1->compute(1) == nts::TRUE);
    REQUIRE(component->getPin(4).getState() == nts::TRUE);
}

// ====================== Component 4011 : pin 10 ======================

TEST_CASE("Simple compute 4011 component : output 10 -> !(1 & 1) = 0")
{
    std::unique_ptr<nts::IComponent> i1 = std::make_unique<nts::CompTrue>("t1");
    std::unique_ptr<nts::IComponent> i2 = std::make_unique<nts::CompTrue>("t2");
    std::unique_ptr<nts::IComponent> component = std::make_unique<nts::Comp4011>("4011");
    std::unique_ptr<nts::IComponent> o1 = std::make_unique<nts::CompOutput>("o1");

    i1->setLink(1, component, 8);
    i2->setLink(1, component, 9);
    component->setLink(10, o1, 1);
    REQUIRE(o1->compute(1) == nts::FALSE);
    REQUIRE(component->getPin(10).getState() == nts::FALSE);
}

TEST_CASE("Simple compute 4011 component : output 10 -> !(1 & 0) = 1")
{
    std::unique_ptr<nts::IComponent> i1 = std::make_unique<nts::CompTrue>("t1");
    std::unique_ptr<nts::IComponent> i2 = std::make_unique<nts::CompFalse>("f2");
    std::unique_ptr<nts::IComponent> component = std::make_unique<nts::Comp4011>("4011");
    std::unique_ptr<nts::IComponent> o1 = std::make_unique<nts::CompOutput>("o1");

    i1->setLink(1, component, 8);
    i2->setLink(1, component, 9);
    component->setLink(10, o1, 1);
    REQUIRE(o1->compute(1) == nts::TRUE);
    REQUIRE(component->getPin(10).getState() == nts::TRUE);
}

TEST_CASE("Simple compute 4011 component : output 10 -> !(0 & 1) = 1")
{
    std::unique_ptr<nts::IComponent> i1 = std::make_unique<nts::CompFalse>("t1");
    std::unique_ptr<nts::IComponent> i2 = std::make_unique<nts::CompTrue>("f2");
    std::unique_ptr<nts::IComponent> component = std::make_unique<nts::Comp4011>("4011");
    std::unique_ptr<nts::IComponent> o1 = std::make_unique<nts::CompOutput>("o1");

    i1->setLink(1, component, 8);
    i2->setLink(1, component, 9);
    component->setLink(10, o1, 1);
    REQUIRE(o1->compute(1) == nts::TRUE);
    REQUIRE(component->getPin(10).getState() == nts::TRUE);
}

TEST_CASE("Simple compute 4011 component : output 10 -> !(0 & 0) = 1")
{
    std::unique_ptr<nts::IComponent> i1 = std::make_unique<nts::CompFalse>("t1");
    std::unique_ptr<nts::IComponent> i2 = std::make_unique<nts::CompFalse>("f2");
    std::unique_ptr<nts::IComponent> component = std::make_unique<nts::Comp4011>("4011");
    std::unique_ptr<nts::IComponent> o1 = std::make_unique<nts::CompOutput>("o1");

    i1->setLink(1, component, 8);
    i2->setLink(1, component, 9);
    component->setLink(10, o1, 1);
    REQUIRE(o1->compute(1) == nts::TRUE);
    REQUIRE(component->getPin(10).getState() == nts::TRUE);
}

// ====================== Component 4011 : pin 11 ======================

TEST_CASE("Simple compute 4011 component : output 11 -> !(1 & 1) = 0")
{
    std::unique_ptr<nts::IComponent> i1 = std::make_unique<nts::CompTrue>("t1");
    std::unique_ptr<nts::IComponent> i2 = std::make_unique<nts::CompTrue>("t2");
    std::unique_ptr<nts::IComponent> component = std::make_unique<nts::Comp4011>("4011");
    std::unique_ptr<nts::IComponent> o1 = std::make_unique<nts::CompOutput>("o1");

    i1->setLink(1, component, 12);
    i2->setLink(1, component, 13);
    component->setLink(11, o1, 1);
    REQUIRE(o1->compute(1) == nts::FALSE);
    REQUIRE(component->getPin(11).getState() == nts::FALSE);
}

TEST_CASE("Simple compute 4011 component : output 11 -> !(1 & 0) = 1")
{
    std::unique_ptr<nts::IComponent> i1 = std::make_unique<nts::CompTrue>("t1");
    std::unique_ptr<nts::IComponent> i2 = std::make_unique<nts::CompFalse>("f2");
    std::unique_ptr<nts::IComponent> component = std::make_unique<nts::Comp4011>("4011");
    std::unique_ptr<nts::IComponent> o1 = std::make_unique<nts::CompOutput>("o1");

    i1->setLink(1, component, 12);
    i2->setLink(1, component, 13);
    component->setLink(11, o1, 1);
    REQUIRE(o1->compute(1) == nts::TRUE);
    REQUIRE(component->getPin(11).getState() == nts::TRUE);
}

TEST_CASE("Simple compute 4011 component : output 11 -> !(0 & 1) = 1")
{
    std::unique_ptr<nts::IComponent> i1 = std::make_unique<nts::CompFalse>("t1");
    std::unique_ptr<nts::IComponent> i2 = std::make_unique<nts::CompTrue>("f2");
    std::unique_ptr<nts::IComponent> component = std::make_unique<nts::Comp4011>("4011");
    std::unique_ptr<nts::IComponent> o1 = std::make_unique<nts::CompOutput>("o1");

    i1->setLink(1, component, 12);
    i2->setLink(1, component, 13);
    component->setLink(11, o1, 1);
    REQUIRE(o1->compute(1) == nts::TRUE);
    REQUIRE(component->getPin(11).getState() == nts::TRUE);
}

TEST_CASE("Simple compute 4011 component : output 11 -> !(0 & 0) = 1")
{
    std::unique_ptr<nts::IComponent> i1 = std::make_unique<nts::CompFalse>("t1");
    std::unique_ptr<nts::IComponent> i2 = std::make_unique<nts::CompFalse>("f2");
    std::unique_ptr<nts::IComponent> component = std::make_unique<nts::Comp4011>("4011");
    std::unique_ptr<nts::IComponent> o1 = std::make_unique<nts::CompOutput>("o1");

    i1->setLink(1, component, 12);
    i2->setLink(1, component, 13);
    component->setLink(11, o1, 1);
    REQUIRE(o1->compute(1) == nts::TRUE);
    REQUIRE(component->getPin(11).getState() == nts::TRUE);
}
