#ifndef CONSTANTS_H
#define CONSTANTS_H

using std::string;
struct constants{
public:
    //Room Id
    //Kitchen
    static const int kitchenId = 1;
    static const inline string kitchenDesc = "You are standing in a heartwarming kitchen, a table with a cookbook on it, an oven to your left, a knife rack, and a giant door with a cookie-shaped keyhole on it in front of you.\n";
    constexpr static const int kitchenAdjecent[5]{0,1,0,0,0};
    //castle
    static const int castleId = 2;
    static const inline string castleDesc = "You are inside a castle room, there is a fireplace with a torch above it, to your left a spice cabinet, and to your right are five paintings.\n";
    constexpr static const int castleAdjecent[5]{1,0,1,0,0};
    //ComputerRoom
    static const int computerID = 3;
    static const inline string computerDesc = "You are in a room full of modern tech, a wall full of monitors on your left, and a safe to your right.\n";
    constexpr const static int computerAdjecent[5]{0,1,0,1,0};
    //Greenhouse
    static const int greenhouseID = 4;
    static const inline string greenhouseDesc = "You are in a greenhouse full of lush green plants, a giant arugula ahead of you blocking some kind of piping, wheat to your left, and a weird mechanical object to your right.\n";
    constexpr static const int greenhouseAdjecent[5]{0,0,1,0,1};
    //Workshop
    static const int workshopID = 5;
    static const inline string workshopDesc = "You are in a workshop with sawdust that covers the floor. In the middle of the room is a wooden pedestal with cut-out shapes sitting on top.\n";
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
    //Computer
    static const inline string computer = "A pile of computer hardware lays beside a monitor\nThe screen blinks with the message - \"Beat my games and receive a reward\"\nWould you like to play the game?(y/n)\n";
    static const inline string computerDone = "The computer is now shut off\n";
    static const inline string safe = "A locked safe sticks beside the computer, wires are running from the computer to the safe\n";
    static const inline string safeOpen = "The safe is now open, inside is what looks like a cut out note with a temperature on it\nWould you like to grab it?(y/n)";
    //Greenhouse
    static const inline string arugula = "A 7 foot tall arugula monster is blocking the way to the pipes, would you like to try to fight it?(y/n)\n";
    static const inline string arugulaDead = "The arugula is now dead on the floor not moving\n";
    static const inline string wheat = "Dried out and dying wheat sits on a bed of dirt, it looks like it needs some water\n";
    static const inline string wheatPour = "Would you like to pour the water on the wheat?(y/n)\n";
    static const inline string wheatDone = "You pour the water on the wheat and it grows instantly, would you like to pick it?(y/n)\n";
    static const inline string wheatPicked = "There is no more wheat left\n";
    static const inline string pipe = "A large faucet wheel is turned stopping the water, would you like to turn it?(y/n)\n";
    static const inline string waterFlow = "You hear water rushing through the pipe through the house\n";
    static const inline string pipeTurned = "You can't do anything more with the pipe\n";
    static const inline string machine = "A large grinder sits in the greenhouse, look like it could take wheat\n";
    static const inline string machineWheat= "Would you like to stick wheat into the machine?(y/n)\n";
    //Workshop
    static const inline string bucketItem = "A bucket sits on the sawdust floor, would you like to pick it up?(y/n)\n";
    static const inline string bucketGrabbed = "You already have the bucket\n";
    static const inline string pedestal = "A wooden pedestal sits in the middle of the room with different shapes on it\nWould you like to try to rearrange them?(y/n)\n";
    static const inline string pedestalDone = "A stick of butter sits inside the pedestal would you like to grab it?(y/n)\n";
};
#endif