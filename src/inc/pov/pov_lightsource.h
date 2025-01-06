#include "pov_object.h"

namespace POV{
    class POVLightSource: public POVObject{
        EuleAngle ea;
    public:
        POVLightSource();
        ~POVLightSource();
        bool setLightSource(const EuleAngle &);
        bool setLightSource(float r, float p, float y);
        bool parserPOV(std::ofstream & os);    
    };
}