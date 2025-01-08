#include <iostream>
#include "pov_parser.h"
#include "pov_camera.h"
#include "pov_model.h"
#include "pov_lightsource.h"
#include "pov_background.h"
#include "pov_box.h"

using namespace POV;

int main(int argc, char ** argv) {
	const std::string object_name = "falanguanban3";
	const Location object_center = {345.86999512, 0, 0};
	//generate 50 sphere-even position of camera
	Location camera_position;

	
	POV::POVParser obj;
	obj.addObject(new POV::Box({-2,-2,-2}, {2, 2, 2}, 1.5));
	obj.parserPOV("test2.pov");
	return 0;
}