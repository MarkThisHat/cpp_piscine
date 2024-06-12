#include <gtest/gtest.h>
#include "../ex05/Harl.hpp"

TEST(HarlTest, debugComplaint) {
  Harl harl;
  testing::internal::CaptureStdout();
  harl.complain("DEBUG");
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, Harl::DEBUG + '\n');
}

TEST(HarlTest, infoComplaint) {
  Harl harl;
  testing::internal::CaptureStdout();
  harl.complain("INFO");
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, Harl::INFO + '\n');
}

TEST(HarlTest, warningComplaint) {
  Harl harl;
  testing::internal::CaptureStdout();
  harl.complain("WARNING");
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, Harl::WARNING + '\n');
}

TEST(HarlTest, errorComplaint) {
  Harl harl;
  testing::internal::CaptureStdout();
  harl.complain("ERROR");
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, Harl::ERROR + '\n');
}

TEST(HarlTest, invalidComplaint) {
  Harl harl;
  testing::internal::CaptureStdout();
  harl.complain("INVALID");
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "");
}
