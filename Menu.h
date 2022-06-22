#pragma once

#include <iostream>
#include <string>
#include <list>

#include "Traverser.h"

class Menu_item
{
public:
    Menu_item(const std::string& name, const std::string& desc, bool vegan, double price) :
        name_(name), description_(desc), vegan_(vegan), price_(price) {}

    std::string name() const { return name_; }
    double price() const     { return price_; }
    std::string description() const { return description_; }
    bool is_vegan() const    { return vegan_; }

private:
    std::string name_;
    std::string description_;
    bool        vegan_;
    double      price_;
};

class Menu
{
public:
    Menu() { } 
    Menu(const std::string& name) : name_(name) { }

    void print() const;

    virtual ~Menu();

    void add_item(const std::string& name, const std::string& desc, bool vegan, double price);

private:
    std::string name_;
    std::list<Menu_item*> items_;
};

void Menu::add_item(const std::string& name, const std::string& desc, bool vegan, double price)
{
    items_.push_back(new Menu_item(name, desc, vegan, price));
}

Menu::~Menu()
{
    for (auto& item : items_)
    {
        delete item;
    }
}

void Menu::print() const
{
    std::cout << "Menu name: " << name_ << std::endl;

    std::cout << " items:" << std::endl;
    for (const auto& item : items_)
    {
        std::cout << "   " << item->name() << std::endl;
    }
}

class Diner_menu : public Menu
{
public:
    Diner_menu();

};

Diner_menu::Diner_menu()
{
//Menu_item(const std::string& name, const std::string& desc, bool vegan, double price) :
    add_item("Regular Pancake Breakfast", "Pancakes, 1 egg, 2 bacon", false, 2.99);
    add_item("Continental", "Oatmeal, fruit cup, muffin", true, 3.99);
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