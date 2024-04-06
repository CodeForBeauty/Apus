#version 330 core

layout(location = 0) in vec4 _position;
layout(location = 1) in vec2 _uv;
layout(location = 1) in vec4 _color;


out vec2 uv;
out vec4 color;


void main()
{
    uv = _uv;
    color = _color;
    gl_Position = _position;
}