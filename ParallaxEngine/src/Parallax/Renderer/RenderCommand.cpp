#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Parallax {

    RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}