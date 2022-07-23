#pragma once

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <memory>

#include "List.h"
#include "Traverser.h"

//using std::cout;  omg, what's wrong with this?
//using std::endl;

class Menu_component // Component of Composite patterns
{
public:
    virtual void add(Menu_component*);
    virtual void remove(Menu_component*);

    virtual void print() const;

protected:
    Menu_component(); //const char*);

private:
    const char* name_; // GoF has name, HF doesn't (in HF, Menu_component is abstract class)
};

class Menu_item : public Menu_component
{
public:
    Menu_item(const std::string& name, const std::string& desc, bool vegan, double price) :
        name_(name), description_(desc), vegan_(vegan), price_(price) {}

    ~Menu_item() { std::cout << "~Menu_item:" << name_ << std::endl; }

    std::string name() const { return name_; }
    double price() const     { return price_; }
    std::string description() const { return description_; }
    bool is_vegan() const    { return vegan_; }

    // todo operator<<
    void print() const override;

    //// wait, why would this override??
    //void add(Menu_component*) override;

private:
    std::string name_;
    std::string description_;
    bool        vegan_;
    double      price_;
};

class Menu : Menu_component
{
public:
    //Menu() { } 
    Menu(const std::string& name);// : name_(name) { }

    // shouldn't Menu be abstract?

    //void print(const std::string& extra = "") const; 
    virtual Iterator<Menu_item*>* create_iterator() const = 0;

    Iterator<Menu_component*>* create_iterator2() const; 
    std::unique_ptr<Iterator<Menu_component*>> create_iterator3() const; 

    virtual void print() const; 

    virtual ~Menu();

    std::string name() const { return name_; }

    virtual void add(Menu_component*);

protected:
    std::string name_;
    
    List<Menu_component*>* menu_items_; // what do submenus look like now? they all have containers
};

class Diner_menu : public Menu
{
public:
    Diner_menu();

    Diner_menu(const std::string& name);

    // don't think needed any longer
    //void add_item(const std::string& name, const std::string& desc, bool vegan, double price);

    // don't think needed any longer
    //void print() const override;

    Iterator<Menu_item*>* create_iterator() const override;

    virtual ~Diner_menu();

private:
    std::list<Menu_item*>* items_;
};

//
// Cafe_menu uses a different storage method - for demonstrating the iterator
//
class Cafe_menu : public Menu
{
public:
    Cafe_menu(const std::string& name);

    void add_item(const std::string& name, const std::string& desc, bool vegan, double price);

    virtual ~Cafe_menu();

    void print() const override;

    Iterator<Menu_item*>* create_iterator() const override;

private:
    using Item_pair = std::pair<std::string, Menu_item*>;
    //std::map<Item_pair> items_;
    std::map<std::string, Menu_item*>* items_;
    //std::list<std::string, Menu_item*> items_;
};

class Dessert_menu : public Menu
{
public:
    Dessert_menu(const std::string& name);

    void add_item(const std::string& name, const std::string& desc, bool vegan, double price);

    virtual ~Dessert_menu();

    void print() const override;

    Iterator<Menu_item*>* create_iterator() const override;

private:
    List<Menu_item*>* items_;
};

template <typename T>
class Print_menus : public List_traverser<Menu*> 
{
public:
    Print_menus(List<T>* list) :
        List_traverser(list) { }

    bool process_item(const T& item)
    {
        FL
        item->print();
        return true;
    }
};

