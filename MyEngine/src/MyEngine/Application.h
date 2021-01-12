#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "MyEngine/Events/ApplicationEvent.h"

#include "Window.h"

namespace MyEngine {

	
	class MyEngine_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window; // unique because window only exists in application scope
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

