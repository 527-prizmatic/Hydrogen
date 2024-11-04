#pragma once

class Core;
namespace ctrl { class Keyboard; }

/// Misc preinitialization operations
void preinit(Core& _core);

/// Registers keybinds
void registerControls(Core& _core);