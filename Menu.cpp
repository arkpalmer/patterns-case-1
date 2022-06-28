#include "Menu.h"
#include "Utils.h"

Menu::~Menu()
{
    // for (auto& item : items_)
    // {
    //     delete item;
    // }
}

void Menu::print() const
{
    std::cout << "Menu name: " << name_ << std::endl;

    std::cout << " items:" << std::endl;
    // for (const auto& item : items_)
    // {
    //     std::cout << "   " << item->name() << std::endl;
    // }
}

Diner_menu::Diner_menu(const std::string& name) :
    Menu(name)
{
//Menu_item(const std::string& name, const std::string& desc, bool vegan, double price) :
    add_item("Regular Pancake Breakfast", "Pancakes, 1 egg, 2 bacon", false, 2.99);
    add_item("Continental", "Oatmeal, fruit cup, muffin", true, 3.99);
}

Diner_menu::~Diner_menu()
{
    for (auto& item : items_)
    {
        delete item;
    }
}

void Diner_menu::add_item(const std::string& name, const std::string& desc, bool vegan, double price)
{
    items_.push_back(new Menu_item(name, desc, vegan, price));
}

Cafe_menu::Cafe_menu(const std::string& name) :
    Menu(name)
{
    add_item("Cafe Latte", "Coffee, milk", true, 2.98);
    add_item("Iced Cap", "Water, coffee, ice", true, 3.99);
}

Cafe_menu::~Cafe_menu()
{
    for (auto& [key, item] : items_)
    {
        delete item;
    }
}

void Cafe_menu::add_item(const std::string& name, const std::string& desc, bool vegan, double price)
{
    items_.insert(Item_pair(name, new Menu_item(name, desc, vegan, price)));
}