varying vec3 lightVec;
varying vec3 eyeVec;
varying vec2 texCoord;
uniform sampler2D colorMap;
uniform sampler2D normalMap;
uniform sampler2D heightMap;
uniform float invRadius;

void main (void)
{
	float distSqr = dot(lightVec, lightVec);
	float att = clamp(1.0 - invRadius * sqrt(distSqr), 0.0, 1.0);
	vec3 lVec = lightVec * inversesqrt(distSqr);
	vec3 vVec = normalize(eyeVec);

	//float height = texture2D(heightMap, gl_TexCoord[0].st).r;
	float height = texture2D(heightMap, texCoord).r;
	float v = height * 0.08 - 0.04;
	vec2 newCoord = texCoord + (vVec.xy * v);

	vec4 base = texture2D(colorMap, newCoord);
	vec3 bump = normalize( texture2D(normalMap, newCoord).xyz * 2.0 - 1.0);
	
	vec4 vAmbient = gl_LightSource[0].ambient * gl_FrontMaterial.ambient + gl_LightSource[1].ambient * gl_FrontMaterial.ambient;

	float diffuse = max( dot(-lVec, bump), 0.0 );
	vec4 vDiffuse = gl_LightSource[1].diffuse * gl_FrontMaterial.diffuse * diffuse;	

	float specular = pow(clamp(dot(reflect(lVec, bump), vVec), 0.0, 1.0), gl_FrontMaterial.shininess );
	vec4 vSpecular = gl_LightSource[1].specular * gl_FrontMaterial.specular * specular;
	
	gl_FragColor = ( vAmbient*base + vDiffuse*base + vSpecular) * att;
}
