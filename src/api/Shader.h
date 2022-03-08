//
// Created by katha on 07.03.22.
//

#ifndef WALL_E_SHADER_H
#define WALL_E_SHADER_H
#include <string>


class Shader {
// the program ID
    unsigned int ID;

    // constructor reads and builds the shader
    Shader(const char* vertexPath, const char* fragmentPath);
    // use/activate the shader
    void use();
    // utility uniform functions
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
};


#endif //WALL_E_SHADER_H
