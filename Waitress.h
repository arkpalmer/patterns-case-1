#include "Menu.h"
#include "List.h"

class Waitress
{
public:
    Waitress();
    ~Waitress();

    void print_menus() const;

private:

    List<Menu*> menus_;
};