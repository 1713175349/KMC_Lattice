#ifndef SITE_H
#define SITE_H

#include "Utils.h"
#include "Object.h"
#include <list>
#include <memory>

using namespace std;

class Site{
    public:
        virtual ~Site();
        Site();
        void clearOccupancy();
        bool isOccupied();
        void setOccupied();
    private:
        list<unique_ptr<Object>>::iterator object_it;
        bool occupied;
};

#endif // SITE_H
