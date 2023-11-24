using std::string;
struct constants{
public:
    //Kitchen
    static const int kitchenId = 1;
    static const inline string kitchenDesc = "You are standing in a heartwarming kitchen, a giant fridge to the right, a table with a cookbook on it, many drawers, an oven to your left, and a giant door with a cookie-shaped keyhole on it in front of you.";
    constexpr static const int kitchenAdjecent[5]{0,1,0,0,0};
    //Medevial
    static const int medevialId = 2;
    static const inline string medevialDesc = "You are inside a castle room, there is a fireplace with a torch above it to your left a spice cabinet, and to your right are five paintings.";
    constexpr static const int medevialAdjecent[5]{1,0,1,0,0};
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
    static const inline string workshopDesc = "You are in a workshop with sawdust that covers the floor.  Tools and a variety of machines scatter the room including a bandsaw.  In the middle of the room is a wooden pedestal with cut-out shapes sitting on top.";
    constexpr static const int workshopAdjecent[5]{0,0,0,1,0};








};