#include "pov_object.h"
#include <fstream>

using namespace POV;
Object::Object():m_lc(0, 0, 0) {
}

Object::~Object() {
}

bool Object::importObject(std::string object_name) {
    this->object_name = object_name;
    return true;
}
bool Object::setLocation(Location _lc) {
	m_lc = _lc;
    return true;
}

bool Object::setTexture() {
    return true;
}

bool Object::parserPOV(std::string save_path) {
    std::ofstream outfile(save_path, std::ios::out | std::ios::app);

    if (!outfile.is_open()) {
        std::cerr << "无法打开文件" << std::endl;
        return false;
    }

    // Append object information
    std::string data[] = { "object{\n", "\t" + object_name + "\n",  "\ttexture {\n", "\t\tpigment {\n", "\t\t\tchecker color rgb <1, 1, 1> color rgb <0, 0, 0>\n", "\t\t}\n", "\t}\n", "}\n"};
    // 追加数据到文件
    for (const auto& line : data) {
        std::cout << line << std::endl;
        outfile << line;
    }

    // 关闭文件
    outfile.close();
    return true;
}