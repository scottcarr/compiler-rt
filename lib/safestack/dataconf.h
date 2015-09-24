#include <stdlib.h>
#include <stdbool.h>

void __dc_init();
extern "C" __attribute__((visibility("default"))) void __dc_unsafe_free(void* ptr);
extern "C" __attribute__((visibility("default"))) void __dc_safe_free(void* ptr);
extern "C" __attribute__((visibility("default"))) void* __dc_unsafe_malloc(size_t n);
extern "C" __attribute__((visibility("default"))) void* __dc_safe_malloc(size_t n);
