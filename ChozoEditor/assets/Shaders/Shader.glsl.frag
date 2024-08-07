#version 450

layout(location = 0) out vec4 o_Color;
layout(location = 1) out int o_EntityID;

layout(location = 0) in vec3 v_Normal;
layout(location = 1) in vec2 v_TexCoord;
layout(location = 2) in flat int v_EntityID;

// layout(push_constant) uniform PushConstants
// {
//     vec4 u_Color;
// } pushConstants;
// uniform vec4 u_Color;

void main()
{
    // vec4 texColor = pushConstants.u_Color;
    

    o_Color = vec4(1.0, 0.5, 0.2, 1.0);
    o_EntityID = v_EntityID;
}