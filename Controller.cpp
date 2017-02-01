#include "Controller.h"

Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::tick()
{
    elevatorTick();
    lobbyTick();
}

//loops through all elevators
void Controller::elevatorTick()
{
    //Cycle through all of the elevators
    for(int i = 0; i < elevators->size(); i++)
    {
        //Setup so that if it is at its destination it will not move
        //If the elevator is below its destination move up
        if(elevators->at(i)->destination() < elevators->at(i)->at())
            elevators->at(i)->move(1);
        //If the elevator is above its destination move down
        else if(elevators->at(i)->destination() > elevators->at(i)->at())
            elevators->at(i)->move(-1);


        //Find people who are at their target destination and
        //put them in their according lobby
        while(elevators->at(i)->find() != -1)
        {
            //Put the current peson inside of the lobby
            lobbies->at(elevators->at(i)->at())->add(elevators->
                                                     at(i)->people()->at(elevators->at(i)->find()));
            //Remove the current person from the elevator
            elevators->at(i)->remove(elevators->at(i)->find());
        }                                                                                                                                                              
    }
}
    


void Controller::lobbyTick()
{
    
}

void Controller::addElevator(std::vector<Elevator *> * e)
{
    elevators = e;
}

void addLobby(std::vector<Lobby *> * l)
{
    lobbies = l;
}


