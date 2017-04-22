#include "Event.h"

// Initialize static class members
const string Event::name_base = "Event";
boost::mt19937 Event::gen{static_cast<std::uint32_t>(0)};

Event::~Event(){

}

Event::Event(){
    wait_time = 0;
    coords_dest.x = 0;
    coords_dest.y = 0;
    coords_dest.z = 0;
}

Coords Event::getDestCoords(){
    return coords_dest;
}

float Event::getWaitTime(){
    return wait_time;
}

string Event::getName(){
    return name_base;
}

list<unique_ptr<Object>>::iterator Event::getObjectIt(){
    return object_it;
}

list<unique_ptr<Object>>::iterator Event::getObjectTargetIt(){
    return object_target_it;
}

double Event::rand01(){
    static boost::uniform_01<boost::mt19937> randn(gen);
    return randn();
}

void Event::seedGenerator(const int id){
    gen.seed(time(0)*(id+1));
}

void Event::setDestCoords(const Coords& coords){
    coords_dest.x = coords.x;
    coords_dest.y = coords.y;
    coords_dest.z = coords.z;
}

void Event::setWaitTime(const float time){
    wait_time = time;
}

void Event::setObjectIt(const list<unique_ptr<Object>>::iterator it){
    object_it = it;
}
