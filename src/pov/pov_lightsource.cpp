#include "../inc/pov/pov_lightsource.h"
using namespace POV;

// POVLightSource::POVLightSource():POVObject("lightsource"){
// }

POVLightSource::~POVLightSource(){
}

POVLightSource::POVLightSource(const POVLightSource & other): _loc(other._loc), POVObject("lightsource"){
}

POVLightSource::POVLightSource(Location && loc): _loc(loc), POVObject("lightsource"){

}

POVLightSource::POVLightSource(Location & loc):_loc(loc), POVObject("lightsource"){

}

bool POVLightSource::setLightSource(const Location & other){
    _loc = {other.x, other.y, other.z};
    return true;
}

bool POVLightSource::setLightSource(float x, float y, float z){
    _loc = {x, y, z};
    return true;
}

bool POVLightSource::parserPOV(std::ofstream & os){
    // std::string data[] = {
    //     "light_source {\n",
    //     "   <0,0,651.257121237851>\n",
    //     "   color rgb <1,1,1>*1.0\n",
    //     "   parallel\n",  //location is defined by normal position
    //     "   point_at <0,0,0>\n",
    //     "   rotate <0,0," + std::to_string(this->ea.roll) + ">\n",  //roll
    //     "   rotate <" + std::to_string(this->ea.pitch) + ",0,0>\n",   //pitch
    //     "   rotate <0," + std::to_string(this->ea.yaw) + ",0>\n",     //yaw
    //     "}\n"  
    // };

    std::string data[] = {
        "light_source {\n",
        "   <" + std::to_string(_loc.x) + "," + std::to_string(_loc.y) +"," + std::to_string(_loc.z) + ">\n",
        "   color rgb <1,1,1>*1.0\n",
        "}\n"  
    };


    // write lines to file
    for (const auto& line : data) {
        // std::cout << line;
        os << line;
    }
    return true;
}    