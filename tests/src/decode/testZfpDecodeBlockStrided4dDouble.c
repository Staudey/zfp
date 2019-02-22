#include "src/decode4d.c"

#include "constants/4dDouble.h"
#include "utils/rand64.h"
#include "zfpDecodeBlockStridedBase.c"

int main()
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test_setup_teardown(when_seededRandomDataGenerated_expect_ChecksumMatches, setup, teardown),
    cmocka_unit_test_setup_teardown(given_4dDoubleBlock_when_DecodeBlockStrided_expect_ReturnValReflectsNumBitsReadFromBitstream, setup, teardown),
    cmocka_unit_test_setup_teardown(given_4dDoubleBlock_when_DecodeBlockStrided_expect_OnlyStridedEntriesChangedInDestinationArray, setup, teardown),
    cmocka_unit_test_setup_teardown(given_4dDoubleBlock_when_DecodeBlockStrided_expect_ArrayChecksumMatches, setup, teardown),
    cmocka_unit_test_setup_teardown(given_4dDoubleBlock_when_DecodePartialBlockStrided_expect_ReturnValReflectsNumBitsReadFromBitstream, setup, teardown),
    cmocka_unit_test_setup_teardown(given_4dDoubleBlock_when_DecodePartialBlockStrided_expect_NonStridedEntriesUnchangedInDestinationArray, setup, teardown),
    cmocka_unit_test_setup_teardown(given_4dDoubleBlock_when_DecodePartialBlockStrided_expect_EntriesOutsidePartialBlockBoundsUnchangedInDestinationArray, setup, teardown),
    cmocka_unit_test_setup_teardown(given_4dDoubleBlock_when_DecodePartialBlockStrided_expect_ArrayChecksumMatches, setup, teardown),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
