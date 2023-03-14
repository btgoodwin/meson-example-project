#pragma once

#define __EXAMPLE_LIB_INSIDE__

#include <api.h>

namespace example_lib {

EXAMPLE_LIB_API
void some_exported_call(void);

};

#undef __EXAMPLE_LIB_INSIDE__