#pragma once

#include "util.h"

namespace EasyGame {
	class Shader {
		DATAREADDEF(unsigned int, ID)
	public:
		Shader(ResourceLocation vertex, ResourceLocation fragment);
		void use();

		void set1f(const char* name, float x);
		void set2f(const char* name, float x, float y);
		void set3f(const char* name, float x, float y, float z);
		void set4f(const char* name, float x, float y, float z, float w);

		void set1b(const char* name, bool x);
		void set2b(const char* name, bool x, bool y);
		void set3b(const char* name, bool x, bool y, bool z);
		void set4b(const char* name, bool x, bool y, bool z, bool w);

		void set1i(const char* name, int x);
		void set2i(const char* name, int x, int y);
		void set3i(const char* name, int x, int y, int z);
		void set4i(const char* name, int x, int y, int z, int w);

		void set2fmat(const char* name, glm::mat2 mat);
		void set3fmat(const char* name, glm::mat3 mat);
		void set4fmat(const char* name, glm::mat4 mat);
	};
}