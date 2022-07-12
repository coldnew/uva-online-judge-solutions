ADD_EXECUTABLE(uva246
  uva246.cpp)

ADD_EXECUTABLE(uva246_unittest
  uva246_unittest.cpp)
TARGET_LINK_LIBRARIES(uva246_unittest PUBLIC ${GTEST_LIBRARIES})
ADD_TEST(NAME uva246_unittest COMMAND uva246_unittest)
