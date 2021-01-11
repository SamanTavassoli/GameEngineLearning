#include "Application.h"

#include "MyEngine/Events/ApplicationEvent.h"
#include "MyEngine/Log.h"

namespace MyEngine {
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		ME_TRACE(e);

		while (true);
	}
}