#include "Chozo.h"

namespace Chozo {

    class CameraController : public ScriptableEntity
    {
    public:
        void OnCreate()
        {
            // auto& translation = GetCompoent<TransformComponent>().Translation;
            // translation.x = rand() % 10 - 5.0f;
        }

        void OnDestroy()
        {
            CZ_TRACE("CameraController Destroyed!");
        }

        void OnUpdate(Timestep ts)
        {
            auto& camera = GetCompoent<CameraComponent>();
            if (!camera.Primary || !m_IsActive) return;

            auto& translation = GetCompoent<TransformComponent>().Translation;

            if (Input::IsKeyPressed(CZ_KEY_A))
                translation.x -= m_CameraMoveSpeed * ts;
            if (Input::IsKeyPressed(CZ_KEY_D))
                translation.x += m_CameraMoveSpeed * ts;
            if (Input::IsKeyPressed(CZ_KEY_W))
                translation.y += m_CameraMoveSpeed * ts;
            if (Input::IsKeyPressed(CZ_KEY_S))
                translation.y -= m_CameraMoveSpeed * ts;
        }

        void SetActive(bool active) { m_IsActive = active; }

        bool OnEvent(Event& e) {
            EventDispatcher dispatcher(e);
            dispatcher.Dispatch<MouseScrolledEvent>([this](MouseScrolledEvent& e) { return OnMouseScroll(e); });

            return true;
        };
    private:
        bool OnMouseScroll(MouseScrolledEvent &e)
        {
            // m_ZoomLevel -= e.GetYOffset() * 0.25f;
            // m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);

            // m_Camera.Zoom(m_ZoomLevel);
            return true;
        }
    private:
        bool m_IsActive = true;

        // OrthographicCamera m_Camera;
        glm::vec3 m_CameraPosition;
        float m_CameraRotation;

        float m_CameraMoveSpeed = 5.0f;
        float m_CameraRotationSpeed = 180.0f;
        float m_ZoomLevel = 1.0f;
        float m_LastScroll = 0.0f;
    };
}
