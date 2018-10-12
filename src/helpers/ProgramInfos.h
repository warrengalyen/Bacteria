#ifndef PROGRAMUTILITIES_H
#define PROGRAMUTILITIES_H

#include <gl3w/gl3w.h>
#include <string>
#include <map>
#include <vector>
#include <glm/glm.hpp>

class ProgramInfos
{
public:

	ProgramInfos();

	ProgramInfos(const std::string & vertextName, const std::string & fragmentName);

	~ProgramInfos();

	const GLint uniform(const std::string & name) const;

	// Version that caches the values passed for the uniform array. Other types will be added when needed.
	void cacheUniformArray(const std::string & name, const std::vector<glm::vec3> & vals);

	void registerTexture(const std::string & name, int slot);

	void reload();

	// To stray coherent with TextureInfos and MeshInfos, we need the id public.
	const GLuint id() const { return _id; }
	
private:

	GLuint _id;
	std::string _vertexName;
	std::string _fragmentName;
	std::map<std::string, GLint> _uniforms;
	std::map<std::string, int> _textures;
	std::map<std::string, glm::vec3> _vec3s;
	
};

#endif
