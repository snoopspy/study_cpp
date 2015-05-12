#pragma once

void foo();

#ifdef __cplusplus
extern "C" {
#endif

void bar();

#ifdef __cplusplus
}
#endif

#include <cstdlib>
int rand() __THROW;
