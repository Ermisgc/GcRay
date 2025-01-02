#include <fstream>
#include <iostream>
#include "pov_parser.h"
#include "pov_model.h"

using namespace POV;
POVParser::POVParser(){

}
POVParser::~POVParser(){

}

bool POVParser::importObject(const std::string & object_name){
    POVModel* temp = new POVModel(object_name);
    objs.push_back(temp);
    return true;
}

bool POVParser::importObject(POVModel * pov_model){
    objs.push_back(pov_model);
    return true;
}

bool POVParser::setCamera(){
    return true;
}

bool POVParser::parserPOV() {
    std::ofstream outfile("test.pov", std::ios::out | std::ios::app);

    if (!outfile.is_open()) {
        std::cerr << "The outfile is not created or opened correctly" << std::endl;
        return false;
    }

    for(auto & ptr: objs){
        ptr->parserPOV(outfile);
    }

    // close fd
    outfile.close();
    return true;
}