#include <iostream>
#include "RoomSystem.h"
using namespace std;
int main() {
    kitchen test2;
    computerRoom test3;
    int x;
    while(true)
    {
        cin >> x;
        if(x == 1){
            test2.kitchenUpdate();
            cout << test2.displayAdjecentRooms();

        }
        if(x == 3) {
            test3.computerUpdate();
            cout << test3.displayAdjecentRooms();
        }

    }
    return 0;
}
