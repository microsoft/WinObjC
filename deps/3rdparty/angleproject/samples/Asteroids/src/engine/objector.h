#ifndef _OBJECTOR_H_
#define _OBJECTOR_H_ 

#include "logger.h"
#include "manager.h"
#include "model.h"

#include <vector>
#include <map>

class Vector2D {
	public:
		float x, y;
};

class Vector3D { //: public Vector2D {
	public:
		float x, y, z;
};

class Vector4D {
	public:
		float x, y, z, w;
};

class MeshNode {
	public:
		class FaceIndex {
			public:
				GLuint v, t, n;     // pos, texture, normal...
		};

		class FaceIndexComparator
		{
			public:
				bool operator() (const FaceIndex& a, const FaceIndex& b) const
				{
					if(a.v < b.v) return true;
					if(a.v == b.v && a.t < b.t) return true;
					if(a.v == b.v && a.t == b.t && a.n < b.n) return true;
					return false;
				}
		};

		std::map<FaceIndex, GLuint, FaceIndexComparator> cache;
		
		std::vector<Vector3D> cPositions;
		std::vector<Vector2D> cTexCoords;
		std::vector<Vector3D> cNormals;

		std::vector<GLuint> mIndices;

		std::vector<Vector3D> mPositions;
		std::vector<Vector2D> mTexCoords;
		std::vector<Vector3D> mNormals;

		MeshNode();
		virtual ~MeshNode();
		void Clear();
		virtual void Render() const;
		virtual void RenderScaled(Vector3D scale) const;

		void add(FaceIndex* ptr);
};

class Mesh {
	public:
		//TODO: Don't mess with mesh :]
		std::vector<MeshNode> mNodes;
		Mesh();
		virtual ~Mesh();
		void Clear();
		virtual void Render();
		virtual void RenderScaled(Vector3D scale);
		//MeshNode *GetNode(int id) { return mNodes[id]; }
};

class Objector;

class ObjModel : public Model {
	protected:
		Objector* objector;
	public:
		ObjModel(Teges* _engine);
};

class ObjResource : public TheResource<Mesh, ObjModel, SimpleTrl> {
	public:
		virtual ~ObjResource();
};

template class Manager<Mesh, ObjModel, SimpleTrl>;
typedef Manager<Mesh, ObjModel, SimpleTrl> ObjManager;

class Objector : public ObjManager {
	public:
		typedef ObjManager::ResourceList ObjResourceList;
		typedef ObjResourceList::iterator ObjResourceIterator;
	protected:
		const char* resourceDir;
		ObjResource* createResource();
		Mesh* loadResource(SimpleTrl* resourceLocation);
	public:
		Objector(const char* _resourceDir, bool _objectorEnabled = true);
		~Objector() { };
};

#endif
