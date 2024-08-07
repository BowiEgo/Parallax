#version 450

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec4 a_Color;
layout(location = 2) in vec2 a_TexCoord;
layout(location = 3) in int a_EntityID;

layout(std140, binding = 0) uniform Camera
{
    mat4 u_ProjectionMatrix;
    mat4 u_ViewMatrix;
};

struct VertexOutput
{
    vec4 Color;
    vec2 TexCoord;
};

layout(location = 0) out VertexOutput Output;
layout(location = 3) out flat int v_EntityID;

void main()
{
    Output.Color = a_Color;
    Output.TexCoord = a_TexCoord;
    v_EntityID = a_EntityID;
    gl_Position = u_ProjectionMatrix * u_ViewMatrix * vec4(a_Position, 1.0);
}