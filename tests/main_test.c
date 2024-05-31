#include "CUnit/Basic.h"

#include "unit_test.h"
#include "building_test.h"

int main() {
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  CU_pSuite pSuite = NULL;

  pSuite = CU_add_suite("strategygame_test_suite", 0, 0);

  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* -------------------------- UNIT_TEST --------------------------*/

  if (NULL == CU_add_test(pSuite, "allocate_unit_test", allocate_unit_test)) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if (NULL == CU_add_test(pSuite, "insert_unit_test", insert_unit_test)) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if (NULL == CU_add_test(pSuite, "remove_unit_test", remove_unit_test)) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* -------------------------- UNIT_TEST --------------------------*/

  /* -------------------------- BUILDING_TEST --------------------------*/

  if (NULL == CU_add_test(pSuite, "allocate_building_test", allocate_building_test)) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if (NULL == CU_add_test(pSuite, "insert_building_test", insert_building_test)) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if (NULL == CU_add_test(pSuite, "remove_building_test", remove_building_test)) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* -------------------------- BUILDING_TEST --------------------------*/

   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   return CU_get_error();
}