#include "mepch.h"
#include <MyEngine.h>

class Sandbox : public MyEngine::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

// the application simply includes the engine and creates this function and that is all it worries about
// the entry point to the application is handled by the engine itself
MyEngine::Application* MyEngine::CreateApplication()
{
	return new Sandbox();
}