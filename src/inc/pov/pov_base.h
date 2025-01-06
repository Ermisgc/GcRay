#pragma once
#include <string>
namespace POV {
	struct Location
	{
		float x , y , z;
		Location() :x(0), y(0), z(0) {
		}
		Location(float _x, float _y, float _z) :x(_x), y(_y), z(_z) {};
	};

    struct EuleAngle{
        float roll, pitch, yaw;
    };
	
	//rgb color:0 ~ 255
	struct Color{
		u_int8_t r, g, b;
	};
}