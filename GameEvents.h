#ifndef ZORKGAME_GAMEEVENTS_H
#define ZORKGAME_GAMEEVENTS_H
#include <iostream>
#include <thread>
#include <chrono>
#include <stdlib.h>
using namespace std;
void generateGrid();
void intialGridPrint();
void playerMovementInput();
void playBoardGame();
void newGridGenerationThread();

const int startY = 0, startX = 0, gridX = 10, gridY = 10, cordinateXMax = gridX - 1, cordinateYMax = gridY - 1;
int movementX = startX, movementY = startY;
string direction;
string userInput;
bool gameOver = false;
bool gameBeat = false;
bool exitGame = false;
string grid[gridX][gridY];

class GameEvents{
public:
    void computerGame();
    void workshopGame();
    void arugulaFight(Inventory);
    void paintingArrange();
    int getEvent(int);
    void setEvent(int, int);
private:
    //0 = Safe Open
    //1 = Castle Cabinet
    //2 = Areguala Defeated
    //3 = Workshop Game Completed
    //4 = Water Turned On
    //5 =
    int eventCompletion[10]{0,0,0,0,0,0,0,0,0,0};
};


int GameEvents::getEvent(int i){
    return eventCompletion[i];
}

void GameEvents::setEvent(int i, int value){
    eventCompletion[i] = value;
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

void GameEvents::arugulaFight(Inventory playerInventory){
    int arugulaHealth = 100;
    int burnAttack = 0;
    int attack = 0;
    srand(time(0));
    int temprand = rand();
    bool burning = false;
    int playerHealth = 100;
    string userCommand;
    bool defeated = false;
    string items = "What would you like to attack with: fist ";
    if(playerInventory.playerHas("knife")){
        items.append("knife ");
    }
    if(playerInventory.playerHas("torch")){
        items.append("torch");
    }
    items.append("\n");
    cout << "The arugula hasn't noticed you yet, so you get to attack first\n";
    while(!defeated){
        cout << items;
        cin >> userCommand;
        if(userCommand == "knife" && (playerInventory.playerHas("knife"))){
            attack = rand()%15;
            cout << "You attack for " << attack << "HP\n";
            if(burning){
                burnAttack = rand()%5;
                cout << "They burn for " << burnAttack << "HP" <<endl;
            }
            arugulaHealth = arugulaHealth - attack - burnAttack;
            cout << "Arugula is now at " << arugulaHealth<< "HP\n";
        }
        else if(userCommand == "fist"){
            attack = rand()%5;
            cout << "You attack for " << attack << "HP\n";
            if(burning){
                burnAttack = rand()%5;
                cout << "They burn for " << burnAttack << endl;
            }
            arugulaHealth = arugulaHealth - attack - burnAttack;
            cout << "Arugula is now at " << arugulaHealth<< endl;
        }
        else if(userCommand == "torch" && (playerInventory.playerHas("torch"))){
            attack = rand()%10;
            burning = true;
            cout << "They are hit for " << attack << "HP\n";
            burnAttack = rand()%5;
            cout << "They burn for " << burnAttack << endl;
            arugulaHealth = arugulaHealth - attack - burnAttack;
            cout << "Arugula is now at " << arugulaHealth << "HP" << endl;
        }

        else{
            cout << "Not an item you lose your turn\n";
        }
        if(arugulaHealth <= 0){
            cout << "You beat the arugula and it falls to the floor dead leaving the way to the pipe open\n";
            eventCompletion[2] = 1;
            return;
        }
        attack = rand()%12;
        cout << "The arugula attacks for " << attack << " HP\n";
        playerHealth = playerHealth-attack;
        cout << "You are now at " << playerHealth << "HP\n";

        if(playerHealth <= 0){
            cout << "You got knocked out by the arugula, try using a different combination of weapons or finding more\n";
            return;
        }

    };


}
void GameEvents::workshopGame() {
    int order[5];
    char userInput;
    bool playAgain = true;
    cout << "On the pedestal sits 5 shapes:\n1:Octagon\n2:Rectangle\n3:Pentagon\n4:Trapezoid\n5:Square\n";
    cout << "Scribed into the wood is 5 images in this order: keyboard, knife, carrot, stonebrick, and wooddust\n";
    while(playAgain){
        cout << "What order would you like to put the shapes(enter number associated with shape)\n";
        cout << "Keyboard Shape:\n";
        cin >> order[0];
        cout << "Knife Shape:\n";
        cin >> order[1];
        cout << "Carrot Shape:\n";
        cin >> order[2];
        cout << "Stonebrick Shape:\n";
        cin >> order[3];
        cout << "WoodDust Shape:\n";
        cin >> order[4];
        if(order[0] == 1 && order[1] == 5 && order[2] == 3 && order[3] == 2 && order[4] == 4){
            cout << "A door on the pedestal opens up, inspect again to grab\n";
            eventCompletion[3] = 1;
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
void GameEvents::computerGame() {
    double input1, input2, input3;
    char userInput;
    int currentGame = 1;
    bool gameComplete = false;
    while(!gameComplete){
        if(currentGame == 1){
            cout << "You will enter 3 inputs, and I will display 3 outputs each with different operations applied to them, cause the outputs to equal 1,4,6\n";
            cout << "Enter your first input:\n";
            cin >> input1;
            cout << "Enter your second input:\n";
            cin >> input2;
            cout << "Enter your third input:\n";
            cin >> input3;
            cout << (input1*3)-2 << "," << (input2/2)+1 << "," << (input3*input3)-3 << endl;
            if(input1 == 1 && input2 == 6 && input3 == 3){
                cout << "Good job on the first game\n Now onto the Second\n";
                currentGame = 2;
            }
            else{
                cout << "Incorrect Inputs, try again?(y/n)\n";
                cin >> userInput;
                if(userInput != 'y'){
                    gameComplete = true;
                }
            }
        }
        if(currentGame == 2){
            playBoardGame();
            if(gameBeat == true) {
                cout  << "You have beaten my games now you will receive your reward\nThe safe beside the computer swings open\n";
                eventCompletion[0] = 1;
                return;
            }
            else if(exitGame == true){
                gameComplete = true;
            }

        }

    }

}


void playBoardGame() {
    while (!exitGame) {
        gameOver = false;
        movementX = startX, movementY = startY;
        cout << "In this game you move around a \"P\" around a grid\n";
        cout << "You move using - W = Up, A = Left, D = Right, S = Down\n";
        cout << "When you see a \"0\" on the board that means that a attack is about to hit there, so move out the way\n";
        cout << "Are you ready to play?(y/n)\n";
        cin >> userInput;
        if (userInput != "y") {
            return;
        }
        generateGrid();
        intialGridPrint();
        thread GridGenerationThread(newGridGenerationThread);
        while (true) {
            playerMovementInput();
            if (gameOver == true) {
                break;
            }
            if(gameBeat == true){
                exitGame = true;
                break;
            }
            if (direction == "L" || direction == "l")
                break;
        }
        GridGenerationThread.join();
        if(userInput != "y") {
            return;
        }
    }
}

void generateGrid() {
    for (int y = 0; y < gridY; y++) {
        for (int x = 0; x < gridX; x++) {
            grid[y][x] = " *";
        }
    }
}

void intialGridPrint() {
    for (int y = 0; y < gridY; y++) {
        for (int x = 0; x < gridX; x++) {
            if (x == startX && y == startY) {
                cout << " P";
            } else {
                cout << grid[y][x];
            }
        }
        cout << endl;
    }
    cout << endl << endl;
}

void playerMovementInput() {
    cin >> direction;
    if (direction == "L" || direction == "l")
        cout << "Thanks for playing!\n";
    else if (direction == "W" || direction == "w")
        movementY--;
    else if (direction == "S" || direction == "s")
        movementY++;
    else if (direction == "d" || direction == "D")
        movementX++;
    else if (direction == "a" || direction == "A")
        movementX--;
    else if((gameOver == true || gameBeat == true) && direction == "y"){

    }
    else if(gameOver == true && direction == "n"){
        exitGame = true;
    }
    else
        cout << "Invalid entry no movement\n";

    if (movementY > cordinateYMax)
        movementY--;
    else if (movementY < 0)
        movementY++;
    if (movementX > cordinateXMax)
        movementX--;
    else if (movementX < 0)
        movementX++;
}

void newGridGenerationThread() {
    int gameCycle = 0;
    while (true) {
        this_thread::sleep_for(chrono::seconds(1));
        if(gameCycle < 5) {
            for (int y = 0; y < gridY; y++) {
                for (int x = 0; x < gridX; x++) {
                    if (x == movementX && y == movementY) {
                        cout << " P";
                    } else {
                        cout << grid[y][x];
                    }
                }
                cout << endl;
            }
        }
        else if(gameCycle == 5 || gameCycle == 6){
            for (int y = 0; y < gridY; y++) {
                for (int x = 0; x < gridX; x++) {
                    if (x == movementX && y == movementY) {
                        cout << " P";
                    }
                    else if(x == 0 || x == 2 || x == 4 || x == 6 || x== 8){
                        cout << " 0";
                    }
                    else {
                        cout << grid[y][x];
                    }
                }
                cout << endl;
            }
        }
        else if(gameCycle == 7){
            for (int y = 0; y < gridY; y++) {
                for (int x = 0; x < gridX; x++) {
                    if (x == movementX && y == movementY) {
                        cout << " P";
                    }
                    else if(x == 0 || x == 2 || x == 4 || x == 6 || x== 8){
                        cout << " X";
                    }
                    else {
                        cout << grid[y][x];
                    }
                }
                cout << endl;
            }
            if(movementX == 0 || movementX ==2|| movementX ==4||movementX ==6|| movementX ==8){
                gameOver = true;
                cout << "You got hit - Game Over\nWould you like to try again?(y/n)";
                return;
            }
        }
        else if(gameCycle == 8 || gameCycle == 9) {
            for (int y = 0; y < gridY; y++) {
                for (int x = 0; x < gridX; x++) {
                    if (x == movementX && y == movementY) {
                        cout << " P";
                    } else {
                        cout << grid[y][x];
                    }
                }
                cout << endl;
            }
        }
        else if(gameCycle == 10 || gameCycle == 11){
            for (int y = 0; y < gridY; y++) {
                for (int x = 0; x < gridX; x++) {
                    if (x == movementX && y == movementY) {
                        cout << " P";
                    }
                    else if(y == 1 || y == 3 || y == 5 || y == 7 || y == 9){
                        cout << " 0";
                    }
                    else {
                        cout << grid[y][x];
                    }
                }
                cout << endl;
            }
        }
        else if(gameCycle == 12){
            for (int y = 0; y < gridY; y++) {
                for (int x = 0; x < gridX; x++) {
                    if (x == movementX && y == movementY) {
                        cout << " P";
                    }
                    else if(y == 1 || y == 3 || y == 5 || y == 7 || y == 9){
                        cout << " X";
                    }
                    else {
                        cout << grid[y][x];
                    }
                }
                cout << endl;
            }
            if(movementY == 1 || movementY ==3|| movementY ==5||movementY ==7|| movementY ==9){
                gameOver = true;
                cout << "You got hit - Game Over\nWould you like to try again?(y/n)\n";
                return;
            }
        }
        else if(gameCycle == 13 || gameCycle == 14) {
            for (int y = 0; y < gridY; y++) {
                for (int x = 0; x < gridX; x++) {
                    if (x == movementX && y == movementY) {
                        cout << " P";
                    } else {
                        cout << grid[y][x];
                    }
                }
                cout << endl;
            }
        }
        else if(gameCycle == 15 || gameCycle == 16){
            for (int y = 0; y < gridY; y++) {
                for (int x = 0; x < gridX; x++) {
                    if (x == movementX && y == movementY) {
                        cout << " P";
                    }
                    else if(y == 1 || y == 3 || y == 5 || y == 7 || y == 9 || x == 0 || x==2 || x ==4 || x== 6 || x== 8){
                        cout << " 0";
                    }
                    else {
                        cout << grid[y][x];
                    }
                }
                cout << endl;
            }
        }
        else if(gameCycle == 17){
            for (int y = 0; y < gridY; y++) {
                for (int x = 0; x < gridX; x++) {
                    if (x == movementX && y == movementY) {
                        cout << " P";
                    }
                    else if(y == 1 || y == 3 || y == 5 || y == 7 || y == 9 || x == 0 || x==2 || x ==4 || x== 6 || x== 8){
                        cout << " X";
                    }
                    else {
                        cout << grid[y][x];
                    }
                }
                cout << endl;
            }
            if(movementY == 1 || movementY == 3 || movementY == 5 || movementY == 7 || movementY == 9 || movementX == 0 || movementX==2 || movementX ==4 || movementX== 6 || movementX== 8){
                gameOver = true;
                cout << "You got hit - Game Over\nWould you like to try again?(y/n)\n";
                return;
            }
        }
        else if(gameCycle == 18 || gameCycle == 19) {
            for (int y = 0; y < gridY; y++) {
                for (int x = 0; x < gridX; x++) {
                    if (x == movementX && y == movementY) {
                        cout << " P";
                    } else {
                        cout << grid[y][x];
                    }
                }
                cout << endl;
            }
        }
        else if(gameCycle == 20|| gameCycle == 21){
            for (int y = 0; y < gridY; y++) {
                for (int x = 0; x < gridX; x++) {
                    if (x == movementX && y == movementY) {
                        cout << " P";
                    }
                    else if(y == 0 ||y == 1 || y == 2 || y == 3 || y == 6 || y == 7 || y == 8 || y == 9
                            || x == 0 || x==1 || x ==2 || x== 3 || x== 6 || x == 7 || x == 8 || x == 9){
                        cout << " 0";
                    }
                    else {
                        cout << grid[y][x];
                    }
                }
                cout << endl;
            }
        }
        else if(gameCycle == 22){
            for (int y = 0; y < gridY; y++) {
                for (int x = 0; x < gridX; x++) {
                    if (x == movementX && y == movementY) {
                        cout << " P";
                    }
                    else if(y == 0 ||y == 1 || y == 2 || y == 3 || y == 6 || y == 7 || y == 8 || y == 9
                            || x == 0 || x==1 || x ==2 || x== 3 || x== 6 || x == 7 || x == 8 || x == 9){
                        cout << " X";
                    }
                    else {
                        cout << grid[y][x];
                    }
                }
                cout << endl;
            }
            if(movementY == 0 || movementY == 1 || movementY == 2 || movementY == 3 || movementY == 6 || movementY == 7 || movementY == 8 || movementY == 9 ||
               movementX == 0 || movementX==1 || movementX ==2 || movementX== 3 || movementX== 6 || movementX== 7 || movementX== 8 || movementX== 9 ){
                gameOver = true;
                cout << "You got hit - Game Over\nWould you like to try again?(y/n)\n";
                return;
            }
        }
        else if(gameCycle == 23){
            cout << "You Won Good Job\n";
            cout << "Type \"y\" to receive your reward\n";
            gameBeat = true;
            return;
        }


        cout << endl;
        gameCycle++;
    }
}
#endif //ZORKGAME_GAMEEVENTS_H
