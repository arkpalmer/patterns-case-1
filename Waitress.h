#include "Menu.h"

class Waitress
{
public:
    Waitress();

    void print_menus() const;
private:
    Diner_menu* diner_menu_;
};