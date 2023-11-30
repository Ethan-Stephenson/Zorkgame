#ifndef ROOMSYSTEM_H
#define ROOMSYSTEM_H

#include "Constants.h"
#include "Inventory.h"
#include "GameEvents.h"
#include <iostream>
#include <string>
using namespace std;
class Room{
public:
    void setRoom(string);
    void inspect(string, Inventory&, GameEvents&);
    int getRoom() const;
    bool getGameCompleted();
    void displayAdjecentRooms();
    string getDescription();
    void displayInspectableItems();
private:
    void setAdjecent(const int[5]);
    void setDescription(string);
    void updateRoom();
    string description;
    int roomNumber{1};
    int adjecentRooms[5]{0,1,0,0,0};
    bool gameCompleted = false;
};
//Get
int Room::getRoom() const{
    return roomNumber;
}

string Room::getDescription() {
    return description;
}

bool Room::getGameCompleted(){
    return gameCompleted;
}

//Set
void Room::setRoom(string userInput) {
    if(roomNumber == 1 && userInput == "castle") {
        roomNumber = 2;
        cout << "You moved to the castle\n";
    }
    else if(roomNumber == 2 && userInput == "kitchen") {
        roomNumber = 1;
        cout << "You moved to the kitchen\n";
    }
    else if(roomNumber == 2 && userInput == "computer") {
        roomNumber = 3;
        cout << "You moved to the computer room\n";
    }
    else if(roomNumber == 3 && userInput == "castle") {
        roomNumber = 2;
        cout << "You moved to the castle\n";
    }
    else if(roomNumber == 3 && userInput == "greenhouse") {
        roomNumber = 4;
        cout << "You moved to the greenhouse\n";
    }
    else if(roomNumber == 4 && userInput == "computer") {
        roomNumber = 3;
        cout << "You moved to the computer\n";
    }
    else if(roomNumber == 4 && userInput == "workshop") {
        roomNumber = 5;
        cout << "You moved to the workshop\n";
    }
    else if(roomNumber == 5 && userInput == "greenhouse") {
        roomNumber = 4;
        cout << "You moved to the greenhouse\n";
    }
    else{
        cout << "Invalid room\n";
    }


    updateRoom();
}
void Room::setDescription(string newDescription){
    description = newDescription;
}

void Room::setAdjecent(const int* newAdjecent) {
    for(size_t i = 0; i < 5; i++){
        adjecentRooms[i] = newAdjecent[i];
    }
}

//Member Functions
void Room::updateRoom(){
    if(roomNumber == 1){
        setDescription(constants::kitchenDesc);
        setAdjecent(constants::kitchenAdjecent);
    }
    else if(roomNumber == 2) {
        setDescription(constants::castleDesc);
        setAdjecent(constants::castleAdjecent);
    }
    else if(roomNumber == 3){
        setDescription(constants::computerDesc);
        setAdjecent(constants::computerAdjecent);
    }
    else if(roomNumber == 4) {
        setDescription(constants::greenhouseDesc);
        setAdjecent(constants::greenhouseAdjecent);
    }
    else if(roomNumber == 5) {
        setDescription(constants::workshopDesc);
        setAdjecent(constants::workshopAdjecent);
    }
}

void Room::displayAdjecentRooms() {
    string text = "The rooms adjacent to you are: ";
    for(size_t i = 0; i < 5; i++){
        if(adjecentRooms[i] == 1){
            if(i == constants::kitchenId-1){
                text.append("kitchen ");
            }
            else if(i == constants::castleId-1){
                text.append("castle ");
            }
            else if(i == constants::computerID-1){
                text.append("computer ");
            }
            else if(i == constants::greenhouseID-1){
                text.append("greenhouse ");
            }
            else if(i == constants::workshopID-1){
                text.append("workshop");
            }
        }
    }
    text.append("\n");
    cout << text;
}

void Room::displayInspectableItems(){
    if(roomNumber == 1){
        cout << "Inspectable objects are: cookbook, sink, kniferack, cookiedoor, and oven" << endl;
    }
    else if(roomNumber == 2){
        cout << "Inspectable objects are: torch, spicecabinet, and paintings" << endl;
    }
    else if(roomNumber == 3){
        cout << "Inspectable objects are: safe and computer" << endl;
    }
    else if(roomNumber == 4){
        cout << "Inspectable objects are: arugula, pipe, wheat, and machine" << endl;
    }
    else if(roomNumber == 5){
        cout << "Inspectable objects are: pedestal" << endl;
    }
};

void Room::inspect(string userInput, Inventory &playerInventory, GameEvents &events){
    if(roomNumber == 1) {
        if (userInput == "cookbook") {
            cout << constants::cookBook;
        }
            //Sink
        else if (userInput == "sink" && events.getEvent(4) == 0) {
            cout << constants::sinkNoWater;
        } else if (userInput == "sink" && events.getEvent(4) == 1 && playerInventory.playerHas("bucket") == false) {
            cout << constants::sinkWaterNobucket;
        } else if (userInput == "sink" && events.getEvent(4) == 1 && playerInventory.playerHas("bucket") == true) {
            cout << constants::sinkWaterBucket;
        } else if (userInput == "kniferack" && playerInventory.playerHas("knife") == false) {
            cout << constants::knifeRack;
            cout << "Would you like to grab the knife?(y/n)\n";
            cin >> userInput;
            if (userInput == "y") {
                playerInventory.grab("knife");
            }
        } else if (userInput == "cookiedoor" && playerInventory.playerHas("cookiekey") == false) {
            cout << constants::cookieDoor;
        } else if (userInput == "cookiedoor" && playerInventory.playerHas("cookiekey") == true) {
            cout << constants::cookieDoorWithKey;
            gameCompleted = true;
        } else if (userInput == "oven" && playerInventory.playerHas("flour") == false &&
                   playerInventory.playerHas("sugar") == false &&
                   playerInventory.playerHas("note") == false && playerInventory.playerHas("butter") == false) {
            cout << constants::oven;
        } else if (userInput == "oven") {
            cout << constants::ovenCompleted;
            playerInventory.grab("cookiekey");
        }
        else{
            cout << "Invalid Inspect\n";
        }
    }
    else if(roomNumber == 2){
        if(userInput == "torch" && playerInventory.playerHas("torch") == false){
            cout << constants::torchGrab;
            cin >> userInput;
            if(userInput == "y"){
                playerInventory.grab("torch");
            }
        }
        else if(userInput == "spicecabinet" && events.getEvent(1) == 0){
            cout << constants::spiceCabinet;
        }
        else if(userInput == "spicecabinet" && events.getEvent(1) == 1){
            cout << constants::spiceCabinetOpen;
            cin >> userInput;
            if(userInput == "y"){
                playerInventory.grab("sugar");
            }
        }
        else if(userInput == "paintings" && events.getEvent(1) == 0){
            cout << constants::paintings;
            cout << constants::paintingsQuestion;
            cin >> userInput;
            if(userInput == "y"){
                events.paintingArrange();
            }
        }
        else if(userInput == "paintings" && events.getEvent(1) == 0){
            cout << constants::paintingsDone;
        }
    }
}

#endif