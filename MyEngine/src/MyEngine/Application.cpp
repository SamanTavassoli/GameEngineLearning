#include "mepch.h"
#include "Application.h"

#include "MyEngine/Log.h"

#include <GLFW/glfw3.h>

namespace MyEngine {

	// we give the callback function, a reference to the application and a placeholder
	// when the callback is called, a reference to the application is automatically passed
	// in along with an expected event in the placeholder
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));


		ME_CORE_TRACE("{0}", e);
	}

	void Application::Run()
	{
		while (m_Running)
		{

			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}