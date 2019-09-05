#ifndef REGEXP_H
#define REGEXP_H

#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <chrono>

#include "boost/timer/timer.hpp"
#include <boost/regex.hpp>

class RegExp
{
public:
    RegExp(const std::string &inRegexp, const std::string& inString);
    void SetRegexpStringVec(const std::string &inRegexp , const std::string &inString);
    void PrintResult();
    void Timer();
    std::string  mResultStr;
    unsigned int mMatchNum;

private:

    std::string mString;
    std::smatch mSMath;
    std::regex  mRegex;

    std::vector<std::string> mVecStringsParth;

    std::chrono::steady_clock::time_point mBeginTimer, mEndTimer;
};

#endif // REGEXP_H
