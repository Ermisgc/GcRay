#include "../inc/pov/pov_camera.h"

using namespace POV;

POVCamera::POVCamera():m_focal(1.0), ea({0,0,0}), POVObject("camera"){
}

POVCamera::POVCamera(const POVCamera & other):POVObject("camera"){
    this->ea = other.ea;
    this->m_focal = other.m_focal;
}
POVCamera::~POVCamera(){

}

bool POVCamera::parserPOV(std::ofstream & os){
    std::string data[] = {
        "camera {\n",
        "   up <0,1,0>\n",
        "   right -x*image_width/image_height\n",
        "   location <0,0,651.257121237851>\n",  //location is defined by normal position
        "   look_at <0,0,650.257121237851>\n",
        "   angle 32.9346087425027\n", //angle is defined by focal
        "   rotate <0,0," + std::to_string(this->ea.roll) + ">\n",  //roll
        "   rotate <" + std::to_string(this->ea.pitch) + ",0,0>\n",   //pitch
        "   rotate <0," + std::to_string(this->ea.yaw) + ",0>\n",     //yaw
        "   translate <345.86999512,0,0>\n" ,
        "}\n"  
    };

    // write lines to file
    for (const auto& line : data) {
        std::cout << line << std::endl;
        os << line;
    }
    return true;
}

bool POVCamera::setEuleAngle(const EuleAngle & other){
    this->ea = {other.roll, other.pitch, other.yaw};
    return true;
}