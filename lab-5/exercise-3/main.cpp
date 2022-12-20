#include <iostream>
#include <stdexcept>
#include <string>
#include "Queue.h"
#include "Stack.h"

using namespace std;

Queue<int> s;
Queue<string> r;
Queue<string>u;
Queue<string>f;

int main(){

    int count=0;
    int jobCount;
    cin >> jobCount;

    for (int i = 0; i < jobCount; i++){
        string name;
        int time;
        cin >> name;
        cin >> time;
        cout << name << " : " << time << endl;
        s.enqueue(time);
        r.enqueue(name);
    }


    int period;
    cin >> period;

    u.enqueue(r.peek());
    cout << r.peek() << " : " << 25 << endl;
    r.dequeue();
    f.enqueue(r.peek());
    cout << r.peek() << " : " << 25 << endl;
    r.dequeue();
    r.enqueue(u.peek());
    r.enqueue(f.peek());
    
    int r1=s.peek();
    s.dequeue();
    int r2=s.peek();
    string std1=r.peek();
    r.dequeue();
    string std2 =r.peek();
    for(int k=0; k<10;k++){
        if(period<r1){
            cout << std1 << " : " << period << endl;
            r1=r1-25;
        }
        if(period<r2){
            cout << std2 << " : " << period << endl;
            r2=r2-25;
        }
    }

    

    // Output round robin schedule, where person can use machine for no longer than the set period

    cout << "Done..." << endl;

    return 0;
}