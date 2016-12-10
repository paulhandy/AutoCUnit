
#include "BCUnit/BCUnit.h"
#include "BCUnit/Basic.h"
#include "i.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define DEBUG
#define section_foreach_entry(section_name, type_t, elem)	\
	for (type_t *elem =					\
			({					\
			 extern type_t __start_##section_name;	\
			 &__start_##section_name;		\
			 });					\
			elem !=					\
			({					\
			 extern type_t __stop_##section_name;	\
			 &__stop_##section_name;		\
			 });					\
			++elem)

int main (int argc, char** argv) {
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	CU_ErrorCode error;

	section_foreach_entry(my_suites, suite_ptr_t, entry) {
		error = CU_register_suites(entry->st);
		if ( CUE_SUCCESS != error) {
			CU_cleanup_registry();
			fprintf(stderr, "suite registration failed - %s\n",
					CU_get_error_msg());
			exit(EXIT_FAILURE);
		}
	}


	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	//CU_automated_run_tests();
	//CU_list_tests_to_file();
	return CU_get_error();
}
