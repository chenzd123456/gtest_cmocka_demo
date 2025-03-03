#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "print_to_file.h"
#include "mock_functions.h"
#include <stddef.h>
using ::testing::_;
using ::testing::Return;

class PrintToFileTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        if (mock_functions == nullptr)
        {
            mock_functions = new MockFunctions();
        }
    }

    void TearDown() override
    {
        if (mock_functions != nullptr)
        {
            delete mock_functions;
            mock_functions = nullptr;
        }
    }
};

TEST_F(PrintToFileTest, SuccessCase)
{
    const char *test_message = "Hello, World!";
    const char *test_filename = "test.txt";

    // Setup mock expectations
    EXPECT_CALL(*mock_functions, open(_, _, _))
        .WillOnce(Return(3)); // Use any valid file descriptor
    EXPECT_CALL(*mock_functions, write(_, test_message, strlen(test_message)))
        .WillOnce(Return(strlen(test_message)));
    EXPECT_CALL(*mock_functions, close(_))
        .WillOnce(Return(0));

    // Execute test
    int result = print_to_file(test_filename, test_message);

    // Verify results
    EXPECT_EQ(result, 0);
}

TEST_F(PrintToFileTest, FailureCase)
{
    const char *test_message = "Hello, World!";
    const char *test_filename = "test.txt";

    // Setup mock expectations
    EXPECT_CALL(*mock_functions, open(_, _, _))
        .WillOnce(Return(-1));

    // Execute test
    int result = print_to_file(test_filename, test_message);

    // Verify results
    EXPECT_EQ(result, -1);
}
