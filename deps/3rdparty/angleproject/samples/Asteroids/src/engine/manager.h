#ifndef _MANAGER_H_
#define _MANAGER_H_ 

#include "logger.h"

#include <vector>

#include <stdlib.h>


/**
 * Abstract class describing location of resource (Teges Resource Location)
 */

/*class TRL {
	public:
		virtual bool equals(TRL& trl) = 0;
		virtual char* getString() = 0;
};*/

class SimpleTrl {//: public TRL {
public:
	char* resourceString;
	SimpleTrl(const char* resString);
	virtual bool equals(SimpleTrl* trl);
	virtual char* getString();
};

/**
 * Template class describing resource which collection manager will manage
 */
template <class Handle, class Object, class TrlType>
class TheResource {
	public:
		Handle* handle;
		TrlType* resourceLocation;
		std::vector<Object*> objects; // List of objects using this resource
		virtual ~TheResource() { }
};

/**
 * Manager defines all abstract things that should be done when managing various resources
 */
template <class Handle, class Object, class TrlType>
class Manager {
	public:
		typedef TheResource<Handle,Object,TrlType> Resource;
		typedef std::vector<Resource*> ResourceList;
		typedef typename ResourceList::iterator ResourceIterator;
		typedef std::vector<Object*> ObjectList;
		typedef typename ObjectList::iterator ObjectIterator;

	protected:
		ResourceList resources;
		bool managerEnabled;
		//TrlType resourceLocation;

		Resource* findResource(TrlType* resourceLocation);
		Resource* findResource(Handle* resource);
		virtual Resource* createResource() = 0;
		virtual Handle* loadResource(TrlType* resourceLocation) = 0;

	public:
		Manager(bool _managerEnabled);
		virtual ~Manager();
		virtual void cleanUp();
		virtual Handle* associate(Object* object, TrlType* resourceLocation);
		virtual bool associate(Object* object, Handle* handle);
		virtual bool free(Object* object, Handle* handle);
		bool isEnabled() { return managerEnabled; }
		ResourceList getResourceList() { return resources; }
};


// Implementation in header file due to delayed instantiation of templates

template<class Handle, class Object, class TrlType>
Manager<Handle,Object,TrlType>::Manager(bool _managerEnabled)
	: managerEnabled(_managerEnabled)
	{ }


template<class Handle, class Object, class TrlType>
Manager<Handle,Object,TrlType>::~Manager() {
	cleanUp();
	//delete resourceLocation; // TODO: Check why not to delete
}


template<class Handle, class Object, class TrlType>
void Manager<Handle,Object,TrlType>::cleanUp() {
	for(ResourceIterator i = resources.begin(); i != resources.end(); ++i) {
		if(*i) delete *i;
		*i = NULL;
	}
	resources.clear();
}


template<class Handle, class Object, class TrlType>
TheResource<Handle,Object,TrlType>* Manager<Handle,Object,TrlType>::findResource(TrlType* resourceLocation) {
	for(ResourceIterator i = resources.begin(); i != resources.end(); ++i) {
		if(resourceLocation->equals((*i)->resourceLocation)) return *i;
	}
	return NULL;
}


template<class Handle, class Object, class TrlType>
TheResource<Handle,Object,TrlType>* Manager<Handle,Object,TrlType>::findResource(Handle* handle) {
	for(ResourceIterator i = resources.begin(); i != resources.end(); ++i) {
		if(handle == (*i)->handle) return *i;
	}
	return NULL;
}


template<class Handle, class Object, class TrlType>
Handle* Manager<Handle,Object,TrlType>::associate(Object* object, TrlType* resourceLocation) {
	if(!managerEnabled) return NULL;
	Handle* handle = NULL;
	Resource* resource = findResource(resourceLocation);
	if(resource == NULL) { 
		// There is no such resrouce in memory
		handle = loadResource(resourceLocation);
		if(handle == NULL) {
			// TODO: Handle out of memory, then delete first not used anymore reousrce and try once again
			logger(-1, "Error loading resource %s", resourceLocation->getString());
			exit(1);
		}
		resource = createResource();
		resource->resourceLocation = resourceLocation;
		resource->handle = handle;
		resources.push_back(resource); // Add to list of loaded textures
	} else {
		for(ObjectIterator i = resource->objects.begin(); i != resource->objects.end(); ++i) {
			if((*i) == object) return resource->handle; // If object is on the list just return the glIdent;
		}
	}
	resource->objects.push_back(object); // Add object to the list
	return resource->handle;
}


template<class Handle, class Object, class TrlType>
bool Manager<Handle,Object,TrlType>::associate(Object* object, Handle* handle) {
	if(!managerEnabled) return false;
	Resource* resource = findResource(handle);
	if(resource == NULL) {
		logger(-1, "Missing resource! handle: %p", handle);
		// TODO:return false;
		exit(1);
	}

	// TOOD: Do we need to check this?
	for(ObjectIterator i = resource->objects.begin(); i != resource->objects.end(); ++i) {
		if((*i) == object) {
			return true;
		}
	}
	resource->objects.push_back(object);
	return true;
}


template<class Handle, class Object, class TrlType>
bool Manager<Handle,Object,TrlType>::free(Object* object, Handle* handle) {
	if(!managerEnabled) return true;
	Resource* resource = findResource(handle);
	logger(3, "Freeing %s", resource->resourceLocation->getString());
	for(ObjectIterator i = resource->objects.begin(); i != resource->objects.end(); ++i) {
		if((*i) == object) {
			//delete (*i);
			resource->objects.erase(i);
			return true;
		}
	}
	// TODO: Trigger texture deleting if not used anymore?
	return false;
}


#endif // _MANAGER_H_
