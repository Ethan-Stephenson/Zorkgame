#ifndef CONSTANTS_H
#define CONSTANTS_H

using std::string;
struct constants{
public:
    //Room Id
    //Kitchen
    static const int kitchenId = 1;
    static const inline string kitchenDesc = "You are standing in a heartwarming kitchen, a table with a cookbook on it, an oven to your left, a knife rack, and a giant door with a cookie-shaped keyhole on it in front of you.";
    constexpr static const int kitchenAdjecent[5]{0,1,0,0,0};
    //castle
    static const int castleId = 2;
    static const inline string castleDesc = "You are inside a castle room, there is a fireplace with a torch above it, to your left a spice cabinet, and to your right are five paintings.";
    constexpr static const int castleAdjecent[5]{1,0,1,0,0};
    //ComputerRoom
    static const int computerID = 3;
    static const inline string computerDesc = "You are in a room full of modern tech, a wall full of monitors on your left, and a safe to your right.";
    constexpr const static int computerAdjecent[5]{0,1,0,1,0};
    //Greenhouse
    static const int greenhouseID = 4;
    static const inline string greenhouseDesc = "You are in a greenhouse full of lush green plants, a giant arugula ahead of you blocking some kind of piping, wheat to your left, and a weird mechanical object to your right.";
    constexpr static const int greenhouseAdjecent[5]{0,0,1,0,1};
    //Workshop
    static const int workshopID = 5;
    static const inline string workshopDesc = "You are in a workshop with sawdust that covers the floor. In the middle of the room is a wooden pedestal with cut-out shapes sitting on top.";
    constexpr static const int workshopAdjecent[5]{0,0,0,1,0};



    //Items
    static const inline string bucket = "bucket";
    static const inline string temperatureNote = "note";
    static const inline string flour = "flour";
    static const inline string sugar = "sugar";
    static const inline string butter = "butter";
    static const inline string cookieKey = "cookieKey";
    static const inline string knife = "knife";
    static const inline string torch = "torch";
    static const inline string herbicide = "herbicide";
    static const inline string waterBucket = "waterBucket";



    //Inspect
    //kitchen
    static const inline string cookBook = "A cook book lies on a table laying out the ingredients for a cookie key.\n  The ingredients are flour, sugar, and butter cooked at a temperature that is cut out\n";
    static const inline string sinkNoWater = "There is a metal sink, though when moving the handles no water comes out\n";
    static const inline string sinkWaterNobucket = "The sink is now able to have water flow out of the faucet, but you need something to fill with water\n";
    static const inline string sinkWaterBucket = "With the sink now able to give water you can fill your bucket\n";
    static const inline string knifeRack = "One chef's knife sticks out of the wooden knife rack\n";
    static const inline string cookieDoor = "A giant door made out of what seems to be cookie has a key slot in the middle of it\n";
    static const inline string cookieDoorWithKey = "As you push in the key into the door, a loud click rings out\nThe door swings open to reveal a lush forest \n You have beaten the game, Thanks for Playing!";
    static const inline string oven = "A electric oven sits in the kitchen with a mold inside for what looks like a key\n";
    //castle
    static const inline string ovenCompleted = "You put all the ingredients inside the oven and turn it to the correct temperature\n After 10 minutes of waiting the oven dings and reveals a cookie key\n";
    static const inline string torchGrab = "A torch sits on a metal stand, would you like to grab it?(y/n)\n";
    static const inline string spiceCabinet = "A large wooden cabinet filled with exotic spices is locked shut\n When looking though the glass on the front you can see what looks like sugar\n";
    static const inline string spiceCabinetOpen = "The spice cabinet is now open, and in the front you can see a bag of sugar\nWould you like to grab the sugar?(y/n)\n";
    static const inline string paintings = "5 paintings are hanged on the walls each portraying a battle, here is each description:\n1:French forces losing at Waterloo\n2:Troops storming the beaches of Normandy"
                                           "\n3:Units charging into Gettysburg\n4:The British surrendering at the end of the Battle of York Town\n5:Bullets flying over no man's land in The Battle of Verdun\n";
    static const inline string paintingsQuestion = "Would you like to try to reorder them?(y/n)\n";
    static const inline string paintingsDone = "The paintings are already arranged";


};
#endif