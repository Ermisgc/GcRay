#include "../inc/pov/pov_camera.h"

using namespace POV;

POVCamera::POVCamera():m_focal(1.0), _look_at({0,0,0}), _loc({0, 0, 500}), POVObject("camera"){
}

POVCamera::POVCamera(const Location & loc, const Location & la): m_focal(1.0), _look_at(la), _loc(loc), POVObject("camera"){

}

POVCamera::POVCamera(const POVCamera & other):POVObject("camera"){
    this->_loc = other._loc;
    this->_look_at = other._look_at;
    this->m_focal = other.m_focal;
}

POVCamera::~POVCamera(){

}

bool POVCamera::parserPOV(std::ofstream & os){
    std::string data[] = {
        "camera {\n",
        "   up <0,1,0>\n",
        "   right -x*image_width/image_height\n",
        "   location <" + std::to_string(_loc.x) + "," + std::to_string(_loc.y) + "," + std::to_string(_loc.z) + ">\n",  //location is defined by normal position
        "   look_at <" + std::to_string(_look_at.x) + "," + std::to_string(_look_at.y) + "," + std::to_string(_look_at.z) + ">\n",
        "   angle 32.9346087425027\n", //angle is defined by focal
        "}\n"  
    };

    // write lines to file
    for (const auto& line : data) {
        // std::cout << line << std::endl;
        os << line;
    }
    return true;
}

bool POVCamera::setLocation(const Location & loc){
    _loc = {loc.x, loc.y, loc.z};
    return true;
}

bool POVCamera::setLookAt(const Location & loc){
    _look_at = {loc.x, loc.y, loc.z};
    return true;
}