#pragma once

#include "Parallax/Renderer/Buffer.h"
#include "Parallax/Renderer/VertexArray.h"

namespace Parallax {

    class OpenGLVertexArray : public VertexArray
    {
    private:
        u_int32_t m_RendererID;
        std::vector<Ref<VertexBuffer>> m_VertexBuffers;
        Ref<IndexBuffer> m_IndexBuffer;
    public:
        OpenGLVertexArray();
        virtual ~OpenGLVertexArray();

        virtual void Bind() const override;
        virtual void Unbind() const override;

        virtual void AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer) override;
    	virtual void SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer) override;
        
        virtual const std::vector<Ref<VertexBuffer>>& GetVertexBuffers() const override { return m_VertexBuffers; }
        virtual const Ref<IndexBuffer>& GetIndexBuffer() const override { return m_IndexBuffer; }
    };
}