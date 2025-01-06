#include "../inc/pov/pov_box.h"
using namespace POV;

Box::Box(const Box & other):corner1(other.corner1), corner2(other.corner2), ior(other.ior), POVObject("Box"){
}
Box::Box(Location _1, Location _2, float _ior):corner1(_1), corner2(_2), ior(_ior), POVObject("Box"){}
Box::~Box(){}
		
bool Box::setCorners(Location _1, Location _2){
	corner1 = _1;
	corner2 = _2;
    return true;
}
bool Box::setIOR(float _ior){
    if(_ior < 1.0) return false;
	ior = _ior;
    return true;
}

bool Box::parserPOV(std::ofstream & os){
	std::string data[] = {
		"box {\n",
		"	<" + std::to_string(corner1.x) + ", " + std::to_string(corner1.y) + ", " + std::to_string(corner1.z) + ">, <" + \
		 std::to_string(corner2.x) + ", " + std::to_string(corner2.y) + ", " + std::to_string(corner2.z) + ">\n",
		"	texture {\n",
		"		pigment { color rgb <1, 1, 1> transmit 1.0 }\n",
		"		finish { ambient 0.1 diffuse 0.9 specular 1.0 roughness 0.001 }\n",
		"	}\n",
		"	interior { ior " + std::to_string(ior) + " }\n",
		"}\n"
	};
	
	for(auto & str: data){
		os << str;
	}

    return true;
}