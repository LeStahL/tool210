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
            if (
                    (pos.x >= data.x) && (pos.x < data.x + data.z) &&
                    (pos.y >= data.y) && (pos.y < data.y + data.w)
               )
            {
                res.rgb = mix(res.rgb, color.rgb, color.a);
                res.a = min(1., color.w + res.w);
            }
        } else if (type == 2)
        {
            vec4 data = texture(iData, vec2(2.5/iDataSize.x, (float(i) + 0.5)/iDataSize.y));
            if (length(pos - data.xy) <= data.z)
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
    float u = 2. * gl_FragCoord.x / iResolution.x - 1.;
    float v = 2. * gl_FragCoord.y / iResolution.y - 1.;
    v *= iResolution.y / iResolution.x;
    gl_FragColor = scene2d(vec2(u, v));
}
