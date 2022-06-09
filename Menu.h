#pragma once

#include <iostream>
#include <string>

#include "Traverser.h"

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

template <typename T>
class Print_menus : public List_traverser<Menu*> 
{
public:
    Print_menus(List<T>* list) :
        List_traverser(list) { }

    bool process_item(const T& item)
    {
        FL
        item->print();
        return true;
    }
};