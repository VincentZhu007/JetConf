//
// Created by Vincent Zhu on 2022/6/18.
//
#include <iostream>
#include <string>
#include <sstream>
#include "gtest/gtest.h"
#include "customer_conf.h"

using namespace std;
using namespace jetconf::experiments;

/**
 * 测试Address类
 */
class AddressTest: public ::testing::Test {
 public:
  void SetUp() override
  {
    std::cout << "AddressTest SetUp..." << std::endl;
  }
  void TearDown() override
  {
    std::cout << "AddressTest TearDown..." << std::endl;
  }
};

namespace {
template<class T>
std::string SerializedObject(const T &obj)
{
  stringstream ss;
  ss << obj;
  return ss.str();
}
}

TEST_F(AddressTest, NewObject)
{
  ASSERT_EQ(SerializedObject(Address()), "{city:,district:}");
  ASSERT_EQ(SerializedObject(Address("深圳")), "{city:深圳,district:}");
  ASSERT_EQ(SerializedObject(Address("深圳", "龙岗")), "{city:深圳,district:龙岗}");
}

/**
 * 合法的地址类型：
 * - city：类型，字符串；白名单[”深圳”， “汕头”， “广州”]；必须项；
 * - district：类型：字符串；长度[0,100]；字段可选；字段出现的前提是city一定存在。
 */
TEST_F(AddressTest, ValidateAddress)
{
  ASSERT_FALSE(Address::Validate(Address()));
  ASSERT_TRUE(Address::Validate(Address("深圳")));

  // city不在白名单中，地址非法
  ASSERT_FALSE(Address::Validate(Address("杭州")));

  ASSERT_TRUE(Address::Validate(Address("深圳", "龙岗")));
  ASSERT_TRUE(Address::Validate(Address("深圳", "XYZ")));
}

std::string GenerateNLengthString(size_t n)
{
  std::string str(n, 'a');
  return str;
}

TEST_F(AddressTest, ValidateDistrictLength)
{
  // 区名长度为0，预期结果：合法
  ASSERT_TRUE(Address::Validate(Address("深圳", std::string(""))));

  // 区名长度为100，预期结果：合法
  ASSERT_TRUE(Address::Validate(Address("深圳", GenerateNLengthString(100U))));

  // 区名长度为101，预期结果：不合法
  ASSERT_FALSE(Address::Validate(Address("深圳", GenerateNLengthString(101U))));
}
