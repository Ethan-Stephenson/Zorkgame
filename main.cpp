#include <iostream>
#include "RoomSystem.h"
#include "Inventory.h"
#include "GameEvents.h"
using namespace std;
void Menu(Room, Inventory);

void kitchenDiagram();

void castleDiagram();

void computerDiagram();

void greenHouseDiagram();

void workshopDiagram();
const char space = ' ';

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
        else if(userCommand == "inspect"){
            room.displayInspectableItems();
            cout << "What would you like to inspect?" << endl;
            cin >> userCommand;
            room.inspect(userCommand, playerInventory, events);
        }
        else if(userCommand == "menu"){
            Menu(room, playerInventory);
        }

    }
    return 0;
}

void Menu(Room room, Inventory playerInventory){
    string gameInstructions = "Your objective is to find all ingredients and items, go explore each room solve its puzzles and get the key.";
    string inventory = "The required items that the player has is: ";
//Delcares choice
    int choice;
//Outputs the various choices to the user
cout << "Room Menu:\n\n";
cout << "1: Room Diagram with description\n";
cout << "2: Display current required items\n";
cout << "3: Instructions for Game\n";
cout << "4: Resume playing Game\n";
cout << "5: Exit Game\n";
cin >> choice;
switch(choice){
    case 1:
        switch(room.getRoom()) {
            case 1:
                kitchenDiagram();
                break;
            case 2:
                castleDiagram();
                break;
            case 3:
                computerDiagram();
                break;
            case 4:
                greenHouseDiagram();
                break;
            case 5:
                workshopDiagram();
                break;
        }
        cout << room.getDescription();
        break;
    case 2:

        if(playerInventory.playerHas("sugar")){
            inventory.append("sugar ");
        }
        if(playerInventory.playerHas("butter")){
            inventory.append("butter ");
        }
        if(playerInventory.playerHas("note")){
            inventory.append("note ");
        }
        if(playerInventory.playerHas("flour")){
            inventory.append("flour ");
        }
        cout << inventory << endl;
        break;
    case 3:
        cout << gameInstructions;
        break;
    case 4:
        return;
    case 5:
        throw(0);
}
    }
void kitchenDiagram(){
    //Uses for loops to create the top line of *
    for (int w = 0; w < 10; w++) {
        cout << "* ";
    }
//Creates a * then does spaces until at other side of square then puts another *
    for (int h = 0; h < 6; h++) {
        cout << "\n*";
        for (int i = 0; i < 17; i++) {
            cout << " ";
        }
        cout << "*";
    }
//Creates the bottom line of *
    cout << endl;
    for (int b = 0; b < 10; b++) {
        cout << "* ";
    }
}
void castleDiagram(){
    //Uses for loops to create the top line of *
    for (int w = 0; w < 10; w++) {
        cout << "* ";
    }
//Creates a * then does spaces until at other side of square then puts another *
    for (int h = 0; h < 10; h++) {
        cout << "\n*";
        for (int i = 0; i < 17; i++) {
            cout << " ";
        }
        cout << "*";
    }
//Creates the bottom line of *
    cout << endl;
    for (int b = 0; b < 10; b++) {
        cout << "* ";
    }
    cout << endl;
    cout << endl;

}
void computerDiagram(){
    int x = 7;
    //Creates spaces to make the top of the shape in the middle
    for (int i = 0; i <= 3; i++) {
        cout << " ";
    }
//Creates the top line of octagon
    for (int i = 0; i <= 4; i++) {
        cout << "* ";
    }
    cout << endl;
//Creates two downward lines of *
    for (int i = 3; i > 0; i--) {
        x = x + 2;
        cout << string(i, space);
        cout << "*";
        cout << string(x, space);
        cout << "*\n";
    }
//Creates the middle sides of vertical *
    for (int i = 0; i < 4; i++) {
        cout << "*";
        for (int y = 0; y <= 14; y++) {
            cout << " ";
        }
        cout << "*\n";
    }
    x = 15;
//Creates the angled lines to the bottom side
    for (int i = 1; i < 4; i++) {
        x = x - 2;
        cout << string(i, space);
        cout << "*";
        cout << string(x, space);
        cout << "*\n";
    }
//Creates the spaces to make the bottom line in the center
    for (int i = 0; i <= 3; i++) {
        cout << " ";
    }
//Creates the bottom side
    for (int i = 0; i <= 4; i++) {
        cout << "* ";
    }
}
void greenHouseDiagram(){
    int y = -1;

    //Irregular Pentagon
//Creates the spaces before the point of the pentagon
    for (int i = 0; i <= 5; i++) {
        cout << " ";
    }
//Point of the pentagon
    cout << "*\n";
//Crates the downward angled lines
    for (int i = 5; i > 0; i--) {

        y = y + 2;
        cout << string(i, space);
        cout << "*";
        cout << string(y, space);
        cout << "*\n";
    }
//Creates the vertical sides of the pentagon
    for (int i = 0; i <= 3; i++) {
        cout << "*";
        for (int y = 0; y <= 10; y++) {
            cout << " ";
        }
        cout << "*\n";
    }
//creates the bottom of the pentagon
    for (int i = 0; i <= 6; i++) {
        cout << "* ";
    }
}
void workshopDiagram(){
    int w = 11;
    //Trapezoid
//Creates spaces to make the top of trapezoid in center
    for (int i = 0; i <= 7; i++) {
        cout << " ";
    }
//Creates top side
    for (int i = 0; i < 7; i++) {
        cout << "* ";
    }
    cout << endl;
//Creates the angled lines to the base of the trapezoid
    for (int i = 7; i > 0; i--) {
        w = w + 2;
        cout << string(i, space);
        cout << "*";
        cout << string(w, space);
        cout << "*\n";
    }
//Creates the base of the trapezoid
    for (int i = 0; i < 15; i++) {
        cout << "* ";
    }
}



