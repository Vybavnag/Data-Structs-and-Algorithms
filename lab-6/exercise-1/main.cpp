#include <iostream>
#include "GoodList.h"
#include "TimeSupport.h"
#include "ArrayList.h"

using namespace std;



int main(){

    const int N = 5000000;

    GoodList goodList;
    ArrayList<int> arrayList;


    timestamp start = current_time();

    for (int i = 0; i < N; i++){
        goodList.append(i);
    }

    timestamp end = current_time();

    int alDuration = time_diff(start, end);

    cout << "Good List: " << alDuration << " ms." << endl;
    timestamp star1t=current_time();
    for (int i = 0; i < N; i++){
        arrayList.append(i);
    }

    timestamp end1 = current_time();

    int alDuration1 = time_diff(star1t, end1);
    cout << "Array List: " << alDuration1 << " ms." << endl;

    cout<<goodList[0]<<endl;
    return 0;
}