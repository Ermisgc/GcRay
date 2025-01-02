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
}