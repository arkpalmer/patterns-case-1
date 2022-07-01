#pragma once

#include <iostream>
#include <string>
#include <list>
#include <map>

#include "Traverser.h"

class Menu_item
{
public:
//    Menu_item() {} // just for testing other code

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

    // shouldn't Menu be abstract?

    virtual Iterator<Menu_item*>* create_iterator() const = 0;
    void print() const;

    virtual ~Menu();

private:
    std::string name_;
};

class Diner_menu : public Menu
{
public:
    Diner_menu();

    Diner_menu(const std::string& name);

    Iterator<Menu_item*>* create_iterator() const override;

    void add_item(const std::string& name, const std::string& desc, bool vegan, double price);

    virtual ~Diner_menu();

private:
    std::list<Menu_item*> items_; // maybe a pointer to - but lots of ripple changes
};


//
// Cafe_menu uses a different storage method - for demonstrating the iterator
//
class Cafe_menu : public Menu
{
public:
    Cafe_menu(const std::string& name);

    void add_item(const std::string& name, const std::string& desc, bool vegan, double price);

    Iterator<Menu_item*>* create_iterator() const override;

    virtual ~Cafe_menu();

private:
    using Item_pair = std::pair<std::string, Menu_item*>;
    //std::map<Item_pair> items_;
    std::map<std::string, Menu_item*> items_;
    //std::list<std::string, Menu_item*> items_;
};

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

