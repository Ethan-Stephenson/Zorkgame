#include "Constants.h"
#include <iostream>
#include <string>
using namespace std;
class room{
public:
    void setRoom(int);
    int getRoom();
    string displayAdjecentRooms();
    void setDescription(string);
    string getDescription();
    void setAdjecent(const int[5]);
    room() {

    }

private:
    void updateRoom();

    string description;
    int roomNumber{1};
    int adjecentRooms[5]{0,0,0,0,0};
};


void room::setRoom(int setRoom) {
    roomNumber = setRoom;
}

void room::setDescription(string newDescription){
    description = newDescription;
}

void room::setAdjecent(const int* newAdjecent) {
     memcpy(adjecentRooms, newAdjecent,sizeof(adjecentRooms));
}


int room::getRoom() {
    return roomNumber;
}

string room::getDescription() {
    return description;
}

string room::displayAdjecentRooms() {
    string text = "The rooms adjacent to you are: ";
    for(int i = 0; i < 5; i++){
        cout << adjecentRooms[i] << endl;
        if(adjecentRooms[i] == 1){
            if(i == constants::kitchenId-1){
                text.append("Kitchen ");
            }
            if(i == constants::medevialId-1){
                text.append("Medieval ");
            }
            if(i == constants::computerID-1){
                text.append("Computer-Room ");
            }
            if(i == constants::greenhouseID-1){
                text.append("Greenhouse ");
            }
            if(i == constants::workshopID-1){
                text.append("Workshop");
            }
        }
    }
    text.append("\n");
    return text;
}

class kitchen : public room{
public:
    void kitchenUpdate();
};

void kitchen::kitchenUpdate() {
    setRoom(constants::kitchenId);
    setDescription(constants::kitchenDesc);
    setAdjecent(constants::kitchenAdjecent);
}


class greenHouse{

};

class computerRoom : public room{
public:
    void computerUpdate();
    void movingPlayerGame();
};
void computerRoom::computerUpdate() {
    setRoom(constants::computerID);
    setDescription(constants::computerDesc);
    setAdjecent(constants::computerAdjecent);
}
class medevial{

};

class workShop{

};



