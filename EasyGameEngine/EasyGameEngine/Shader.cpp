#include "Shader.h"

namespace EasyGame {
	DATAREAD(unsigned int, ID, Shader)

	Shader::Shader(ResourceLocation vertex, ResourceLocation fragment) {
		std::string vertexC, fragmentC;
		std::ifstream source;
		std::stringstream buffer;
		source.exceptions(std::ifstream::badbit | std::ifstream::failbit);
		try {
			source.open(vertex.toPath().c_str());
			buffer << source.rdbuf();
			vertexC = buffer.str();
			buffer.clear();
			source.close();

			source.open(fragment.toPath().c_str());
			buffer << source.rdbuf();
			fragmentC = buffer.str();
			source.close();
		}
		catch (std::ifstream::failure exc) {
			MessageBox(NULL, (LPCWSTR)exc.what(), L"Error!", NULL);
		}

		unsigned vid = glCreateShader(GL_VERTEX_SHADER), fid = glCreateShader(GL_FRAGMENT_SHADER);
		int state;
		char log[8192];

		const char *vertexCode = vertexC.c_str(), *fragmentCode = fragmentC.c_str();

		glShaderSource(vid, 1, &vertexCode, NULL);
		glCompileShader(vid);
		glGetShaderiv(vid, GL_COMPILE_STATUS, &state);
		if (! state) {
			glGetShaderInfoLog(vid, 512, NULL, log);
			MessageBox(NULL, (LPCWSTR)log, L"Vertex Shader Compile Error!", NULL);
		}

		glShaderSource(fid, 1, &fragmentCode, NULL);
		glCompileShader(fid);
		glGetShaderiv(fid, GL_COMPILE_STATUS, &state);
		if (! state) {
			glGetShaderInfoLog(fid, 512, NULL, log);
			MessageBox(NULL, (LPCWSTR)log, L"Fragment Shader Compile Error!", NULL);
		}

		this -> ID = glCreateProgram();
		glAttachShader(ID, vid);
		glAttachShader(ID, fid);
		glLinkProgram(ID);

		glGetProgramiv(ID, GL_LINK_STATUS, &state);
		if (! state) {
			glGetProgramInfoLog(ID, 512, NULL, log);
			MessageBox(NULL, (LPCWSTR)log, L"Shader Program Linked Error!", NULL);
		}

		glDeleteShader(vid);
		glDeleteShader(fid);
	}

	void Shader::use() {
		glUseProgram(ID);
	}

	void Shader::set1f(const char* name, float x) {
		glUniform1f(glGetUniformLocation(ID, name), x);
	}

	void Shader::set2f(const char* name, float x, float y) {
		glUniform2f(glGetUniformLocation(ID, name), x, y);
	}

	void Shader::set3f(const char* name, float x, float y, float z) {
		glUniform3f(glGetUniformLocation(ID, name), x, y, z);
	}

	void Shader::set4f(const char* name, float x, float y, float z, float w) {
		glUniform4f(glGetUniformLocation(ID, name), x, y, z, w);
	}

	void Shader::set1b(const char* name, bool x) {
		glUniform1i(glGetUniformLocation(ID, name), x);
	}

	void Shader::set2b(const char* name, bool x, bool y) {
		glUniform2i(glGetUniformLocation(ID, name), x, y);
	}

	void Shader::set3b(const char* name, bool x, bool y, bool z) {
		glUniform3i(glGetUniformLocation(ID, name), x, y, z);
	}

	void Shader::set4b(const char* name, bool x, bool y, bool z, bool w) {
		glUniform4i(glGetUniformLocation(ID, name), x, y, z, w);
	}

	void Shader::set1i(const char* name, int x) {
		glUniform1i(glGetUniformLocation(ID, name), x);
	}

	void Shader::set2i(const char* name, int x, int y) {
		glUniform2i(glGetUniformLocation(ID, name), x, y);
	}

	void Shader::set3i(const char* name, int x, int y, int z) {
		glUniform3i(glGetUniformLocation(ID, name), x, y, z);
	}

	void Shader::set4i(const char* name, int x, int y, int z, int w) {
		glUniform4i(glGetUniformLocation(ID, name), x, y, z, w);
	}

	void Shader::set2fmat(const char* name, glm::mat2 mat) {
		glUniformMatrix2fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(mat));
	}

	void Shader::set3fmat(const char* name, glm::mat3 mat) {
		glUniformMatrix3fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(mat));
	}

	void Shader::set4fmat(const char* name, glm::mat4 mat) {
		glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(mat));
	}
}