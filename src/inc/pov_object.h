#pragma once
#include <iostream>
#include <string>
#include "pov_base.h"

namespace POV {
	//base class of camera, lightsource, background, imported model and some other objects.
	class POVObject {
		friend class POVParser; //a friend class can use the private mathods.
	public:
		POVObject(const std::string & name);
		virtual ~POVObject();

	protected:  //users cannot directly parser this object to .pov
		std::string object_name;
		virtual bool parserPOV(std::ofstream & os) = 0;
	};

}