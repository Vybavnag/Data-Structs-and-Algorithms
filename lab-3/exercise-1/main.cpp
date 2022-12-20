#include <iostream>
#include "ArrayList.h"

using namespace std;

int main(){


    ArrayList collection;

    collection.append(1);
    collection.prepend(5);
    collection.append(3);
    collection.append(3);
    collection.append(3);

    cout << collection << endl;

    collection.removeFirst();

    cout << collection << endl;

    collection.removeFirst();

    cout << collection << endl;

    collection.removeLast();

    cout << collection << endl;

    return 0;
}