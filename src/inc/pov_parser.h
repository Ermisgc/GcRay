#include "pov_object.h"
#include <list>

namespace POV
{
    class POVObject;
    class POVParser{
        std::list<POVObject *> objs; 
    public:
        //Construction and destruction
        POVParser();
        ~POVParser();

        //import a model generated by poseRay
        //this function will auto include the .inc file of generated model
        //when not finding the suitable file, return false
        bool importObject(const std::string & object_name);

        bool importObject(POVModel * pov_model);

        bool setCamera();

        //parser the scene to a .pov file
        bool parserPOV();

    };
} // namespace POV