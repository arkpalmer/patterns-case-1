#include <iostream>

#include "Waitress.h"

using namespace std;

Waitress::Waitress()
{
    diner_menu_ = new Diner_menu("Mo's Diner");
}

void Waitress::print_menus() const
{
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
        diner_iter->current_item();
        diner_iter->next();
    }
}
