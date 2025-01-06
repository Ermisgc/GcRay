#include <iostream>
#include "./pov_parser.h"
#include "pov_camera.h"
#include "pov_model.h"
#include "pov_lightsource.h"
#include "pov_background.h"

using namespace POV;

int main() {
	POV::POVParser obj;
	//background
	POVBackGround * bg = new POVBackGround();
	bg->setBackGroundColor({255, 255, 255});
	obj.setbackground(bg);

	//lightsource
	POV::POVLightSource * pls = new POVLightSource();
	pls->setLightSource({9.2131,2.04121,-13.312412});
	obj.setLightSource(pls);
	//camera
	POV::POVCamera * cmr = new POVCamera();
	cmr->setEuleAngle({26.124314,34.412451,-21.31241});
	obj.setCamera(cmr);
	POVModel * model = new POVModel("falanguanban3");
	model->setTexture("poseraylogo.png");
	obj.importObject(model);
	obj.parserPOV();
	return 0;
}