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
        first();
        //list_iter_ = diner_menu_->begin();
    }

    void first() 
    {
        list_iter_ = diner_menu_->begin();
    }

    // advance the iterator
    void next() 
    {
        if (!is_done())
        {
            list_iter_++;
        }
    }

    // true if iterator does not refer to an element
    bool is_done() const 
    { 
        return (list_iter_ == diner_menu_->end()); 
    }

    Menu_item* current_item() const 
    { 
        if (is_done())
        {
            return nullptr; // throw?
        }

        return *list_iter_; 
    }

private:
    //
    std::list<Menu_item*>::const_iterator list_iter_;
    //std::list<Menu_item*>::iterator list_iter_;
    const std::list<Menu_item*>* diner_menu_;
};