#ifndef LOBBY_H
#define LOBBY_H

#include <vector>
#include "Person.h"

class Lobby {
public:
    Lobby(const int, const int);
    ~Lobby();
    std::vector<Person> people() const{return person_;}
    std::vector<Person> & people(){return person_;}
    int MAX_WEIGHT() const{return MAX_WEIGHT_;}
    int FLOOR() const{return FLOOR_;}
private:
    const int MAX_WEIGHT_, FLOOR_;
    std::vector<Person> person_;

protected:
};

std::ostream & operator<<(std::ostream &,
                          const Lobby &);
#endif
