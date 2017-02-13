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
        if(elevators[i]->destination() < elevators[i]->at())
            elevators[i]->move(1);
        //If the elevator is above its destination move down
        else if(elevators[i]->destination() > elevators[i]->at())
            elevators[i]->move(-1);
        else if(elevators[i]-> destination() ==  elevators[i]->at())
        {
            elevators[i]->destination() = tasks.at(0);
            tasks.erase(tasks.begin());
        }


        //Find people who are at their target destination and
        //put them in their according lobby
        while(elevators[i]->find() != -1)
        {
            //Put the current person inside of the lobby
          lobbies->at(elevators[i]->at())->add(elevators[i]->
                                                   people().at(elevators[i]->find()));
          
          //Remove the current person from the elevator
          elevators[i]->remove(elevators[i]->find());
        }
    }
}
    
void Controller::lobbyTick()
{
    for(int i = 0; i < lobbies->size(); i++)
    {
        for(int n = 0; n < elevators->size(); n++)
        {
            while(lobbies[i]->find(elevators->at(n)->Weight_left(),
                                       elevators->at(n)->destination() ) != -1)
            {
                if(elevators->at(n)->at() == lobbies[i]->FLOOR())
                {
                    //Put the current person inside of the elevator
                    elevators->at(n)->add(lobbies[i]->people().
                                          at(lobbies[i]->find(elevators->at(n)->Weight_left()
                                                                  , elevators->at(n)->destination())));
                    //Remove the current person from the lobby
                    lobbies[i]->remove(lobbies[i]->find(elevators->at(n)->Weight_left(),
                                                                elevators->at(n)->destination()));
                }    
            }
        }    
    }
}

void Controller::addElevator(std::vector<Elevator *> * e)
{
    elevators = e;
}

void Controller::addLobby(std::vector<Lobby *> * l)
{
    lobbies = l;
}
