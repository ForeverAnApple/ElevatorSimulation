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
      Elevator * e = elevators->at(i);
      if(e->people().size() == 0 && tasks.size() != 0) {
        e->dir() =
          tasks.at(0) < e->at() ? -1 :
               tasks.at(0) > e->at() ? 1 : 0;
        std::cout << "Removed task at floor " << tasks.at(0) << std::endl;
        tasks.erase(tasks.begin());
        std::cout << "Tasks size: " << tasks.size() << std::endl;
      }
      else if(e->people().size() != 0) {
        e->dir() = e->people().at(0)->dir();
      }
      else if(e->people().size() == 0 && tasks.size() == 0)
        e->dir() = 0;
      
      // MOVE THE ELEVATOR
      e->move(e->dir());

      
      std::cout << "Find inside ELEVATOR returned: " << e->find() << std::endl;
      //Find people who are at their target destination and
      //put them in their according lobby
      while(e->find() != -1)
        {
          //Put the current person inside of the lobby
          lobbies->at(e->at())->add(e->people().at(e->find()));

          std::cout << "Person found: \n" << e->people().at(e->find())
                    << std::endl;
          //Remove the current person from the elevator
          e->remove(e->find());
        }
    }
}
    
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
                  //Put the current person inside of the elevator
                  e->add(l->
                         people().at(l->
                                     find(e->Weight_left(),
                                          e->destination())));
                  //Remove the current person from the lobby
                  l->remove(l->
                            find(e->Weight_left(),
                                 e->destination()));
                }
              else
                continue;
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
