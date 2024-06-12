#include <gtest/gtest.h>
#include "../ex06/Harl.hpp"

TEST(HarlTest, debugComplaint) {
  Harl harl;
  testing::internal::CaptureStdout();
  harl.complain("DEBUG");
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, Harl::DEBUG_STR + "\n\n" + Harl::INFO_STR + "\n\n" + Harl::WARNING_STR + "\n\n" + Harl::ERROR_STR + '\n');
}

TEST(HarlTest, infoComplaint) {
  Harl harl;
  testing::internal::CaptureStdout();
  harl.complain("INFO");
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, Harl::INFO_STR + "\n\n" + Harl::WARNING_STR + "\n\n" + Harl::ERROR_STR + '\n');
}

TEST(HarlTest, warningComplaint) {
  Harl harl;
  testing::internal::CaptureStdout();
  harl.complain("WARNING");
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, Harl::WARNING_STR + "\n\n" + Harl::ERROR_STR + '\n');
}

TEST(HarlTest, errorComplaint) {
  Harl harl;
  testing::internal::CaptureStdout();
  harl.complain("ERROR");
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, Harl::ERROR_STR + '\n');
}

TEST(HarlTest, invalidComplaint) {
  Harl harl;
  testing::internal::CaptureStdout();
  harl.complain("INVALID");
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, Harl::OTHER_STR +'\n');
}
