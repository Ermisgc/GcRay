#include "pov_model.h"
#include <fstream>
#include <string>

using namespace POV;
POVModel::POVModel(const std::string & object):m_lc(0, 0, 0), POVObject(object) {
}

POVModel::~POVModel() {
}

bool POVModel::setLocation(Location _lc) {
	m_lc = _lc;
    return true;
}

bool POVModel::setLocation(float _x, float _y, float _z){
    return setLocation({_x, _y, _z});
}

bool POVModel::setTexture(const std::string & _png){
    //parser the name of png file:
    int pos = _png.find('.');
    std::string temp = _png.substr(pos + 1, 3);
    if(temp != "png"){
        std::cout << "The texture image should be a .png file" << std::endl;
        return false;
    }
    m_texture = _png.substr(0, pos);
    return true;
}

bool POVModel::parserPOV(std::ofstream & os) {
    // Append object information
    std::string texture_name = m_texture.substr(0, m_texture.find('.'));
    std::string data[] = {
        "#declare " + texture_name + " = texture{",
        "    pigment{",
        "        image_map {png \"" + m_texture + "\"}",
        "    }",
        "}",
        "#include \"" + object_name + "_POV_geom.inc\" //Geometry",

        "//Assembled object that is contained in " + object_name + "_POV_geom.inc with no SSLT components",
        "object{",
        "      " + object_name + "_ ",
        "      texture{",
        "                 " + texture_name + "",
        "         }    ",
        "}"
    };
    // write lines to file
    for (const auto& line : data) {
        std::cout << line << std::endl;
        os << line;
    }
    return true;
}