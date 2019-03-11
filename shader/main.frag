#version 130

uniform vec2 iResolution;

void main()
{
    float u = gl_FragCoord.x / iResolution.x;
    float v = gl_FragCoord.y / iResolution.y;
    gl_FragColor = vec4(u, v, 1.0, 1.0);
}
