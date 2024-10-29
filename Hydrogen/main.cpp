#include <iostream>
#include <string>

#include "toolbox_proto.hpp"
#include "Core.hpp"

int main(int argc, char** argv) {
	Core::init();
		
	while (Core::windowIsOpen()) {
		Core::init();
		Core::update();

		Core::beginRendering();
		Core::render();
		Core::endRendering();

		Core::changeState();
	}
}
