#ifndef ZORKGAME_GAMEEVENTS_H
#define ZORKGAME_GAMEEVENTS_H
#include <iostream>
using namespace std;
class GameEvents{
public:
    void computerGame();
    void workshopGame();
    void paintingArrange();
    int* getEventCompletion();
    int getEvent(int);
private:
    //0 = Safe Open
    //1 = Castle Cabinet
    //2 = Areguala Defeated
    //3 = Workshop Game Completed
    //4 = Water Turned On
    //5 =
    int eventCompletion[10]{0,0,0,0,0,0,0,0,0,0};
};

int* GameEvents::getEventCompletion() {
    return eventCompletion;
}

int GameEvents::getEvent(int i){
    return eventCompletion[i];
}

void GameEvents::paintingArrange() {
    int order[5];
    char userInput;
    bool playAgain = true;
    while(playAgain){
        cout << "What order would you like to put the paintings in(use numbers assigned to paintings)\n";
        cout << "First Painting Space:\n";
        cin >> order[0];
        cout << "Second Painting Space:\n";
        cin >> order[1];
        cout << "Third Painting Space:\n";
        cin >> order[2];
        cout << "Fourth Painting Space:\n";
        cin >> order[3];
        cout << "Fifth Painting Space:\n";
        cin >> order[4];
        if(order[0] == 4 && order[1] == 1 && order[2] == 3 && order[3] == 5 && order[4] == 2){
            cout << "The door to the cabinet beside the paintings creaks open\n";
            eventCompletion[1] = 1;
            return;
        }
        else{
            cout << "Incorrect Order\n";
        }
        cout << "Would you like to try again?(y/n)\n";
        cin >> userInput;
        if(userInput != 'y'){
            playAgain = false;
        }
        else{
            cout << constants::paintings;
        }
    }
}

#endif //ZORKGAME_GAMEEVENTS_H
