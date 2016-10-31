#ifndef LOBBY_H
#define LOBBY_H

#include <vector>
#include "Person.h"

class Lobby {
public:
    Lobby(const int, const int);
    ~Lobby();
    std::vector<Person> const & people() const{return person_;}
    std::vector<Person> & people(){return person_;}
    int const MAX_WEIGHT() const{return MAX_WEIGHT_;}
    int const FLOOR() const{return FLOOR_;}
private:
    int const MAX_WEIGHT_, FLOOR_;
    std::vector<Person> person_;

protected:
};

std::ostream & operator<<(std::ostream &,
                          Lobby const &);
#endif
