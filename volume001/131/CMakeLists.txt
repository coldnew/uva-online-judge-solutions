ADD_EXECUTABLE(uva131
  uva131.cpp)

ADD_EXECUTABLE(uva131_unittest
  uva131_unittest.cpp)
TARGET_LINK_LIBRARIES(uva131_unittest PUBLIC ${GTEST_LIBRARIES})
ADD_TEST(NAME uva131_unittest COMMAND uva131_unittest)
