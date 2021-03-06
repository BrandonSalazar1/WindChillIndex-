//
// Created by aknight on 7/28/18.
//

#ifndef EX09_MOVIEREVIEWS_GTESTNODEATH_H
#define EX09_MOVIEREVIEWS_GTESTNODEATH_H
#include <gtest/gtest.h>

# define EXPECT_NO_DEATH(statement, regex) \
    EXPECT_NO_EXIT(statement, ::testing::internal::ExitedUnsuccessfully, regex)

# define EXPECT_NO_EXIT(statement, predicate, regex) \
    GTEST_NO_DEATH_TEST_(statement, predicate, regex, GTEST_NONFATAL_FAILURE_)

# define GTEST_NO_DEATH_TEST_(statement, predicate, regex, fail) \
  GTEST_AMBIGUOUS_ELSE_BLOCKER_ \
  if (::testing::internal::AlwaysTrue()) { \
    const ::testing::internal::RE& gtest_regex = (regex); \
    ::testing::internal::DeathTest* gtest_dt; \
    if (!::testing::internal::DeathTest::Create(#statement, &gtest_regex, \
        __FILE__, __LINE__, &gtest_dt)) { \
      goto GTEST_CONCAT_TOKEN_(gtest_label_, __LINE__); \
    } \
    if (gtest_dt != NULL) { \
      ::testing::internal::scoped_ptr< ::testing::internal::DeathTest> \
          gtest_dt_ptr(gtest_dt); \
      switch (gtest_dt->AssumeRole()) { \
        case ::testing::internal::DeathTest::OVERSEE_TEST: \
          if (gtest_dt->Passed(predicate(gtest_dt->Wait()))) { \
            goto GTEST_CONCAT_TOKEN_(gtest_label_, __LINE__); \
          } \
          break; \
        case ::testing::internal::DeathTest::EXECUTE_TEST: { \
          ::testing::internal::DeathTest::ReturnSentinel \
              gtest_sentinel(gtest_dt); \
          GTEST_EXECUTE_DEATH_TEST_STATEMENT_(statement, gtest_dt); \
          gtest_dt->Abort(::testing::internal::DeathTest::TEST_ENCOUNTERED_RETURN_STATEMENT); \
          break; \
        } \
        default: \
          break; \
      } \
    } \
  } else \
    GTEST_CONCAT_TOKEN_(gtest_label_, __LINE__): \
      fail(::testing::internal::DeathTest::LastMessage())

# define ASSERT_NO_EXIT(statement, predicate, regex) \
    GTEST_NO_DEATH_TEST_(statement, predicate, regex, GTEST_FATAL_FAILURE_)

#define ASSERT_NO_DEATH(statement, regex) \
    ASSERT_NO_EXIT(statement, ::testing::internal::ExitedUnsuccessfully, regex)

#endif //EX09_MOVIEREVIEWS_GTESTNODEATH_H
