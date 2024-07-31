#version 330 core
in vec3 ourColor;
out vec4 FragColor;

uniform float time;
uniform float random;
uniform vec4 color;

in vec3 fColor;

void main()
{
    FragColor = vec4(fColor, 1.0);
}  
