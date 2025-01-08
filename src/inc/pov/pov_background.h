#include "pov_object.h"

namespace POV{
    class POVBackGround: public POVObject{
        Color color;
    public:
        POVBackGround() = delete;
        POVBackGround(const Color &&);
        POVBackGround(const POVBackGround &);
        ~POVBackGround();
        bool setBackGroundColor(const Color & );
        bool parserPOV(std::ofstream & os);
    };
}