#include "pov_object.h"
namespace POV{
	class Box: public POVObject{
		Location corner1;
		Location corner2;
		float ior;
	public:
		Box() = delete;
		Box(const Box &);
		Box(Location _1, Location _2, float _ior);
		~Box();
		
		bool setCorners(Location _1, Location _2);
		bool setIOR(float);
		bool parserPOV(std::ofstream & os);
	};
}