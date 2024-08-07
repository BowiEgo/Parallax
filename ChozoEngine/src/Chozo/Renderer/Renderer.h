#pragma once

#include "czpch.h"

#include "EditorCamera.h"
#include "RenderCommand.h"
#include "OrthographicCamera.h"
#include "Shader.h"
#include "Texture.h"
#include "Mesh.h"
#include "UniformBuffer.h"

#include "Batch.h"

#include "Chozo/Scene/Components.h"

namespace Chozo {

    class Renderer
    {
    public:

        struct Statistics
        {
            uint32_t DrawCalls = 0;
            uint32_t VerticesCount = 0;
            uint32_t TriangleCount = 0;

            uint32_t GetTotalVerticesCount() { return VerticesCount; }
            uint32_t GetTotalTrianglesCount() { return TriangleCount; }
        };

        static Statistics GetStats();
        static void ResetStats();

        struct RenderCamera
        {
            glm::mat4 PrjectionMatrix;
            glm::mat4 ViewMatrix;
        };

        struct RendererData
        {
            uint32_t IndexCount = 0;
            BatchManager BatchManager;

            Ref<Shader> Shader;
            int MaxTextureSlots = 0;
            uint32_t TextureSlotIndex = 1; // 0 = white texture
            std::vector<Ref<Texture2D>> TextureSlots;
            Ref<Texture2D> WhiteTexture;

            struct CameraData
            {
                glm::mat4 ProjectionMatrix;
                glm::mat4 ViewMatrix;
            };
            CameraData CameraBuffer;
            Ref<UniformBuffer> CameraUniformBuffer;

            Renderer::Statistics Stats;

            uint32_t GetMaxTriangles() { return GetMaxCount<Index>(); }
        };

        static void Init();
        static void Shutdown();
        
        static void BeginScene(const glm::mat4& projection, const glm::mat4& transform);
        static void BeginScene(EditorCamera& camera); // TODO: Remove
        static void EndScene();

        static void RenderBatches();

        // Primitives
        static bool SubmitMesh(StaticMesh* mesh);
        static void DrawMesh(const glm::mat4 transform, Ref<MeshSource> meshSource, uint32_t entityID = -1);

        inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

        static RendererData GetRendererData();
        static void UpdateMaxTriagles(uint32_t count);
    private:
        struct SceneData
        {
            glm::mat4 ViewProjectionMatrix;
            Ref<Shader> Shader;
        };

        static SceneData* m_SceneData;
    };
}