#pragma once

#include "Strife/Layer.h"
#include "C:\dev\Strife\Strife\vendor\imgui\imgui.h"

namespace Strife {

	class STRIFE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetatch() override;
		void OnUpdate() override;
		void OnEvent(Event& e) override;

		static ImGuiKey GlfwKeyToImGuiKey(int key);
		static int KeyToModifier(int keycode);
		static void SetModifier(int modifier, bool enabled);

		static void CopyToClipboard(void* user_data, const char* text);
		static const char* PasteFromClipboard(void* user_data);
	private:
		float m_Time = 0.0f;
	};
}
