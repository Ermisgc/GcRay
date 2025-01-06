#include <fstream>
#include <iostream>
#include "../inc/pov/pov_parser.h"
#include "../inc/pov/pov_model.h"
#include "../inc/pov/pov_camera.h"
#include "../inc/pov/pov_lightsource.h"
#include "../inc/pov/pov_background.h"

using namespace POV;
POVParser::POVParser(){

}
POVParser::~POVParser(){
    for(auto & ptr: objs) delete ptr;
}

bool POVParser::importObject(const std::string & object_name){
    POVModel* temp = new POVModel(object_name);
    objs.push_back(temp);
    return true;
}

bool POVParser::importObject(POVModel * pov_model){
    if(!pov_model) return false;
    objs.push_back(pov_model);
    return true;
}

bool POVParser::setCamera(POVCamera* camera){
    if(!camera) return false;
    objs.push_front(camera);
    return true;
}

bool POVParser::setLightSource(POVLightSource * lightsource){
    if(!lightsource) return false;
    objs.push_front(lightsource);
    return true;
}

bool POVParser::parserPOV(const std::string & _file_name) {
    if(_file_name.substr(_file_name.find('.') + 1, 3) != "pov"){
        std::cout << "the file name should be .pov" << std::endl;
        return false;
    } 
    std::ofstream outfile(_file_name, std::ios::out);

    if (!outfile.is_open()) {
        std::cerr << "The outfile is not created or opened correctly" << std::endl;
        return false;
    }

    outfile << "#local Temp_version = version;\n";
    outfile << "#version 3.7;\n";
    outfile << "global_settings {\n";
    outfile << "    max_trace_level 15\n";
    outfile << "    adc_bailout 0.001\n";
    outfile << "    assumed_gamma 1\n";
    outfile << "}\n";
    for(auto & ptr: objs){
        ptr->parserPOV(outfile);
    }
    outfile << "#version Temp_version;\n";
    // close fd
    outfile.close();
    return true;
}

bool POVParser::setbackground(POVBackGround * bg){
    if(!bg) return false;
    objs.push_front(bg);
    return true;
}

bool POVParser::addObject(POVObject * obj){
    if(!obj) return false;
    this->objs.push_back(obj);
    return true;
}