#include "EGWindow.h"

namespace EasyGame {
	DATAREAD(std::string, Title, Window)
	DATAREAD(GLFWwindow*, WindowProc, Window)
	DATAREAD(int, Width, Window)
	DATAREAD(int, Length, Window)
	DATAREAD(int, MajorVersion, Window)
	DATAREAD(int, MinorVersion, Window)

	void Window::tick(){
		for (IRenderer* renderer : renderers) {
			renderer->render(*this);
		}
		glfwPollEvents();
		glfwSwapBuffers(WindowProc);
	}

	Window::Window(int width, int length, std::string title, int majorVersion, int minorVersion, GLFWframebuffersizefun callback) {
		this->Width = width;
		this->Length = length;
		this->Title = title;
		this->MajorVersion = majorVersion;
		this->MinorVersion = minorVersion;

		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, this->MajorVersion);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, this->MinorVersion);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

		this->WindowProc = glfwCreateWindow(this->Width, this->Length, this->Title.c_str(), NULL, NULL);

		if (this->WindowProc == NULL) {
			MessageBox(NULL, TEXT("Can't create glfw window!"), TEXT("Fatal Errors!"), NULL);
			glfwTerminate();
			exit(-1);
		}

		glfwMakeContextCurrent(this->WindowProc);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			MessageBox(NULL, TEXT("Can't init glad"), TEXT("Fatal Errors!"), NULL);
			exit(-1);
		}

		glViewport(0, 0, this->Width, this->Length);
		glfwSetFramebufferSizeCallback(this->WindowProc, callback);
	}

	Window::~Window() {
		glfwTerminate();
		for (IRenderer* renderer : renderers) {
			delete renderer;
		}
	}
}