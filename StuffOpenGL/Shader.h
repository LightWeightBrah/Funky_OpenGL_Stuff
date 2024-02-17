#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h> //include glad to get all the required opengl headers
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	unsigned int ID; //program ID

	Shader(const char* vertexPath, const char* fragmentPath);

	void Use();
	void Delete();

	void SetBool(const std::string& name, bool value) const;
	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;
	void SetMat4(const std::string& name, const glm::mat4& mat) const;
	void SetVec3(const std::string& name, const glm::vec3& vec) const;

};

#endif