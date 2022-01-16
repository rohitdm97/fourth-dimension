#include "common.h"

#include "Engine.h"


int main() {
	Engine engine;
	engine.load();
	engine.start();
	int exit = engine.exitCode();
	return exit;
}
