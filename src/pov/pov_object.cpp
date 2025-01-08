#include "../inc/pov/pov_object.h"

using namespace POV;

POVObject::POVObject(const std::string & name): object_name(name){}
POVObject::~POVObject(){}

std::string POVObject::name(){
    return object_name;
}