using std::string;

class RoomSystem{
    public:
        void setRoom(int);
        int getRoom();
        string adjecentRooms();




    private:
        int roomNumber = 1;


};


void RoomSystem::setRoom(int setRoom) {
    roomNumber = setRoom;
}

int RoomSystem::getRoom() {
    return roomNumber;
}

string RoomSystem::adjecentRooms(){
    string text;

    return text;

}



