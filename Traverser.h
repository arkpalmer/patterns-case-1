#pragma once

#include "Iterator.h"
//#include "Menu.h"

template <typename T>
class List_traverser
{
public:
    List_traverser(List<T>* list);
    bool traverse();

protected:
    virtual bool process_item(const T& item) = 0;

private:
    List_iterator<T> iterator_;
};

template <typename T>
List_traverser<T>::List_traverser(List<T>* list) :
    iterator_(list)
{
}

template <typename T>
bool List_traverser<T>::traverse()
{
    bool result = false; // ? returns false if no items to process

    for (iterator_.first(); !iterator_.is_done(); iterator_.next())
    {        
        result = process_item(iterator_.current_item());
    }

    return result;
}

// class Print_menus : public List_traverser<Menu*> 
// {

// };
// next subclass Print_menus : public List_traverser<Menu*> {};