#pragma once

namespace engine {

	void PrintVersion();

	void InitializeEngine(int initialWindowWidth, int initialWindowHeight, void (*delegateMainLoop)(), void (*delegateKeyPressed)(int key));

	void InitializeMainLoop();

	void ResizeWindow(int newWidth, int newHeight);

}
