#include <iostream>

#include "List.h"
#include "Menu.h"
#include "Iterator.h"
#include "Traverser.h"
#include "Waitress.h"

using namespace std;

int main()
{
    Waitress waitress;

    waitress.print_menus();

    return 0;
}
