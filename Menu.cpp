#include <iostream>
#include <memory>

#include "Menu.h"
#include "Menu_iterators.h"
#include "Utils.h"

using namespace std;

#if 0
class Menu_component
{
public:
    virtual void add(Menu_component*);
    virtual void remove(Menu_component*);

protected:
    Menu_component(const char*);

private:
    const char* name_;
};
#endif

Menu_component::Menu_component() // const char* name) :
    //name_(name)
{
}

// TODO what does Gof do? HF is exception I think 
void Menu_component::add(Menu_component*) { cout << "add unimplemented" << endl; }
void Menu_component::remove(Menu_component*) { cout << "remove unimplemented" << endl; }
void Menu_component::print() const { cout << "print unimplemented" << endl; }

Menu::Menu(const std::string& name) : 
    name_(name) 
{ 
    menu_items_ = new List<Menu_component*>();
}

//    Iterator<Menu_component*> get_iterator() const;
// Iterator<T>* List<T>::create_iterator()
Iterator<Menu_component*>* Menu::create_iterator2() const
{
    return menu_items_->create_iterator();
}

std::unique_ptr<Iterator<Menu_component*>> Menu::create_iterator3() const
{
    //return nullptr;
    //return new List_iterator<T>(this);

    /// Dessert menu:
    //    Iterator<Menu_item*>* create_iterator() const override;
    //     return new List_iterator(items_);
    //    List<Menu_item*>* items_;

    return std::make_unique<List_iterator<Menu_component*>>(menu_items_);
    //auto up = std::make_unique<List_iterator<Menu_component*>>(menu_items_);

    //return up;
}
#if 0
Iterator<Menu_item*>* Diner_menu::create_iterator() const
{
    return new Diner_menu_iterator(items_);
}
#endif

void Menu::print() const
{
    PFL
    cout << "u22 name: " << name_ << endl;

    // TBD/TODO: or already have it created and 'get_iterator' 
    auto iter = create_iterator3();

    while (!iter->is_done())
    {
        auto item = iter->current_item();
        item->print();
        iter->next();
    }
    PFL
}

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

void Menu::add(Menu_component* menu_component)  
{ 
    PFL
    menu_items_->push(menu_component);
}

//
// TODO 
//
void Menu_item::print() const
{
    PFL
    cout << name_ << ": " << description_ << endl;
}

Menu::~Menu()
{
}

Diner_menu::Diner_menu(const std::string& name) :
    Menu(name)
{
    add(new Menu_item("Regular Pancake Breakfast", "Pancakes, 1 egg, 2 bacon", false, 2.99));
    add(new Menu_item("Continental", "Oatmeal, fruit cup, muffin", true, 3.99));
    //items_->push_back(new Menu_item(name, desc, vegan, price));
    //add(new Menu_item());

    items_ = new std::list<Menu_item*>();

    //add_item("Regular Pancake Breakfast", "Pancakes, 1 egg, 2 bacon", false, 2.99);
    //add_item("Continental", "Oatmeal, fruit cup, muffin", true, 3.99);
}

Diner_menu::~Diner_menu()
{
    delete_menu_items(create_iterator());

    delete items_;
}

#if 0
void Diner_menu::add_item(const std::string& name, const std::string& desc, bool vegan, double price)
{
    items_->push_back(new Menu_item(name, desc, vegan, price));
    //menu_items_->push(new Menu_item(name, desc, vegan, price));
}
#endif

#if 0
void Diner_menu::print() const 
{
    // TBD still needed? use only Menu and Menu_item print?
    PFL
    cout << name_ << " (Diner)" << endl;

    for (const auto& item : *items_)
    {
        item->print();
    }
}
#endif

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