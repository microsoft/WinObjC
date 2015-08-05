#include "objector.h"
#include "teges.h"

#include <stdio.h>
		
ObjModel::ObjModel(Teges* _engine) : objector(_engine->getObjector()), Model(_engine), TegesObject(_engine)
{ }

ObjResource::~ObjResource() {
	logger(3, "Freeing obj %s", resourceLocation->getString());
	// TODO
}

Objector::Objector(const char* _resourceDir, bool _objectorEnabled)
	:	ObjManager(_objectorEnabled),
		resourceDir(_resourceDir)
{ }

ObjResource* Objector::createResource() {
	return new ObjResource;
}

MeshNode::MeshNode() { }

MeshNode::~MeshNode() { }

void MeshNode::Render() const {
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, &mPositions[0]);
	glTexCoordPointer(2, GL_FLOAT, 0, &mTexCoords[0]);
	glNormalPointer(GL_FLOAT, 0, &mNormals[0]);

	glDrawElements(GL_TRIANGLES, mIndices.size(), GL_UNSIGNED_INT, &mIndices[0]);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
}

void MeshNode::RenderScaled(Vector3D scale) const {
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);

	std::vector<Vector3D> scaledPositions;
	std::vector<Vector3D>::const_iterator i;
	Vector3D vec3;
	for(i = mPositions.begin(); i != mPositions.end(); ++i) {
		vec3 = *i;
		vec3.x *= scale.x;
		vec3.y *= scale.y;
		vec3.z *= scale.z;
		scaledPositions.push_back(vec3);
	}

	printf("Rendering %i vertices\n", scaledPositions.size());

	glVertexPointer(3, GL_FLOAT, 0, &scaledPositions[0]);
	glTexCoordPointer(2, GL_FLOAT, 0, &mTexCoords[0]);
	glNormalPointer(GL_FLOAT, 0, &mNormals[0]);

	glDrawElements(GL_TRIANGLES, mIndices.size(), GL_UNSIGNED_INT, &mIndices[0]);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);

}

void MeshNode::add(FaceIndex* ptr) {
	for(int i = 0; i<3; ++i, ++ptr) {
		std::map<FaceIndex, GLuint, FaceIndexComparator>::iterator iter = cache.find(*ptr);
		if( iter == cache.end() ) {
			//printf("Nieznaleziono, size = %i\n", cache.size());
			cache[*ptr] = cache.size();
		} else {
			printf("   Znaleziono, size = %i\n", cache.size());
		}
		mPositions.push_back(cPositions[ptr->v -1]);
		mTexCoords.push_back(cTexCoords[ptr->t -1]);
		mNormals.push_back(cNormals[ptr->n -1]);
		mIndices.push_back(cache[*ptr]-1);
	}
}
Mesh::Mesh() { }

Mesh::~Mesh() { }

void Mesh::Render() {
	for(std::vector<MeshNode>::const_iterator i = mNodes.begin(); i != mNodes.end(); ++i) (*i).Render();
}

void Mesh::RenderScaled(Vector3D scale) {
	for(std::vector<MeshNode>::const_iterator i = mNodes.begin(); i != mNodes.end(); ++i) (*i).RenderScaled(scale);
}

Mesh* Objector::loadResource(SimpleTrl* resourceLocation) {
	char* fileName = new char[strlen(resourceDir) + strlen(resourceLocation->resourceString) + 2];
	sprintf(fileName, "%s/%s", resourceDir, resourceLocation->resourceString);
	logger(2, "Loading %s", fileName);
	//TODO Load(fileName);
	
	FILE* inputFile = fopen(fileName, "r");
	if(inputFile == NULL) {
		return NULL;
	}
	
	char line[1024];
	char* ptr;

	// buffers
	Vector3D vec3;
	Vector2D vec2;

	MeshNode meshNode;
	MeshNode::FaceIndex face[3];
	int size;
	int line_no = 0;

	while(fgets(line, 1024, inputFile) != NULL) {
		++line_no;
		for(ptr = line; *ptr == ' ' || *ptr == '\t'; ++ptr); // skip whitepaces

		switch(*ptr) {
			//TODO: Do the rest
			case 'v':
				++ptr;
				switch(*ptr) {
					case 't': // vertex texture coords
						sscanf(line, "%*c%*c %f %f", &vec2.x, &vec2.y);
						meshNode.cTexCoords.push_back(vec2);
						break;
					case 'n': // vertex normal
						sscanf(line, "%*c%*c %f %f %f", &vec3.x, &vec3.y, &vec3.z);
						meshNode.cNormals.push_back(vec3);
						break;
					case ' ':
					case '\t': // vertex position
						sscanf(line, "%*c %f %f %f", &vec3.x, &vec3.y, &vec3.z);
						meshNode.cPositions.push_back(vec3);
						break;
					default:
						logger(-1, "OBJ file syntax error at line %i", line_no);
				}
				break;
			case 'f': // face
				sscanf(line, "%*c %d/%d/%d %d/%d/%d %d/%d/%d",
						&face[0].v, &face[0].t, &face[0].n,
						&face[1].v, &face[1].t, &face[1].n,
						&face[2].v, &face[2].t, &face[2].n
					);
				meshNode.add(face);
				break;
			case 'o':
			case 'u':
			case 's':
			case '#':
			case '\n':
				break;
			default:
				logger(-1, "OBJ file syntax error at line %i", line_no);
		}
	}

	meshNode.cPositions.clear();	
	meshNode.cTexCoords.clear();	
	meshNode.cNormals.clear();	
	meshNode.cache.clear();

	/*printf("Mesh: ");
	for(std::vector<unsigned int>::const_iterator i = meshNode.mIndices.begin(); i != meshNode.mIndices.end(); ++i) {
		printf("%i ", *i);
	}
	printf("\n");*/

	Mesh* res = new Mesh();

	res->mNodes.push_back(meshNode);

	delete [] fileName;
	if(res == NULL) return NULL;
	return res;
}
