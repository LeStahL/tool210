#version 130

uniform sampler2D iData;
uniform vec2 iResolution;

void main()
{
    float u = gl_FragCoord.x / iResolution.x;
    float v = gl_FragCoord.y / iResolution.y;
    gl_FragColor = texture(iData, vec2(u, v));
}
