#pragma once

#include "MyEngine/Core.h"
#include "MyEngine/Events/Event.h"

namespace MyEngine{

	// intended to be subclassed by each different layer
	class MyEngine_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttack() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;
	};
}


