// ModelVisor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Engine.h"

#include <iostream>
#include <string>
#include <filesystem>
#include <sstream>

void LoopOpenGL()
{
	//std::cout << "LOOP" << std::endl;
}


void KeyPressedOpenGL(int key)
{
	std::cout << key << std::endl;
	if (key == 32)
	{
		engine::ResizeWindow(320, 200);
	}
}


int main()
{


	void (*delegateMainLoopfunc)() = LoopOpenGL;
	void (*delegateKeypressedfunc)(int key) = KeyPressedOpenGL;
	engine::PrintVersion();
	engine::InitializeEngine(800,600, delegateMainLoopfunc, delegateKeypressedfunc);
}
