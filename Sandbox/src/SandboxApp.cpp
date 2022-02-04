#include <HEngine.h>

class ExampleLayer : public HEngine::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override
	{
		if (HEngine::Input::IsKeyPressed(HE_KEY_TAB))
		{
			HE_TRACE("Tab Key is Pressed!(poll)");
		}
	}

	void OnEvent(HEngine::Event& event) override
	{
		if (event.GetEventType() == HEngine::EventType::KeyPressed)
		{
			HEngine::KeyPressedEvent& e = (HEngine::KeyPressedEvent&)event;

			if (e.GetKeyCode() == HE_KEY_TAB)
			{
				HE_TRACE("Tab Key is Pressed!(event)");
			}
			HE_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public HEngine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new HEngine::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

HEngine::Application* HEngine::CreateApplication()
{
	return new Sandbox();
}