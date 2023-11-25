#ifndef INVENTORY_H
#define INVENTORY_H
#include "global.h"
#include <string>
#include <iostream>
#include <utility>
#include "RoomSystem.h"
using std::string;
class Inventory{
public:
    void grab(string, int);
    bool playerHas(string);

private:

    bool bucket = false,temperatureNote = false, flour = false, sugar = false, butter = false, cookieKey = false, knife = false, torch = false, herbicide = false, waterBucket = false;
    int itemsGrabbed[10]{0,0,0,0,0,0,0,0,0,0};
};



void Inventory::grab(string item, int roomNumber) {
    if(item == constants::bucket && itemsGrabbed[0] == 0 && roomNumber == 1){
        bucket = true;
        itemsGrabbed[0] = 1;
    }
    else if(item == constants::temperatureNote && itemsGrabbed[1] == 0){
        temperatureNote = true;
        itemsGrabbed[1] = 1;
    }
    else if(item == constants::flour && itemsGrabbed[2] == 0){
        flour = true;
        itemsGrabbed[2] = 1;
    }
    else if(item == constants::sugar && itemsGrabbed[3] == 0){
        sugar = true;
        itemsGrabbed[3] = 1;
    }
    else if(item == constants::butter && itemsGrabbed[4] == 0){
        butter = true;
        itemsGrabbed[4] = 1;
    }
    else if(item == constants::cookieKey && itemsGrabbed[5] == 0){
        cookieKey = true;
        itemsGrabbed[5] = 1;
    }
    else if(item == constants::knife && itemsGrabbed[6] == 0){
        knife = true;
        itemsGrabbed[6] = 1;
    }
    else if(item == constants::torch && itemsGrabbed[7] == 0){
        torch = true;
        itemsGrabbed[7] = 1;
    }
    else if(item == constants::herbicide && itemsGrabbed[8] == 0){
        herbicide = true;
        itemsGrabbed[8] = 1;
    }
    else if(item == constants::waterBucket && itemsGrabbed[9] == 0){
        waterBucket = true;
        itemsGrabbed[9] = 1;
    }
    else{
        std::cout << "No item by that name, or item is not accessible" << std::endl;
        return;
    }
    std::cout << "You grabbed " << item << std::endl;
}

bool Inventory::playerHas(string item) {
    if(item == constants::bucket){
        return bucket;
    }
    if(item == constants::temperatureNote){
        return temperatureNote;
    }
    if(item == constants::flour){
        return flour;
    }
    if(item == constants::sugar){
        return sugar;
    }
    if(item == constants::butter){
        return butter;
    }if(item == constants::cookieKey){
        return cookieKey;
    }if(item == constants::knife){
        return knife;
    }
    if(item == constants::torch){
        return torch;
    }
    if(item == constants::herbicide){
        return herbicide;
    }
    if(item == constants::waterBucket){
        return waterBucket;
    }
    else{
        return false;
    }
}
#endif