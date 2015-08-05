#include "manager.h"

#include <string.h>

SimpleTrl::SimpleTrl(const char* resString) {
	int l = strlen(resString);
	resourceString = new char[++l];
	strncpy(resourceString, resString, l);
}

bool SimpleTrl::equals(SimpleTrl* trl) {
	if(strncmp(resourceString, trl->resourceString, strlen(resourceString)) == 0) return true;
	else return false;
}

char* SimpleTrl::getString() {
	return resourceString;
}


