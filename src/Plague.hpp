//TODO write the entire Virus class
/*
Placed at a random location, it can live in states: ACTIVE, IDLE, or DEAD

Behavior:
    - If it eats, it will switch to ACTIVE for 300 frames, and expand in the food's direction by CEIL(curr_size/10)
    - After those 300 ACTIVE frames, it will become IDLE starting from the direction where food was not found
        //TODO math out the "opposite side" thing. overlay leftmostx -> rightmostx and rightmostx -> leftmostx for opposite
    - If IDLE for X frames, it will become DEAD, which is permanent and can be disconnected from the class.
    - If neighboring "pixel" is eating
        - If current pizel is IDLE
            - Set current to ACTIVE
        - If current pixel is ACTIVE
            - Reset Active ctr
        - If current pixel is DEAD
            - Do not pass food on beyond it
*/

#ifndef PLAGUE_HPP
#define PLAGUE_HPP

#include <vector>

#include "Console.hpp"

//TODO add "starring" effect when v expands

enum VStatus{
    UNINITIALIZED = 0,
    ACTIVE,
    IDLE,
    DEAD
};

struct PlaguePxl{
    Coord c;
    VStatus status;
    inline PlaguePxl(): c(), status(UNINITIALIZED){}
    inline PlaguePxl(VStatus newst): c(), status(newst){}
};

class Plague{
    public:
        Plague();
        ~Plague();
        std::vector<PlaguePxl> GetLoc();
    private:
        std::vector<PlaguePxl> thisLoc;
};

#endif