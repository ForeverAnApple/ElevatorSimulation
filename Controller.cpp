#include "Controller.h"

Controller::Controller()
{
}

Controller::~Controller()
{
}

void Controller::tick()
{
  std::cout << "CONTROLLER TICK\n";
  elevatorTick();
  lobbyTick();
}

//loops through all elevators
void Controller::elevatorTick()
{
  std::cout << "INSIDE ELEVATOR TICK\n";

  //Cycle through all of the elevators
  for(int i = 0; i < elevators->size(); i++)
    {
      //When the elevator is empty, the elevator sets it direction towards the first thing
      //on the task list. However, when the elevator has people inside, the elevator's
      //direction is set to the first person's destination
      if(elevators->at(i)->people().size() == 0 && tasks.size() != 0) {
        elevators->at(i)->dir() =
          tasks.at(0) < elevators->at(i)->at() ? -1 :
          tasks.at(0) > elevators->at(i)->at() ? 1 : 0;
        std::cout << "Removed task at floor " << tasks.at(0) << std::endl;
        tasks.erase(tasks.begin());
        std::cout << "Tasks size: " << tasks.size() << std::endl;
      }
      else if(elevators->at(i)->people().size() != 0) {
        elevators->at(i)->dir() = elevators->at(i)->people().at(0)->dir();
      }
      else if(elevators->at(i)->people().size() == 0 && tasks.size() == 0)
        elevators->at(i)->dir() = 0;
      
      // MOVE THE ELEVATOR
      elevators->at(i)->move(elevators->at(i)->dir());

      
      std::cout << "Find inside ELEVATOR returned: " << elevators->at(i)->find() << std::endl;
      //Find people who are at their target destination and
      //put them in their according lobby
      while(elevators->at(i)->find() != -1)
        {
          //Put the current person inside of the lobby
          lobbies->at(elevators->at(i)->at())->add(elevators->at(i)->
                                                   people().at(elevators->at(i)->find()));

          std::cout << "Person found: \n" << elevators->at(i)->people().at(elevators->at(i)->find())
                    << std::endl;
          //Remove the current person from the elevator
          elevators->at(i)->remove(elevators->at(i)->find());
        }
    }
}
    
void Controller::lobbyTick()
{
  std::cout << "INSIDE LOBBY TICK \n";

  //UPDATE THE TASK LIST
  for(int i = 0; i < lobbies->size(); i++)
    {
      for(int n = 0; n < elevators->size(); n++)
        {
          std::cout << "Find inside LOBBY " << i << "returned: "
                    << lobbies->at(i)->find(elevators->at(n)->Weight_left(),
                                            elevators->at(n)->destination()) << std::endl;
          while(lobbies->at(i)->find(elevators->at(n)->Weight_left(),
                                     elevators->at(n)->destination()) != -1)
            {
              if(elevators->at(n)->at() == lobbies->at(i)->FLOOR())
                {
                  std::cout << "Moved person at floor " << i << " to elevator " << n << std::endl;
                  //Put the current person inside of the elevator
                  elevators->at(n)->add(lobbies->at(i)->
                                        people().at(lobbies->at(i)->
                                                    find(elevators->at(n)->Weight_left(),
                                                         elevators->at(n)->destination())));
                  //Remove the current person from the lobby
                  lobbies->at(i)->remove(lobbies->at(i)->
                                         find(elevators->at(n)->Weight_left(),
                                              elevators->at(n)->destination()));
                }
              else
                continue;
            }
        }
      if(lobbies->at(i)->people().size() != 0)
        {
          bool isTask = true;
          for(int n = 0; n < tasks.size(); n++)
            {
              std::cout << "Person at floor " << i << "'s dir returned: "
                        << lobbies->at(i)->people().at(0)->dir() << std::endl;
              if(tasks.at(n) == lobbies->at(i)->people().at(0)->source() ||
                 lobbies->at(i)->people().at(0)->dir() == 0) {
              
                isTask = false;
              }
            }
          std::cout << "Task checking done.\n";
          if(isTask && lobbies->at(i)->people().at(0)->dir() != 0){
            tasks.push_back(i);
            std::cout << "Added task to floor " << i << std::endl;
            std::cout << "Tasks size: " << tasks.size() << std::endl;
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
