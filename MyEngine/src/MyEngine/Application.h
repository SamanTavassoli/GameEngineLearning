#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace MyEngine {

	
	class MyEngine_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window; // unique because window only exists in application scope
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

