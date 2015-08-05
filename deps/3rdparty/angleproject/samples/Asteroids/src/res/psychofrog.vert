varying vec4 diffuse,ambientGlobal,ambient;
varying vec3 normal,lightDir,halfVector;
varying float dist;
varying float posZ;

uniform int time;

void main()
{	
	vec4 ecPos;
	vec3 aux;
	
	/* first transform the normal into eye space and normalize the result */
	normal = normalize(gl_NormalMatrix * gl_Normal);
	
	/* now normalize the light's direction. Note that according to the
	OpenGL specification, the light is stored in eye space. Also since 
	we're talking about a directional light, the position field is actually 
	direction */
	ecPos = gl_ModelViewMatrix * gl_Vertex;
	aux = vec3(gl_LightSource[1].position-ecPos);
	lightDir = normalize(aux);
	
	/* compute the distance to the light source to a varying variable*/
	dist = length(aux);

	/* Normalize the halfVector to pass it to the fragment shader */
	halfVector = normalize(gl_LightSource[1].halfVector.xyz);
	
	/* Compute the diffuse, ambient and globalAmbient terms */
	diffuse = gl_FrontMaterial.diffuse * gl_LightSource[1].diffuse;
	ambient = gl_FrontMaterial.ambient * gl_LightSource[1].ambient;
	ambientGlobal = gl_LightModel.ambient * gl_FrontMaterial.ambient;
	

	vec4 v = vec4(gl_Vertex);
	v.x = v.x + 0.2*sin(v.y+0.002 *time);
	v.y = v.y + 0.1*sin(v.z+0.0013*time);
	v.z = v.z + 0.1*sin(v.x+0.0016*time);
	
	gl_Position = gl_ModelViewProjectionMatrix * v;
	
	gl_TexCoord[0] = gl_MultiTexCoord0;
	posZ = gl_Vertex.z;
		
} 
