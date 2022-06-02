#include <iostream>

#include "List.h"

using namespace std;

int main()
{
    FL

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
