#include "pov_object.h"

namespace POV{
    class POVBackGround: public POVObject{
        Color color;
    public:
        POVBackGround();
        ~POVBackGround();
        bool setBackGroundColor(const Color & );
        bool parserPOV(std::ofstream & os);
    };
}