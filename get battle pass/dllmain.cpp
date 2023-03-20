#include "misc.h"


bool __stdcall DllMain(void* dll, unsigned long call, void* reserved) {
	if (call == 1) 
	{
		alloc_console();
		init_hook();
	}
	return true;
}