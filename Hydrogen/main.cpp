#include <iostream>
#include <string>

#include "toolbox_proto.hpp"
#include "Core.hpp"

int main(int argc, char** argv) {
	Core core;
		
	while (core.windowIsOpen()) {
		core.init();
		core.update();

		core.beginRendering();
		core.render();
		core.endRendering();

		core.changeState();
	}
}
