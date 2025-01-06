#include "../inc/pov/pov_sphere.h"
using namespace POV;

Sphere::Sphere(float _, const Location & _l): radius(_), _loc({_l.x, _l.y, _l.z}), POVObject("sphere"){

}

Sphere::Sphere(const Sphere& other): radius(other.radius), _loc({other._loc.x, other._loc.y, other._loc.z}), POVObject("sphere"){
}

bool Sphere::setRadius(float _){
    if(_ <= 0) return false;
    this->radius = _;
    return true;
}

bool Sphere::setLocation(const Location & _l){
    this->_loc = {_l.x, _l.y, _l.z};
    return true;
}

bool Sphere::setTexture(std::string _name){
    //parser the name of png file:
    int pos = _name.find('.');
    std::string temp = _name.substr(pos + 1, 3);
    if(temp != "png"){
        std::cout << "The texture image should be a .png file" << std::endl;
        return false;
    }
    m_texture = _name.substr(0, pos);
    return true;
}

bool Sphere::parserPOV(std::ostream & os){
    std::string texture_name = m_texture.substr(0, m_texture.find('.'));
    std::string texture_type = m_texture.substr(m_texture.find('.'), 3);
    std::string data[] = {
        "sphere{\n",
        "   <" + std::to_string(_loc.x) + "," + std::to_string(_loc.y) + "," + std::to_string(_loc.z) + "> " + std::to_string(radius) + "\n",
        "   texture{\n",
        "       pigment { image_map { " + texture_type + " \"" + texture_name +  "\"} }\n",
        "   }    \n",
        "}\n"
    };

    // write lines to file
    for (const auto& line : data) {
        std::cout << line << std::endl;
        os << line;
    }
    return true;
}