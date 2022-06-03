#include <iostream>

#include "List.h"
#include "Menu.h"

using namespace std;

int main()
{
    FL

    //
    // don't commit to a specific List implementation
    //
    Abstract_list<Menu*>* menu_list;
    menu_list = new List<Menu*>();
    menu_list->push(new Menu("Scotty's Diner"));

    auto it = menu_list->create_iterator();

    while (!it->is_done())
    {
        it->current_item()->print();
        it->next();
    }

    return 0;

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

    return 0;
}
