#ifndef SEVERITYLEVEL_H
#define SEVERITYLEVEL_H

namespace ApplicationInsights
{
	namespace core
	{
		enum SeverityLevel
		{
			Verbose = 0,
			Information = 1,
			Warning = 2,
			Error = 3,
			Critical = 4,
		};
	}
}
#endif
