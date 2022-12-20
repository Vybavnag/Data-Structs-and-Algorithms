#include <iostream>
#include <string>
#include "WordleHelper.h"

using namespace std;

int main(){

    WordleHelper wh;


    wh.addGreen("_o__y");
    wh.addYellow("__tlo");
    wh.addGray("audih");

    vector <string> sol = wh.possibleSolutions();

    for(int i=0; i<sol.size(); i++){
        cout<<sol[i]<<endl;
    }
    return 0;

}