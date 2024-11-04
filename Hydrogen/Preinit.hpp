/// -------------------------------------------------------- ///
///        == Hydrogen == Prototype C++ State Machine		 ///
///   (C) 2024 J.Sebastien Toussaint - All Rights Reserved	 ///
/// -------------------------------------------------------- ///
///                  == FILE DESCRIPTION ==					 ///
///  Handles Core resource preinitialization phase, serving	 ///
///  as an entry point to register new gamestates and add	 ///
///  new keyboard keybinds.									 ///
/// -------------------------------------------------------- ///

#pragma once

class Core;
namespace ctrl { class Keyboard; }

/// Misc preinitialization operations
void preinit(Core& _core);

/// Registers keybinds
void registerControls(Core& _core);