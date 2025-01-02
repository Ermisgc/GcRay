#pragma once
#include <iostream>
#include <string>
#include "pov_base.h"

namespace POV {
	class Object {
		friend class POVParser;  //可以允许POVParser这个类来调用私有方法，但不允许用户直接使用
	public:
		Object();
		~Object();
		bool importObject(std::string object_name);
		bool setLocation(Location _lc);
		bool setTexture();
		
	private:
		std::string object_name;

	//protected:  //后续要改为protected
	public:
		Location m_lc;
		bool parserPOV(std::string);
	};
}