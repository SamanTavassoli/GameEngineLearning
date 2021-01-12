#pragma once

#include "Core.h"

#include "Window.h"
#include "MyEngine/LayerStack.h"
#include "MyEngine/Events/Event.h"
#include "MyEngine/Events/ApplicationEvent.h"

namespace MyEngine {

	
	class MyEngine_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window; // unique because window only exists in application scope
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

