#pragma once

#include "common.h"

class Engine;

class Window
{
private:
	GLFWwindow* ref;
	const char* title;
	int width;
	int height;

	friend class Engine;
public:
	Window(const char* title, int width, int height);
	~Window();

	bool isValid();

	void start();

	bool shouldClose();
	void processInput();
};

