#version 330 core

// outputs
out vec4 GLOBAL_fragment_color;

// shader entry point
void main() {
    // setup fragment color
    GLOBAL_fragment_color = vec4(1.0, 0.0, 0.0, 1.0);
    if (GLOBAL_fragment_color.a < 1.0f) {
        discard;
    }

    return;
}
