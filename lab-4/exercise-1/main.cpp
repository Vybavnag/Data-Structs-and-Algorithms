#include <iostream>
#include "ArrayList.h"

using namespace std;

int main(){


    ArrayList collection;

    collection.append(99);
    collection.append(27);
    collection.append(14);
    // collection.append(42);
    // collection.append(72);

    // cout << collection << endl;

    // collection.insert(101,2);

    cout << collection << endl;

    cout << collection.get(3) << endl;

    return 0;
}