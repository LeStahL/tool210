#version 130

uniform sampler1D iData;
uniform vec2 iResolution;

vec2 f(vec2 pos)
{
    float r = pos.x * texture(iData, 0).x;
    float g = pos.y * texture(iData, 0).y;
    return vec2(r, g);
}

void main()
{
    float u = gl_FragCoord.x / iResolution.x;
    float v = gl_FragCoord.y / iResolution.y;
    gl_FragColor = vec4(f(vec2(u, v)), 1.0, 1.0);
}
