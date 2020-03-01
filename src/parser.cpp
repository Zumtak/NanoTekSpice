/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** parser
*/

#include <cstring>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "Parser.hpp"
#include "Factory.hpp"

namespace
{
bool goTo(std::ifstream& stream, const std::string str)
{
    std::string buffer;

    do
    {
    } while (getline(stream, buffer) && buffer != str);
    if (buffer == str)
    {
        return (true);
    }
    return (false);
}

bool getChipsets(std::ifstream &stream, std::unordered_map<size_t, std::unique_ptr<IComponent>> components)
{
    std::string buffer;
    char *token = NULL;

    if (!goTo(stream, ".chipsets:\n"))
    {
        std::cerr << "No .chipsets marker detected in file.\n";
        return (false);
    }
    while (getline(stream, buffer) && buffer != ".links:") {
        token = strtok((char*)buffer.c_str(), "\t ");
        if (token[0] == '#') {
            break;
        } else if (!nts::Factory::createComponent(token, strtok((char*)buffer.c_str(), "\t "))) {
            std::cerr << "Invalid component type detected.\n";
            return (false);
        }
    }
    return (true);
}

bool setLinks(std::ifstream& stream, std::unordered_map<size_t, std::unique_ptr<IComponent>> components)
{
    std::string buffer;
    char *token = NULL;
    std::vector<std::string> tokens;
    std::unique_ptr<nts::IComponent> eastComp;
    std::unique_ptr<nts::IComponent> westComp;

    while (getline(stream, buffer)) {
        token = strtok((char*)buffer.c_str(), "\t :");
        while (token) {
            token = strtok(NULL, "\t :");
            tokens.push_back(token);
        }
        eastComp = nts::NanoTekSpice::getComponent(tokens[0]);
        westComp = nts::NanoTekSpice::getComponent(tokens[2]);
        if (!westComp ==  || !eastComp) {
            std::cerr << "Undeclared component to link.\n";
            return (false);
        }
        eastComp.setLink((size_t)atoi(tokens[1]), westComp, (size_t)atoi(token[3]));
        }
    return (true);
}
};

bool nts::Parser::Parsing(std::string filepath, std::unordered_map<size_t, std::unique_ptr<IComponent>> components)
{
    std::ifstream stream;

    stream.open(filepath);
    if (!stream.is_open())
    {
        std::cerr << "A valid config file must be provided.\n";
        return (false);
    }
    if (getChipsets(stream, components))
    {
        return (setLinks(stream, components));
    }
    return (true);
}