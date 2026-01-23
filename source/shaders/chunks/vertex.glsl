#version 330 core

// inputs
layout (location = 0) in vec3 GLOBAL_coordinates;

// shader entry point
void main() {
    // setup position
    gl_Position = vec4(GLOBAL_coordinates, 1.0f);

    return;
}
