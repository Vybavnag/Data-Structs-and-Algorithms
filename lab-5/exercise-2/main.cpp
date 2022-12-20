#include <iostream>
#include "Queue.h"
#include "Stack.h"

using namespace std;

int main(){

    int op;
    int total = 0;

    Stack<int> s;

    do{
        cout << "1. Add" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Multiply" << endl;
        cout << "4. Divide" << endl;
        cout << "5. Undo" << endl;
        cout << "6. Stop" << endl;
        cout << endl;
        cout << "Select option: ";
        cin >> op;
        int amount;

        if (op == 1){
            cout << "Enter amount: ";
            cin >> amount;
            total += amount;
            s.push(total);
        }
        else if (op == 2){
            cout << "Enter amount: ";
            cin >> amount;
            total -= amount;
            s.push(total);
        }
        else if (op == 3){
            cout << "Enter amount: ";
            cin >> amount;
            total *= amount;
            s.push(total);
        }
        else if (op == 4){
            cout << "Enter amount: ";
            cin >> amount;
            total /= amount;
            s.push(total);
        }
        else if (op == 5){
            // Your code here
            cout << "Will undo last operation" << endl;
            s.pop();
        }
        
        cout << endl << "Total: " << s.peek() << endl << endl;
    }while( op != 6);

    cout << "Done..." << endl;

    return 0;
}