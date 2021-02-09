/*
** EPITECH PROJECT, 2019
** NanoTekSpice
** File description:
** File for Wire tests
*/

#include <iostream>
#include <memory>
#include "catch.hpp"
#include "Wire.hpp"
#include "components/Comp4001.hpp"
#include "components/Comp4011.hpp"

TEST_CASE("Add Pin function")
{
    nts::Wire tmp;
    nts::Pin pin1("pin1", nullptr, 1);
    nts::Pin pin2("pin2", nullptr, 2);

    tmp.addPin(pin1, pin2);
    REQUIRE(tmp.getOtherPin(pin1).getId() == "pin2");
}

TEST_CASE("Simple link between 2 components pin's")
{
    std::unique_ptr<nts::IComponent> comp1 = std::make_unique<nts::Comp4001>("comp1");
    std::unique_ptr<nts::IComponent> comp2 = std::make_unique<nts::Comp4011>("comp2");
    nts::Wire *tmp = nullptr;
    nts::Wire *tmp2 = nullptr;

    comp1->setLink(1, comp2, 1);
    REQUIRE(comp1->getPin(1).getWire() == comp2->getPin(1).getWire());
    tmp = comp1->getPin(1).getWire();
    tmp2 = comp2->getPin(1).getWire();
    REQUIRE(tmp == tmp2);
    REQUIRE(tmp->getOtherPin(comp1->getPin(1)).getId() == "comp2:1");
    REQUIRE(tmp->getOtherPin(comp2->getPin(1)).getId() == "comp1:1");
    REQUIRE(tmp2->getOtherPin(comp1->getPin(1)).getId() == "comp2:1");
    REQUIRE(tmp2->getOtherPin(comp2->getPin(1)).getId() == "comp1:1");
}
