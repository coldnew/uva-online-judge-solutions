ADD_EXECUTABLE(uva100
  uva100.cpp)

ADD_EXECUTABLE(uva100_unittest
  uva100_unittest.cpp)
TARGET_LINK_LIBRARIES(uva100_unittest PUBLIC ${GTEST_LIBRARIES})
ADD_TEST(NAME uva100_unittest COMMAND uva100_unittest)
