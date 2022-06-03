#pragma once

#include <iostream>
#include <string>

class Menu
{
public:
    Menu() { } 
    Menu(const std::string& name) : name_(name) { }

    void print() const;

private:
    std::string name_;
};

void Menu::print() const
{
    std::cout << "Menu name: " << name_ << std::endl;
}