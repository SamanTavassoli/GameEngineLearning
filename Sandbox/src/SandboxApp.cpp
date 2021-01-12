#include <MyEngine.h>

class ExampleLayer : public MyEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		ME_INFO("ExampleLayer::Update");
	}

	void OnEvent(MyEngine::Event& event) override
	{
		ME_TRACE("{0}", event);
	}

};

class Sandbox : public MyEngine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
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