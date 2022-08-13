#pragma once

#include "Strife/Layer.h"
#include "C:\dev\Strife\Strife\vendor\imgui\imgui.h"

namespace Strife {

	class STRIFE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void BeginFrame();
		void EndFrame();
	private:
		float m_Time = 0.0f;
	};
}
