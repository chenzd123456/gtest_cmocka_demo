#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "print_to_file.h"
#include "mock_functions.h"
#include <stddef.h>
using ::testing::_;
using ::testing::Return;

class PrintToFileTest : public ::testing::Test {
protected:
    // std::shared_ptr<MockFunctions> mock_functions_ptr;

    void SetUp() override {
        // mock_functions_ptr = std::make_shared<MockFunctions>();
        // // Reset mock expectations before each test
        // ::testing::Mock::VerifyAndClearExpectations(mock_functions_ptr.get());
        // // Allow mock to leak since it's managed by shared_ptr
        // ::testing::Mock::AllowLeak(mock_functions_ptr.get());
    }

    void TearDown() override {
        // mock_functions_ptr.reset();
    }
};

TEST_F(PrintToFileTest, SuccessCase) {
    const char *test_message = "Hello, World!";
    const char *test_filename = "test.txt";

    // Setup mock expectations
    // EXPECT_CALL(mock_functions, open(_, _))
    //     .WillOnce(Return(3));  // Use any valid file descriptor
    // EXPECT_CALL(mock_functions, write(_, test_message, strlen(test_message)))
    //     .WillOnce(Return(strlen(test_message)));
    // EXPECT_CALL(mock_functions, close(_))
    //     .WillOnce(Return(0));

    // Execute test
    int result = print_to_file(test_filename, test_message);

    // Verify results
    EXPECT_EQ(result, 0);
    
    // Verify no other calls were made
    // EXPECT_TRUE(testing::Mock::VerifyAndClearExpectations(&mock_functions));
}

TEST_F(PrintToFileTest, FailureCase) {
    const char *test_message = "Hello, World!";
    const char *test_filename = "test.txt";

    // Setup mock expectations
    // EXPECT_CALL(*mock_functions_ptr, open(_, _))
    //     .WillOnce(Return(-1));

    // Execute test
    int result = print_to_file(test_filename, test_message);

    // Verify results
    EXPECT_EQ(result, -1);

    // Verify no other calls were made
    // EXPECT_TRUE(testing::Mock::VerifyAndClearExpectations(&mock_functions));
}
