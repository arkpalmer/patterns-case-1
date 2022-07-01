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
        list_iter_ = menu_list->begin();
    }

    void first() override 
    {
        list_iter_ = diner_menu_->begin();
    } 

    void next() override 
    {
        list_iter_++;
    } 

    bool is_done() const override 
    { 
        //return (diner_menu_->empty() || list_iter_ == std::prev(diner_menu_->end()));
        //return true; 
        if (diner_menu_ == nullptr)
        {
            std::cout << "nullptr" << std::endl;
            return true;
        }

        return (diner_menu_->empty());
    } //TODO

    Menu_item* current_item() const override  
    { 
        // TODO throw if invalid? 0 entries or iter off the end? prevent off the end and only check for 0?
        // testreturn new Menu_item("test menu item", "test", true, 0.99);
        //T temp; return temp; 
        return *list_iter_;
    }//TODO

private:
    //
    std::list<Menu_item*>::const_iterator list_iter_;
    const std::list<Menu_item*>* diner_menu_;

    long           current_;
};