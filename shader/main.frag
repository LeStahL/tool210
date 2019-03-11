#version 130

void main()
{
    gl_FragColor = vec4(0.001 * gl_FragCoord.xyz, 1.0);
}
