#pragma once

#include "../render/IRenderer.h"

namespace EasyGame {
	class Window {
		std::vector<IRenderer*> renderers;
		DATAREADDEF(std::string, Title)
		DATAREADDEF(GLFWwindow*, WindowProc)
		DATAREADDEF(int, Width)
		DATAREADDEF(int, Length)
		DATAREADDEF(int, MajorVersion)
		DATAREADDEF(int, MinorVersion)
	public:
		template<typename Type> void addRenderer() {
			IRenderer* renderer = (IRenderer*)new Type;
			renderer->init();
			this->renderers.push_back(renderer);
		}
		void tick();
		Window(int width, int length, std::string title, int majorVersion, int minorVersion, GLFWframebuffersizefun callback);
		~Window();
	};
}