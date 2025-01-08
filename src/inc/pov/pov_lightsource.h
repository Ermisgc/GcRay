#include "pov_object.h"

namespace POV{
    class POVLightSource: public POVObject{
        Location _loc;
    public:
        POVLightSource() = delete;
        POVLightSource(const POVLightSource &);
        POVLightSource(Location && loc);
        POVLightSource(Location & loc);
        ~POVLightSource();
        bool setLightSource(const Location &);
        bool setLightSource(float r, float p, float y);
        bool parserPOV(std::ofstream & os);    
    };
}