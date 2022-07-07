#include <iostream>

#include "Waitress.h"

using namespace std;

Waitress::Waitress()
{
    menus_.push(new Diner_menu("Mo's Diner"));
    menus_.push(new Cafe_menu("Loser Cafe"));
    menus_.push(new Dessert_menu("Wimps Desserts"));
}

Waitress::~Waitress()
{
    for (int i = 0; i < menus_.count(); ++i)
    {
        auto menu = menus_.get(i);
        delete menu;
    }
}

void Waitress::print_menus() const
{
    for (int i = 0; i < menus_.count(); ++i)
    {
        auto menu = menus_.get(i);
        cout << endl;
        menu->print(); // menu prints itself - earlier version had Waitress printing the details
    }

    cout << endl;
}