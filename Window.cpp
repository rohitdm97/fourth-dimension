#include "Window.h"

void framebuffer_size_callback(GLFWwindow* ref, int width, int height) {
	glViewport(0, 0, width, height);
}

Window::Window(const char* title, int width, int height) :
	title(title),
	width(width),
	height(height)
{
	ref = glfwCreateWindow(width, height, title, NULL, NULL);
}

Window::~Window()
{
	if (ref != NULL) {
		glfwDestroyWindow(ref);
	}
}

bool Window::isValid()
{
	return ref != NULL;
}

void Window::start()
{
	// instance = this;

	// glfwSetFramebufferSizeCallback(ref, framebuffer_size_callback);
	glViewport(0, 0, width, height);

	// ...



}

bool Window::shouldClose()
{
	return glfwWindowShouldClose(ref);
}

void Window::processInput()
{
	if (glfwGetKey(ref, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(ref, true);
	}
}
