
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Elevator.h"
#include "Lobby.h"
#include <iostream>

class Controller
{
    
public:
    Controller();
    ~Controller();
    void tick();
private:
    void elevatorTick();
    void lobbyTick();

    //Add Stuff
    void addElevator(std::vector<Elevator *> * e);
    void addLobby(std::vector<Lobby *> * l);
    //Hold Stuff
    std::vector<Elevator *> *  elevators;
    std::vector<int> tasks;
    std::vector<Lobby *> * lobbies;
    

};

#endif
