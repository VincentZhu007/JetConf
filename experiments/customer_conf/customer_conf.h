//
// Created by Vincent Zhu on 2022/6/18.
//

#ifndef JETCONF_CUSTOMER_CONF_H
#define JETCONF_CUSTOMER_CONF_H

#include <iostream>
#include <string>
#include <unordered_set>

namespace jetconf {
namespace experiments {
/**
 * Customer address
 */
class Address {
 public:
  Address() {}
  Address(const std::string &city, const std::string &district = "") :
      city_(city), district_(district) {}
  ~Address() = default;
  Address(const Address &) = delete;
  Address &operator=(const Address &) = delete;

  static bool Validate(const Address &obj)
  {
    return ValidateCity(obj) && ValidateDistrict(obj);
  }

 private:
  std::string city_ = {};
  std::string district_ = {};
  static bool ValidateCity(const Address &obj)
  {
    const std::unordered_set<std::string> CITY_WHITE_LIST = {
        "深圳", "汕头", "广州"
    };
    return CITY_WHITE_LIST.find(obj.city_) != CITY_WHITE_LIST.end();
  }
  static bool ValidateDistrict(const Address &obj)
  {
    return (obj.district_.length() <= 100);
  }

  friend std::ostream &operator<<(std::ostream &os, const Address &obj)
  {
    os << "{city:" << obj.city_ << ",district:" << obj.district_ << "}";
    return os;
  }
};

enum class CustomerType {
  NORMAL = 0,
  VIP = 1,
  VVIP = 2,
};

//struct CustomerInfo {
//  int64_t id;
//  CustomerType type;
//  Address adress;
//  Phone phone;
//  Email email;
//};

//class CustomerConf {
// public:
//  CustomerConf() = default;
//  int Parse(const std::string &confPath);
//  int Parse(std::istream &in);
//  std::vector<std::string> GetPages() const;
//  std::unordered_map<std::string, std::string> GetWindow() const;
//
// private:
//  void DoParsePages(const Json::Value root);
//  void DoParseWindow(const Json::Value root);
//  static int DoReadJson(std::istream &in, Json::Value &root);
//
//  std::vector<std::string> pages_ = {};
//  std::unordered_map<std::string, std::string> window_ = {};
//};
}
}

#endif // JETCONF_CUSTOMER_CONF_H
