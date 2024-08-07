#pragma once

#include "Chozo/Renderer/RendererTypes.h"
#include "Chozo/Renderer/Texture.h"

namespace Chozo {
    
    class OpenGLTexture2D : public Texture2D
    {
    public:
        OpenGLTexture2D(const Texture2DSpecification& spec);
        OpenGLTexture2D(const std::string& path, const Texture2DSpecification& spec);
        virtual ~OpenGLTexture2D();

        virtual uint32_t GetWidth() const override { return m_Width; };
        virtual uint32_t GetHeight() const override { return m_Height; };
		virtual RendererID GetRendererID() const override { return m_RendererID; };

        virtual void Bind(uint32_t slot = 0) const override;

        virtual void SetData(const void* data, const uint32_t size) override;
    private:
        Texture2DSpecification m_Spec;
        std::string m_Path;
        uint32_t m_Width, m_Height;
        RendererID m_RendererID;
    };

}