#include <iostream>
#include "components/CompInput.hpp"
#include "Pin.hpp"
#include "components/IComponents.hpp"

int main(void)
{
    nts::CompInput test("test");
    nts::Pin tmp = test.getPin(0);
    nts::Tristate tmpState = tmp.getState();

    std::cout << "pin state : " << tmpState << std::endl;
    return 0;
}
