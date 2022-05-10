ADD_EXECUTABLE(uva514
  uva514.cpp)

ADD_EXECUTABLE(uva514_unittest
  uva514_unittest.cpp)
TARGET_LINK_LIBRARIES(uva514_unittest PUBLIC ${GTEST_LIBRARIES})
ADD_TEST(NAME uva514_unittest COMMAND uva514_unittest)
