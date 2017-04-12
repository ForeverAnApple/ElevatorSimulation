#include "Controller.h"

Controller::Controller(int floors)
{
  up = new bool[floors];
  down = new bool[floors];
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

  for(auto &e : *elevators) {
    e->tick(lobbies, tasks);
  }
}


// TODO: Update the task list inside the lobby, move people in and out through the elevator tick

void Controller::lobbyTick()
{
  std::cout << "INSIDE LOBBY TICK \n";

  //UPDATE THE TASK LIST
  for(int i = 0; i < lobbies->size(); i++)
    {
      Lobby * l = lobbies->at(i);
      for(int n = 0; n < elevators->size(); n++)
        {
          Elevator * e = elevators->at(n);
          std::cout << "Find inside LOBBY " << i << "returned: "
                    << l->find(e->Weight_left(),
                               e->destination()) << std::endl;
          while(l->find(e->Weight_left(),
                        e->destination()) != -1)
            {
              if(e->at() == l->FLOOR())
                {
                  std::cout << "Moved person at floor " << i << " to elevator " << n << std::endl;
                  Person* temp = l->people().at(l->find(e->Weight_left(), e->destination()));
                  //Put the current person inside of the elevator
                  e->add(temp);
                  
                  //Remove the current person from the lobby
                  l->remove(temp);
                }
              else
                break;
            }
        }
      if(l->people().size() != 0)
        {
          bool isTask = true;
          for(int n = 0; n < tasks.size(); n++)
            {
              std::cout << "Person at floor " << i << "'s dir returned: "
                        << l->people().at(0)->dir() << std::endl;
              if(tasks.at(n) == l->people().at(0)->source() ||
                 l->people().at(0)->dir() == 0) {
              
                isTask = false;
              }
            }
          std::cout << "Task checking done.\n";
          if(isTask && l->people().at(0)->dir() != 0){
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
