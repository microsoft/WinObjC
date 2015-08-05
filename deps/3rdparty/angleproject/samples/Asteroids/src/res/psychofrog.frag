varying vec4 diffuse,ambientGlobal, ambient;
varying vec3 normal,lightDir,halfVector;
varying float dist, posZ;

uniform sampler2D tex;
uniform int time;

void main()
{
	vec3 n,halfV,viewV,ldir;
	float NdotL,NdotHV;
	vec4 color = ambientGlobal;
	float att;
	
	/* a fragment shader can't write a verying variable, hence we need
	a new variable to store the normalized interpolated normal */
	n = normalize(normal);
	
	/* compute the dot product between normal and ldir */
	NdotL = max(dot(n,normalize(lightDir)),0.0);

	if (NdotL > 0.0) {
	
		att = 1.0 / (gl_LightSource[1].constantAttenuation +
				gl_LightSource[1].linearAttenuation * dist +
				gl_LightSource[1].quadraticAttenuation * dist * dist);
		color += att * (diffuse * NdotL + ambient);
	
		
		halfV = normalize(halfVector);
		NdotHV = max(dot(n,halfV),0.0);
		color += att * gl_FrontMaterial.specular * gl_LightSource[1].specular * pow(NdotHV,gl_FrontMaterial.shininess);
	}

	vec4 texel = texture2D(tex,gl_TexCoord[0].st);

	gl_FragColor = color * texel;;
	
	// rainbow
	gl_FragColor.r = gl_FragColor.r + 0.5*sin((time*0.003)+posZ) - 0.5;
	gl_FragColor.g = gl_FragColor.g + 0.5*sin((time*0.004)+posZ) - 0.5;
	gl_FragColor.b = gl_FragColor.b + 0.5*sin((-time*0.005)+posZ) - 0.5;
}
