object{
	test_object
	texture {
		pigment {
			checker color rgb <1, 1, 1> color rgb <0, 0, 0>
		}
	}
}
#declare  = texture{    pigment{        image_map {png ""}    }}#include "falanguanban3_POV_geom.inc" //Geometry//Backgroundbackground { color srgb <0,1,0.5>  }//Assembled object that is contained in falanguanban3_POV_geom.inc with no SSLT componentsobject{      falanguanban3_       texture{                          }    }