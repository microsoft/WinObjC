#ifndef _TEGES_OBJECT_H
#define _TEGES_OBJECT_H

class Teges;

class TegesObject {
		//static const char className[]; // debug, should be cleaned in release
		int connections;
		friend class Teges;

	protected:
		Teges* engine;

	public:
		TegesObject(Teges* _engine) : connections(0), engine(_engine) { }
		virtual ~TegesObject();
		//virtual const char* getClass() { return className; } // debug, should be cleaned in release
};

#endif
