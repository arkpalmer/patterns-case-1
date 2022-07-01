#include <iostream>

#include "List.h"
#include "Menu.h"
#include "Iterator.h"
#include "Traverser.h"
#include "Waitress.h"

using namespace std;

void print_menus(Iterator<Menu*>& it)
{
    FL

    while (!it.is_done())
    {
        cout << "menu:" << endl;
        it.current_item()->print();
        it.next();
    }
}

void foo(List<Menu*>* ml)
{

}

int main()
{
    FL

    Waitress waitress;

    waitress.print_menus();

    //
    // don't commit to a specific List implementation
    //
    Abstract_list<Menu*>* menu_list;
    menu_list = new List<Menu*>();
    menu_list->push(new Diner_menu("Scotty's Diner"));
    menu_list->push(new Cafe_menu("Zolas Cafe"));

    auto dl = dynamic_cast<List<Menu*>*>(menu_list);

    if (dl)
    {
        Print_menus<Menu*> pm(dl);
        pm.traverse();

        //foo(dl);
        //auto menu_traverser = new Print_menus<Menu*>(dl);

        //
        // internal iterator (p268)
        //
        //menu_traverser->traverse();
    }

    return 0;

    //auto ml = dynamic_cast<Menu*>...
    Print_menus<Menu*> menu_printer(static_cast<List<Menu*>*>(menu_list));
    //uto menu_traverser = new List_traverser<Menu*>(menu_list);

    auto it = menu_list->create_iterator();

    print_menus(*it);
    it->first(); // check setting back to first works by printing again
    print_menus(*it);

    // NEXT p266 print_employees

    while (!it->is_done())
    {
        it->current_item()->print();
        it->next();
    }

    return 0;

#if 0
    //Menu* m = new Menu("Scotty's Diner");
    List<Menu*> menus;
    Menu m("Diner");
    menus.push(new Menu("Scotty's Diner"));
    menus.push(new Menu("Mort's"));

    auto menus_it = List_iterator<Menu*>(&menus);

    while (!menus_it.is_done())
    {
        menus_it.current_item()->print();
        menus_it.next();
    }
    
    return 0;
    //menus.push(m);

    List<int> li;
    cout << "li count:" << li.count() << endl;

    cout << "a val:" << li.get(5) << endl;
    cout << li.first() << endl;

    li.push(82);
    cout << "after push 82: li count:" << li.count() << endl;
    cout << li.last() << endl;

    List_iterator<int> lit(&li);

    // test of except
    List<int> li2(0);
    try
    {
     cout << li2.first() << endl;   
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
#endif

    return 0;
}
