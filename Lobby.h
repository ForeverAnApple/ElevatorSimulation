#ifndef LOBBY_H
#define LOBBY_H

#include <vector>
#include "Person.h"

class Lobby {
public:
    Lobby(int const MAX_PPL = 10, int const FLOOR = 0);
    ~Lobby();
    std::vector<Person *> const & people() const{ return person_; }
    std::vector<Person *> & people(){ return person_; }
    int const MAX_PPL() const{ return MAX_PPL_; }
    int const FLOOR() const{ return FLOOR_; }
private:
    int const MAX_PPL_, FLOOR_;
    std::vector<Person *> person_;

protected:
};

std::ostream & operator<<(std::ostream &,
                          Lobby const & );
#endif
