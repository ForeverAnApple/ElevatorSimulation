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
        else if(elevators->at(i)-> destination() ==  elevators->at(i)->at())
        {
            elevators->at(i)->destination() = tasks.at(0);
            tasks.erase(tasks.begin());
        }


        //Find people who are at their target destination and
        //put them in their according lobby
        while(elevators->at(i)->find() != -1)
        {
            //Put the current person inside of the lobby

            lobbies->at(elevators->at(i)->at())->add(elevators->at(i)->
                                                     people().at(elevators->at(i)->find()));
            //Remove the current person from the elevator
            elevators->at(i)->remove(elevators->at(i)->find());
        }                                                                                                                                                              
    }
}
    
void Controller::lobbyTick()
{
    for(int i = 0; i < lobbies->size(); i++)
    {
        for(int n = 0; n < elevators->size(); n++)
        {
            while(lobbies->at(i)->find(elevators->at(n)->Weight_left(),
                                       elevators->at(n)->destination() ) != -1)
            {
                if(elevators->at(n)->at() == lobbies->at(i)->FLOOR())
                {
                    //Put the current person inside of the elevator
                  elevators->at(n)->add(lobbies->at(i)->people().
                                        at(lobbies->at(i)->find(elevators->at(n)->Weight_left(),
                                                                elevators->at(n)->destination())));
                    //Remove the current person from the lobby
                    lobbies->at(i)->remove(lobbies->at(i)->find(elevators->at(n)->Weight_left(),
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
