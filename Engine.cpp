#include "Engine.h"

Engine::Engine() : exit(0)
{
	glfwInit();

	// set the OpenGL 3.3 core profile
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	log(info) << "using OpenGL 3.3 core";

#if __APPLE__
	log(debug) << "macos detected using GLFW_OPENGL_FORWARD_COMPAT"
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#else
	log(debug) << "not a macos device";
#endif
}

Engine::~Engine()
{
	window.reset();

	glfwTerminate();
}

int Engine::exitCode()
{
	return exit;
}

void Engine::load()
{
	// create a window, exit if failed
	window = std::make_unique<Window>("TITLE", 800, 600);
	if (!window->isValid()) {
		log(error) << "Failed to create GLFW window";
		glfwTerminate();
		exit = -1;
		return;
	}
	glfwMakeContextCurrent(window->ref);

	// init GLAD, exit if failed
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		log(error) << "Failed to initialize GLAD";
		exit = -1;
		return;
	}
}

void Engine::start()
{
	window->start();

	while (!window->shouldClose()) {
		window->processInput();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window->ref);
		glfwPollEvents();
	}

	window.reset();
}
