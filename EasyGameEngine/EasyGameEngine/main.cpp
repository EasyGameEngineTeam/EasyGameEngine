#include "Window.h"

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

class Example1 : EasyGame::IRenderer {
public:
	virtual void render(EasyGame::Window& window) override final {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	virtual void init() override final {
	}
};

int main() {
	EasyGame::Window window(200, 200, "test", 3, 3, framebufferSizeCallback);

	window.addRenderer<Example1>();

	while (! glfwWindowShouldClose(window.getWindowProc())) {
		window.tick();
	}
	return 0;
}