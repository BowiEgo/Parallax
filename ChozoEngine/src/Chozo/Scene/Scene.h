#pragma once

#include "czpch.h"

#include "entt.hpp"

#include "Chozo/Core/UUID.h"
#include "Chozo/Core/Timestep.h"
#include "Chozo/Renderer/EditorCamera.h"

namespace Chozo {

    class Entity;

    class Scene
    {
    public:
        Scene();
        ~Scene();

        Entity CreateEntity(const std::string& name = std::string());
        Entity CreateEntityWithUUID(UUID uuid, const std::string& name = std::string());
        void DestroyEntity(Entity entity);

        // TEMP
        entt::registry& Reg() { return m_Registry; }

        void OnUpdateEditor(Timestep ts, EditorCamera& camera);
        void OnUpdateRuntime(Timestep ts);
        void OnViewportResize(uint32_t width, uint32_t height);

        Entity GetPrimaryCameraEntity();
    private:
        template<typename T>
        void OnComponentAdded(Entity entity, T& component);
    public:
        entt::registry m_Registry;

        friend class Entity;
        friend class SceneSerializer;
        friend class SceneHierarchyPanel;
    private:
        uint32_t m_ViewportWidth = 0, m_ViewportHeight = 0;
    };
}
