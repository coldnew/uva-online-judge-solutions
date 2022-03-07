ADD_EXECUTABLE(uva263
  uva263.cpp)

ADD_EXECUTABLE(uva263_unittest
  uva263_unittest.cpp)
TARGET_LINK_LIBRARIES(uva263_unittest PUBLIC ${GTEST_LIBRARIES})
ADD_TEST(NAME uva263_unittest COMMAND uva263_unittest)
