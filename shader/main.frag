#version 130

uniform sampler2D iData;
uniform vec2 iResolution;
uniform vec2 iDataSize;

vec4 scene2d(vec2 pos)
{
    vec4 res = vec4(0.);
    for (int i=0; i<iDataSize.y; i++)
    {
        vec4 header = texture(iData, vec2(0.5/iDataSize.x, (float(i) + 0.5)/iDataSize.y ));
        int type = int(header.x);
        vec4 color = texture(iData, vec2(1.5/iDataSize.x, (float(i) + 0.5)/iDataSize.y));
        if (type == 1)
        {
            vec4 data = texture(iData, vec2(2.5/iDataSize.x, (float(i) + 0.5)/iDataSize.y));
            float x = data.x;
            float y = data.y;
            float w = data.z;
            float h = data.w;
            if (
                    (pos.x >= x) && (pos.x < x + w) &&
                    (pos.y >= y) && (pos.y < y + h)
               )
            {
                res.rgb = mix(res.rgb, color.rgb, color.a);
                res.a = min(1., color.w + res.w);
            }
        }
    }
    return res;
}

void main()
{
    float u = gl_FragCoord.x / iResolution.x;
    float v = gl_FragCoord.y / iResolution.y;
    gl_FragColor = scene2d(vec2(u, v));
}
