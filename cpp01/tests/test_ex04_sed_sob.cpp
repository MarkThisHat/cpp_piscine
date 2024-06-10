#include <gtest/gtest.h>
#include "../ex04/FileProcessor.hpp"
#include <fstream>
#include <string>

class FileProcessorTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Create a test file with known content
        std::ofstream srcFile(srcFileName);
        srcFile << "This is a test file.\nThis file has multiple lines.\nThis line contains a word to be replaced.\n";
        srcFile.close();
    }

    void TearDown() override {
        // Remove test files if they exist
        std::remove(srcFileName.c_str());
    }

    const std::string srcFileName = "test_file.txt";
};

TEST_F(FileProcessorTest, ReplaceString) {
    ASSERT_TRUE(FileProcessor::processFile(srcFileName, "test", "sample"));

    std::ifstream resultFile(srcFileName.c_str());
    std::string resultContent((std::istreambuf_iterator<char>(resultFile)), std::istreambuf_iterator<char>());
    resultFile.close();

    const std::string expectedContent = "This is a sample file.\nThis file has multiple lines.\nThis line contains a word to be replaced.\n";
    EXPECT_EQ(resultContent, expectedContent);
}

TEST_F(FileProcessorTest, ReplaceNonExistentString) {
    ASSERT_TRUE(FileProcessor::processFile(srcFileName, "nonexistent", "sample"));

    std::ifstream resultFile(srcFileName);
    std::string resultContent((std::istreambuf_iterator<char>(resultFile)), std::istreambuf_iterator<char>());
    resultFile.close();

    const std::string expectedContent = "This is a test file.\nThis file has multiple lines.\nThis line contains a word to be replaced.\n";
    EXPECT_EQ(resultContent, expectedContent);
}

TEST_F(FileProcessorTest, FileNotFound) {
    ASSERT_FALSE(FileProcessor::processFile("non_existent_file.txt", "test", "sample"));
}
