#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP
#include "Ninja.hpp"

class TrainedNinja : virtual public Ninja{
    public:
    TrainedNinja(string name , Point location);
};

#endif