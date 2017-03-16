#ifndef DEPENDENCYKIND_H
#define DEPENDENCYKIND_H

namespace ApplicationInsights
{
	namespace core
	{
		enum DependencyKind
		{
			SQL = 0,
			Http = 1,
			Other = 2,
		};
	}
}
#endif
