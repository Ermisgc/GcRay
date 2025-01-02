#pragma once
#include <iostream>
#include <string>
#include "pov_base.h"

namespace POV {
	class Object {
		friend class POVParser;  //��������POVParser�����������˽�з��������������û�ֱ��ʹ��
	public:
		Object();
		~Object();
		bool importObject(std::string object_name);
		bool setLocation(Location _lc);
		bool setTexture();
		
	private:
		std::string object_name;

	//protected:  //����Ҫ��Ϊprotected
	public:
		Location m_lc;
		bool parserPOV(std::string);
	};
}