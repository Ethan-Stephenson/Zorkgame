#ifndef ZORKGAME_GAMEEVENTS_H
#define ZORKGAME_GAMEEVENTS_H

class GameEvents{
public:
    void computerGame();
    void workshopGame();
    void medevialGame();
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

#endif //ZORKGAME_GAMEEVENTS_H
