#include <iostream>
#include "RoomSystem.h"
#include "Inventory.h"
#include "GameEvents.h"
using namespace std;

int main() {
    Room room;

    Inventory playerInventory;
    GameEvents events;
    string userCommand;
    while(!room.getGameCompleted()){
        cout << "What would you like to do? (inspect, move, and menu)" << endl;
        cin >> userCommand;
        if(userCommand == "move"){
            room.displayAdjecentRooms();
            cout << "Where would you like to move to?" << endl;
            cin >> userCommand;
            room.setRoom(userCommand);
        }
        if(userCommand == "inspect"){
            room.displayInspectableItems();
            cout << "What would you like to inspect?" << endl;
            cin >> userCommand;
            room.inspect(userCommand, playerInventory, events);
        }
        if(userCommand == "x"){
            cout << playerInventory.playerHas("knife");
        }

    }
    return 0;
}
