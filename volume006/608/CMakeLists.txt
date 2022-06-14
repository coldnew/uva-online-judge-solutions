ADD_EXECUTABLE(uva608
  uva608.cpp)

ADD_EXECUTABLE(uva608_unittest
  uva608_unittest.cpp)
TARGET_LINK_LIBRARIES(uva608_unittest PUBLIC ${GTEST_LIBRARIES})
ADD_TEST(NAME uva608_unittest COMMAND uva608_unittest)
