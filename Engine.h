#pragma once
#include "common.h"
#include <memory>

#include "Window.h"

using WindowPtr = std::unique_ptr<Window>;

class Engine
{
private:
	WindowPtr window;
	int exit;
public:
	Engine();
	~Engine();
	int exitCode();

	void load();
	void start();
};

