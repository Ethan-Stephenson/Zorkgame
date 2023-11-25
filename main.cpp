#include <iostream>
#include "RoomSystem.h"
#include "Inventory.h"
using namespace std;
int main() {
    Room room;
    Inventory playerInventory;
    room.setRoom(2);
    string y;
    while(true)
    {
        cin >> y;
        playerInventory.grab(y, room.getRoom());
        cout << playerInventory.playerHas("bucket");

    }
    return 0;
}
