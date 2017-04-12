#include "Elevator.h"

Elevator::Elevator(int const MAX_WEIGHT, int id)
  : at_(0), MAX_WEIGHT_(MAX_WEIGHT),
    destination_(0), id_(id), dir_(0)
{
    
}

Elevator::~Elevator() {

}

std::ostream & operator<<(std::ostream & cout,
                          Elevator const & e) {
  cout << "\n[------ELEVATOR------\nAt: " << e.at()
       << "\nDestination: " << e.destination()
       << "\nID: " << e.id()
       << "\nMAX WEIGHT: " << e.MAX_WEIGHT()
       << "\nDirection: " << e.dir();

  cout << "\n\nPeople In Elevator:\n";

  for(int i = 0; i < e.people().size(); ++i)
    {
      cout << *(e.people().at(i)) << "\n";
    }
  cout << "------END ELEVATOR------]\n";
    
  return cout;
}


// IMPORTANT TICK FUNCTION
void Elevator::tick(std::vector<Lobby *> * &lobbies, std::vector<int> &tasks)
{
  //When the elevator is empty, the elevator sets it direction towards the first thing
      //on the task list. However, when the elevator has people inside, the elevator's
      //direction is set to the first person's destination
      if(size() == 0 && tasks.size() != 0) {
        dir() =
          tasks.at(0) < at() ? -1 :
          tasks.at(0) > at() ? 1 : 0;
        std::cout << "Removed task at floor " << tasks.at(0) << std::endl;
        tasks.erase(tasks.begin());
        std::cout << "Tasks size: " << tasks.size() << std::endl;
      }
      else if(size() != 0) {
        dir() = people().at(0)->dir();
      }
      else if(size() == 0 && tasks.size() == 0)
        dir() = 0;
      
      // MOVE THE ELEVATOR
      move(dir());

      
      std::cout << "Find inside ELEVATOR returned: " << find() << std::endl;
      //Find people who are at their target destination and
      //put them in their according lobby
      while(find() != -1)
        {
          //Put the current person inside of the lobby
          lobbies->at(at())->add(people().at(find()));

          std::cout << "Person found: \n" << people().at(find())
                    << std::endl;
          //Remove the current person from the elevator
          remove(find());
        }
}




void Elevator::remove(int index)
{
  person_.erase(person_.begin() + index);
}

void Elevator::remove(Person * person)
{
  for(int i = 0; i < person_.size(); ++i)
    {
      if(person_.at(i)->id() == person->id())
        {
          person_.erase(person_.begin() + i);
          break;
        }
    }
}

void Elevator::add(Person * person)
{
  person_.push_back(person);
}

void Elevator::move(int x)
{
  at_ += x;
  for(int i = 0; i < person_.size(); ++i)
    person_.at(i)->source() += x;
}

int const Elevator::find()
{
  for(int i = 0; i < person_.size(); ++i) {
    if(at_ == person_.at(i)->destination()) {
      return i;
    }
  }
  return -1;
}

int const Elevator::size()
{
  return person_.size();
}
