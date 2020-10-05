#pragma once

#include "util.h"

namespace EasyGame {
	class Window;
	interface IRenderer {
	public:
		virtual void render(EasyGame::Window& window) = 0;
		virtual void init() = 0;
	};
}