#version 330 core

in vec2 uv;
in vec4 color;


out vec4 fragColor;


void main() 
{
    fragColor =  vec4(uv.x, uv.y, 0.0f, 1.0f);
}