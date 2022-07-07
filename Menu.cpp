#include <iostream>

#include "Menu.h"
#include "Menu_iterators.h"
#include "Utils.h"

using namespace std;

void delete_menu_items(Iterator<Menu_item*>* items_iter)
{
    while (!items_iter->is_done())
    {
        auto item = items_iter->current_item();
        //cout << "dtor: " << item->description() << endl;
        delete item;
        items_iter->next();
    }
}

void Menu_item::print() const
{
    cout << name_ << ": " << description_ << endl;
}

Menu::~Menu()
{
}

Diner_menu::Diner_menu(const std::string& name) :
    Menu(name)
{
    items_ = new std::list<Menu_item*>();

    add_item("Regular Pancake Breakfast", "Pancakes, 1 egg, 2 bacon", false, 2.99);
    add_item("Continental", "Oatmeal, fruit cup, muffin", true, 3.99);
}

Diner_menu::~Diner_menu()
{
    delete_menu_items(create_iterator());

    delete items_;
}

void Diner_menu::add_item(const std::string& name, const std::string& desc, bool vegan, double price)
{
    items_->push_back(new Menu_item(name, desc, vegan, price));
}

void Diner_menu::print() const 
{
    cout << name_ << " (Diner)" << endl;

    for (const auto& item : *items_)
    {
        item->print();
    }
}

Iterator<Menu_item*>* Diner_menu::create_iterator() const
{
    return new Diner_menu_iterator(items_);
}

Cafe_menu::Cafe_menu(const std::string& name) :
    Menu(name)
{
    items_ = new std::map<std::string, Menu_item*>();

    add_item("Cafe Latte", "Coffee, milk", true, 2.98);
    add_item("Iced Cap", "Water, coffee, ice", true, 3.99);
}

Cafe_menu::~Cafe_menu()
{
    delete_menu_items(create_iterator());
    
    delete items_;
}

void Cafe_menu::add_item(const std::string& name, const std::string& desc, bool vegan, double price)
{
    items_->insert(Item_pair(name, new Menu_item(name, desc, vegan, price)));
}

void Cafe_menu::print() const 
{
    cout << name_ << " (Cafe)" << endl;

    for (const auto& [name, item] : *items_)
    {
        item->print();
    }
}

Iterator<Menu_item*>* Cafe_menu::create_iterator() const
{
    return new Cafe_menu_iterator(items_);
}

Dessert_menu::Dessert_menu(const std::string& name) : 
   Menu(name)
{
    items_ = new List<Menu_item*>();

    add_item("Coward Cake", "piss, sugar, flour", true, 2.99);
    //add_item("Continental", "Oatmeal, fruit cup, muffin", true, 3.99);
}

Dessert_menu::~Dessert_menu()
{
    delete_menu_items(create_iterator());
    
    delete items_;
}

void Dessert_menu::add_item(const std::string& name, const std::string& desc, bool vegan, double price)
{
    items_->push(new Menu_item(name, desc, vegan, price));
}

void Dessert_menu::print() const 
{
    cout << name_ << " (Dessert)" << endl;

    for (unsigned i = 0; i < items_->count(); ++i)
    {
        auto item = items_->get(i);
        item->print();
    }
}

Iterator<Menu_item*>* Dessert_menu::create_iterator() const
{
    return new List_iterator(items_);
}