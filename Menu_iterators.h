#pragma once


// not sure about this...

#include <list>

#include "Menu.h"
#include "Iterator.h"

// should really use a Std_list sort of base class...
//
// Diner_menu items are stored in a std::list
//
class Diner_menu_iterator : public Iterator<Menu_item*>
{
public:
    //Diner_menu_iterator() {} // explicit?
    Diner_menu_iterator(std::list<Menu_item*>* menu_list) :
       diner_menu_(menu_list)
    {

    }

    void first() {}

    // advance the iterator
    void next() {}

    // true if iterator does not refer to an element
    bool is_done() const { return true; }

    Menu_item* current_item() const { return nullptr; }

private:
    //
    //std::list<Menu_item*>::const_iterator list_iter_;
    const std::list<Menu_item*>* diner_menu_;
};