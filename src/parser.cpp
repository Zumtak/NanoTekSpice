/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** parser
*/

#include <fstream>
#include <regex>
#include <string>
#include <unordered_map>
#include "NanoTekSpice.hpp"
#include "Parser.hpp"
#include "Factory.hpp"
#include "components/IComponents.hpp"

static std::string escape_spaces_around(const std::string &line)
{
    std::string tmp(std::regex_replace(line, std::regex("^ +"), ""));
    tmp = std::regex_replace(tmp, std::regex(" +$"), "");

    return (tmp);
}

static int getPinLink(const std::string &line)
{
    return (std::stoi(std::regex_replace(line, std::regex("(.*):"), "")));
}

static std::string getCompLink(const std::string &line)
{
    return (std::string(std::regex_replace(line, std::regex(":(.*)"), "")));
}

static std::string ltrim(const std::string& s)
{
    const std::string whitespaces = " \n\r\t\f\v";
	size_t start = s.find_first_not_of(whitespaces);
	return (start == std::string::npos) ? "" : s.substr(start);
}

static std::string rtrim(const std::string& s)
{
    const std::string whitespaces = " \n\r\t\f\v";
	size_t end = s.find_last_not_of(whitespaces);
	return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

static std::string trim(const std::string& s)
{
	return rtrim(ltrim(s));
}

bool nts::Parser::addLink(const std::string &line)
{
    std::string tmp = escape_spaces_around(line);
    std::string owner(std::regex_replace(tmp, std::regex(" (.*)"), ""));
    std::string target(std::regex_replace(tmp, std::regex("(.*) "), ""));
    std::string ownerName = getCompLink(owner);
    std::string targetName = getCompLink(target);
    auto it1 = this->buffComps.find(ownerName);
    auto it2 = this->buffComps.find(targetName);

    if (it1 == this->buffComps.end() || it2 == this->buffComps.end())
        return (false);
    this->buffComps[ownerName].get()->setLink(getPinLink(owner), this->buffComps[targetName], getPinLink(target));
    return (true);
}

bool nts::Parser::addChipset(const nts::Factory &factory, const std::string &line)
{
    if (line == "")
        return (true);
    std::string tmp = escape_spaces_around(line);
    std::string type(std::regex_replace(tmp, std::regex(" (.*)"), ""));
    std::string name(std::regex_replace(tmp, std::regex("(.*) "), ""));
    this->buffComps[name] = factory.createComponent(type, name);
    return (true);
}

void nts::Parser::Parsing(const std::string &filepath)
{
    nts::Factory factory;
    std::string line;
    std::ifstream fileStream(filepath);

    if (!fileStream.good()) {
        std::cout << "Problem with file :/" << std::endl;
        return;
    }
    while (std::getline(fileStream, line) && std::regex_match(line, std::regex("#(.*)"))) {}
    while (std::getline(fileStream, line)) {
        if (line != "\n")
            break;
    }
    line = trim(line);
    if (line != ".chipsets:") {
        std::cout << "No chipsets declaration" << std::endl;
        return;
    }
    while (std::getline(fileStream, line)) {
        line = trim(line);
        if (line == ".links:") {
            break;
        }
        if (addChipset(factory, line) == false)
            return;
    }
    while (std::getline(fileStream, line) && line != "") {
        if (addLink(line) == false)
            return;
    }
    std::cout << std::endl;
}

std::unordered_map<TYPE_COMPMAP_NANOTEK>& nts::Parser::getComponents(void)
{
    return this->buffComps;
}
