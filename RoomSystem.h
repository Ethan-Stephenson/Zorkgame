#ifndef ROOMSYSTEM_H
#define ROOMSYSTEM_H

#include "Constants.h"
#include <iostream>
#include <string>
using std::string;
class Room{
public:
    void setRoom(int);
    int getRoom() const;
    string displayAdjecentRooms();
    string getDescription();
private:
    void setAdjecent(const int[5]);
    void setDescription(string);
    void updateRoom();
    string description;
    int roomNumber{1};
    int adjecentRooms[5]{0,0,0,0,0};
};
//Get
int Room::getRoom() const{
    return roomNumber;
}

string Room::getDescription() {
    return description;
}

//Set
void Room::setRoom(int setRoom) {
    roomNumber = setRoom;
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
        setDescription(constants::medevialDesc);
        setAdjecent(constants::medevialAdjecent);
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
string Room::displayAdjecentRooms() {
    string text = "The rooms adjacent to you are: ";
    for(size_t i = 0; i < 5; i++){
        if(adjecentRooms[i] == 1){
            if(i == constants::kitchenId-1){
                text.append("Kitchen ");
            }
            else if(i == constants::medevialId-1){
                text.append("Medieval ");
            }
            else if(i == constants::computerID-1){
                text.append("Computer-Room ");
            }
            else if(i == constants::greenhouseID-1){
                text.append("Greenhouse ");
            }
            else if(i == constants::workshopID-1){
                text.append("Workshop");
            }
        }
    }
    text.append("\n");
    return text;
}

#endif