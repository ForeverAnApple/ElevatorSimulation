
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Elevator.h"
#include "Lobby.h"


class Controller
{
    
Public:
    Controller();
    ~Controller();
    void tick();
Private:
    void elevatorTick();
    void lobbyTick();

    //Add Stuff
    void addElevator(Elevator *);
    void addLobby(Lobby *);
    //Hold Stuff
    std::vector<Elevator *> *  elevators;
    std::vector<int *> tasks;
    std::vector<Lobby *> * lobbies;
    

};

#endif
