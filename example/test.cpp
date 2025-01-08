#include <iostream>
#include "pov_parser.h"
#include "pov_camera.h"
#include "pov_model.h"
#include "pov_lightsource.h"
#include "pov_background.h"
#include "pov_box.h"
#include <random>

using namespace POV;

std::mt19937 gen((unsigned int) time(nullptr));  //seed
std::uniform_real_distribution<float> dis(-1.0, 1.0);  //distribution

inline Location marsaglia(float radius){
	float u = 1.0, v = 1.0;
	while(u * u + v * v > 1){
		u = dis(gen);
		v = dis(gen);
	}
	float sqs = u * u + v * v;
	return {static_cast<float>(2.0 * u * sqrt(1 - sqs) * radius), static_cast<float>(2.0 * v * sqrt(1 - sqs) * radius),\
		 static_cast<float>((1.0 - 2.0 * sqs) * radius)};
}

int main(int argc, char ** argv) {
	const std::string object_name = "falanguanban3";
	const int image_nums = 50;
	const int light_nums = 10;
	const Location object_center = {345.86999512, 0, 0};

	POV::POVParser obj;
	POVModel * model = new POVModel(object_name);
	model->setTexture("lipurple.bmp");  // the texture image
	obj.importObject(model);  
	obj.setbackground(new POVBackGround((Color){255, 255, 255}));

	for(int i = 0;i < light_nums; ++i){
		Location sphere = marsaglia(2000);
		Location light_position = {object_center.x + sphere.x, object_center.y + sphere.y, object_center.z + sphere.z};
		obj.setLightSource(new POVLightSource(light_position));
	}
	

	//generate 50 sphere-even position of camera
	for(int i = 0; i < image_nums; ++i){
		Location sphere = marsaglia(750);
		Location camera_position = {object_center.x + sphere.x, object_center.y + sphere.y, object_center.z + sphere.z};
		std::cout << camera_position.x << " " << camera_position.y << " " << camera_position.z << std::endl;
		obj.deleteObject("camera"); // delete the previous camera
		obj.setCamera(new POVCamera(camera_position, object_center));
		obj.parserPOV("scan_" + std::to_string(i) + ".pov");
	}
	return 0;
}