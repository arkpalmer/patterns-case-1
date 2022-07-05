#include "Menu.h"
#include "List.h"

class Waitress
{
public:
    Waitress();

    void print_menus() const;

private:
    void print_menu(const Menu* menu) const;

    List<Menu*> menus_;
};