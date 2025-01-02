#include <iostream>
#include "pov_parser.h"

using namespace POV;

int main() {
	POV::POVParser obj;
	obj.importObject("test.model");
	obj.parserPOV();
	return 0;
}