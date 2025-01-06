#include "../inc/pov/pov_background.h"
using namespace POV;

POVBackGround::POVBackGround():POVObject("background"){
}

POVBackGround::~POVBackGround(){}

bool POVBackGround::setBackGroundColor(const Color & other){
    color = {other.r, other.g, other.b};
    return true;
}

bool POVBackGround::parserPOV(std::ofstream & os){
    std::string data[] = {"background {color srgb <" + std::to_string((float)color.r/255)\
         + "," + std::to_string((float)color.g/255) + "," + std::to_string((float)color.b/255) + "> }\n", "\n"};

    // write lines to file
    for (const auto& line : data) {
        std::cout << line;
        os << line;
    }
    return true;
}