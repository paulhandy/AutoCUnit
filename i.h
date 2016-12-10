#ifndef I_H
#define I_H

#include "BCUnit/BCUnit.h"


typedef struct suite_ptr_s {
	CU_SuiteInfo *st; /* suite */
} suite_ptr_t;


#define ADD_SUITE(suite_s)			\
	static suite_ptr_t ptr_##suite_s	\
__attribute((used, section("my_suites"))) = {	\
	.st = suite_s,				\
}

/*
typedef CU_SuiteInfo *(*my_func_cb)(void);

typedef struct func_ptr_s {
	my_func_cb cb;  // function callback
} func_ptr_t;
#define ADD_FUNC(func_cb)                        \
static func_ptr_t ptr_##func_cb              \
__attribute((used, section("my_array"))) = { \
.cb = func_cb,                           \
}
*/
#endif

