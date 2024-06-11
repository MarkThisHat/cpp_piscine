#include <gtest/gtest.h>
#include "../ex04/FileProcessor.hpp"
#include <fstream>
#include <string>

class FileProcessorTest : public ::testing::Test {
protected:
    void SetUp() override {
        std::ofstream srcFile(srcFileName.c_str());
        srcFile << "This is a test file.\nThis file has multiple lines.\nThis line contains a word to be replaced: test\nEnd of file";
        srcFile.close();
    }

    void TearDown() override {
        std::remove(srcFileName.c_str());
        std::remove(replaceFileName.c_str());
    }

    const std::string srcFileName = "test_file.txt";
    const std::string replaceFileName = "test_file.txt.replace";
};

TEST_F(FileProcessorTest, ReplaceString) {
    ASSERT_TRUE(FileProcessor::processFile(srcFileName, "test", "sample"));

    std::ifstream resultFile(replaceFileName.c_str());
    std::string resultContent((std::istreambuf_iterator<char>(resultFile)), std::istreambuf_iterator<char>());
    resultFile.close();

    const std::string expectedContent = "This is a sample file.\nThis file has multiple lines.\nThis line contains a word to be replaced: sample\nEnd of file";
    EXPECT_EQ(resultContent, expectedContent);
}

TEST_F(FileProcessorTest, ReplaceNonExistentString) {
    ASSERT_TRUE(FileProcessor::processFile(srcFileName, "nonexistent", "sample"));

    std::ifstream resultFile(replaceFileName.c_str());
    std::string resultContent((std::istreambuf_iterator<char>(resultFile)), std::istreambuf_iterator<char>());
    resultFile.close();

    const std::string expectedContent = "This is a test file.\nThis file has multiple lines.\nThis line contains a word to be replaced: test\nEnd of file";
    EXPECT_EQ(resultContent, expectedContent);
}

TEST_F(FileProcessorTest, FileNotFound) {
    ASSERT_FALSE(FileProcessor::processFile("non_existent_file.txt", "test", "sample"));
}
