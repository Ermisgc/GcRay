#include <iostream>
#include "pov_object.h"

using namespace POV;

int main() {
	POV::Object obj;
	obj.importObject("test_object");
	obj.parserPOV("test.pov");
	return 0;
}