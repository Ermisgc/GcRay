#include "pov_object.h"

namespace POV{
    enum class CameraType{
        PERSPECTIVE,
    };

    class POVCamera : public POVObject{
        float m_focal;
        EuleAngle ea;
    public:
        POVCamera();
        POVCamera(const POVCamera & );
        ~POVCamera();
    
        // bool setCameraType(CameraType);
        // bool setLocation(Location);
        // bool setLookAt(Location);
        // bool setFocal(float focal);
        bool setEuleAngle(const EuleAngle &);

    protected:
        bool parserPOV(std::ofstream & os);
    };
}