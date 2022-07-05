#include <iostream>

#include "Waitress.h"

using namespace std;

Waitress::Waitress()
{
    menus_.push(new Diner_menu("Mo's Diner"));
    menus_.push(new Cafe_menu("Loser Cafe"));
    menus_.push(new Dessert_menu("Wimps Desserts"));
}

//TODO dtor

void Waitress::print_menu(const Menu* menu) const
{
    cout << endl << "print_menu .... "  << menu->name() << endl;

    auto menu_iter = menu->create_iterator();

    if (menu_iter == nullptr)
    {
        cout << "iter is nullptr" << endl;
        return;
    }

    while (!menu_iter->is_done())
    {
        auto item = menu_iter->current_item();
        cout << item->description() << endl;
        menu_iter->next();
    }
}

void Waitress::print_menus() const
{
    for (int i = 0; i < menus_.count(); ++i)
    {
        auto menu = menus_.get(i);
        cout << endl;
        menu->print();
        //print_menu(menu);
    }

#if 0
    // HERE - TODO general solution
    if (diner_menu_ == nullptr)
    {
        cout << "diner_menu_ is nullptr" << endl;
        return;
    }
    auto diner_iter = diner_menu_->create_iterator();

    if (diner_iter == nullptr)
    {
        cout << "iter is nullptr" << endl;
        return;
    }

    while (!diner_iter->is_done())
    {
        auto item = diner_iter->current_item();
        cout << item->description() << endl;
        diner_iter->next();
    }

    auto cafe_iter = cafe_menu_->create_iterator();

    if (cafe_iter == nullptr)
    {
        cout << "iter is nullptr" << endl;
        return;
    }

    while (!cafe_iter->is_done())
    {
        auto item = cafe_iter->current_item();
        cout << item->description() << endl;
        cafe_iter->next();
    }
#endif
}