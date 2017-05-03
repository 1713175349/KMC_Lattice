// Copyright (c) 2017 Michael C. Heiber
// This source file is part of the KMC_Lattice project, which is subject to the MIT License.
// For more information, see the LICENSE file that accompanies this software.
// The KMC_Lattice project can be found on Github at https://github.com/MikeHeiber/KMC_Lattice

#ifndef EVENT_H
#define EVENT_H

#include "Utils.h"
#include "Object.h"
#include <list>
#include <memory>
#include <random>

using namespace std;

class Object;

class Event{
    public:
        static mt19937 gen;
        virtual ~Event();
        Event();
        virtual void calculateEvent(const Coords& dest_coords, const double rate) = 0;
        Coords getDestCoords() const;
        virtual string getName() const;
        list<unique_ptr<Object>>::iterator getObjectIt() const;
        list<unique_ptr<Object>>::iterator getObjectTargetIt() const;
        double getWaitTime() const;
        void setDestCoords(const Coords& coords);
        void setWaitTime(const double time);
        void setObjectIt(const list<unique_ptr<Object>>::iterator it);
        void setObjectTargetIt(const list<unique_ptr<Object>>::iterator it);
    protected:
        // Variables
        // Functions
        double rand01();
    private:
        // Variables and objects
        static const string name_base;
        double wait_time;
        list<unique_ptr<Object>>::iterator object_it;
        list<unique_ptr<Object>>::iterator object_target_it;
        Coords coords_dest;
};

#endif // EVENT_H
