#include "../inc/pov/pov_lightsource.h"
using namespace POV;

POVLightSource::POVLightSource():POVObject("lightsource"){
}

POVLightSource::~POVLightSource(){
}

bool POVLightSource::setLightSource(const EuleAngle & other){
    ea = {other.roll, other.pitch, other.yaw};
    return true;
}

bool POVLightSource::setLightSource(float r, float p, float y){
    ea = {r, p, y};
    return true;
}

bool POVLightSource::parserPOV(std::ofstream & os){
    std::string data[] = {
        "light_source {\n",
        "   <0,0,651.257121237851>\n",
        "   color rgb <1,1,1>*1.0\n",
        "   parallel\n",  //location is defined by normal position
        "   point_at <0,0,0>\n",
        "   rotate <0,0," + std::to_string(this->ea.roll) + ">\n",  //roll
        "   rotate <" + std::to_string(this->ea.pitch) + ",0,0>\n",   //pitch
        "   rotate <0," + std::to_string(this->ea.yaw) + ",0>\n",     //yaw
        "}\n"  
    };

    // write lines to file
    for (const auto& line : data) {
        std::cout << line;
        os << line;
    }
    return true;
}    