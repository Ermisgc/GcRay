#include "pov_object.h"
namespace POV{
    class Sphere : public POVObject{
        float radius;
        Location _loc;
        std::string m_texture;
    public:
        Sphere() = delete;
        Sphere(float _, const Location & _l);
        Sphere(const Sphere& other);

        bool setRadius(float);
        bool setLocation(const Location & _l);
        bool setTexture(std::string _name);
        bool parserPOV(std::ostream & os);
    };
}