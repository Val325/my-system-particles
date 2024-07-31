#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec3 transform;
layout (location = 3) in float SizeParticle;

out vec3 ourColor;
out float sizePartic;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;
uniform float time;
uniform float random;
uniform float deltaTime;

out VS_OUT {
    vec3 color;
} vs_out;

out VS_OUT_SIZE {
    float size;
} vs_out_size;

void main()
{
    gl_Position = projection * view * model * vec4(aPos.x * transform.x, aPos.y * transform.y, aPos.z * transform.z, 1.0);
    vs_out.color = aColor;
    vs_out_size.size = SizeParticle;
}
