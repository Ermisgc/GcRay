#include "pov_object.h"

namespace POV{
    enum class CameraType{
        PERSPECTIVE,
    };

    class POVCamera : public POVObject{
        float m_focal;
        // EuleAngle ea;
        Location _loc;
        Location _look_at;
    public:
        POVCamera();
        POVCamera(const Location & loc, const Location & la);
        POVCamera(const POVCamera & );
        ~POVCamera();
        // bool setEuleAngle(const EuleAngle &);  //about some intrinsic properties
        bool setLocation(const Location & loc);
        bool setLookAt(const Location & loc);

    protected:
        bool parserPOV(std::ofstream & os);
    };
}