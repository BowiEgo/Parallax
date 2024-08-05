#pragma once

#include "czpch.h"

#include "EditorCamera.h"
#include "RenderCommand.h"
#include "OrthographicCamera.h"
#include "Shader.h"
#include "Texture.h"
#include "Mesh.h"

#include "Chozo/Scene/Components.h"

namespace Chozo {

    class Renderer
    {
    public:
        struct RenderCamera
        {
            glm::mat4 PrjectionMatrix;
            glm::mat4 ViewMatrix;
        };

        static void Init();
        static void Shutdown();
        
        static void BeginScene(const glm::mat4& projection, const glm::mat4& transform);
        static void BeginScene(EditorCamera& camera); // TODO: Remove
        static void EndScene();

        static void BeginBatch();
        static void NextBatch();
        static void Flush();

        // Primitives
        static void DrawMesh(const glm::mat4 transform, Mesh& mesh, uint32_t entityID = -1);

        inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

        // Stats
        struct Statistics
        {
            uint32_t DrawCalls = 0;
            uint32_t triangleCount = 0;

            // uint32_t GetTotalVertexCount() { return QuadCount * 4; }
            // uint32_t GetTotalIndexCount() { return QuadCount * 6; }
        };

        static Statistics GetStats();
        static void ResetStats();
    private:
        static void FlushAndReset();
    private:
        struct SceneData
        {
            glm::mat4 ViewProjectionMatrix;
            Ref<Shader> Shader;
        };

        static SceneData* m_SceneData;
    };
}