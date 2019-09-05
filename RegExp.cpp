#include "RegExp.h"

RegExp::RegExp(const std::string &inRegexp, const std::string &inString)
{
    this->SetRegexpStringVec(inRegexp, inString);
}

void RegExp::SetRegexpStringVec(const std::string &inRegexp, const std::string &inString)
{
    mRegex = std::regex(inRegexp);

    {
    //boost::timer::auto_cpu_timer t;

    std::string endMatch("\n\n");
    mBeginTimer = std::chrono::steady_clock::now();
    mMatchNum = 0;

    std::regex_iterator<std::string::const_iterator> iter ( inString.cbegin(), inString.cend(), mRegex );
    std::regex_iterator<std::string::const_iterator> IterEnd;
    while (iter != IterEnd)
    {
        this->mResultStr += iter->str() + endMatch;
        ++mMatchNum;

        ++iter;
    }

    mEndTimer = std::chrono::steady_clock::now();
    }
}

void RegExp::PrintResult()
{
    std::cout << this->mResultStr << "\n";
}

void RegExp::Timer()
{
    std::cout << "RegExp Timer:" << std::endl;
    std::cout << "Time difference minutes      = " << std::chrono::duration_cast<std::chrono::minutes>     (mEndTimer - mBeginTimer).count() <<std::endl;
    std::cout << "Time difference seconds      = " << std::chrono::duration_cast<std::chrono::seconds>     (mEndTimer - mBeginTimer).count() <<std::endl;
    std::cout << "Time difference microseconds = " << std::chrono::duration_cast<std::chrono::microseconds>(mEndTimer - mBeginTimer).count() <<std::endl;
    std::cout << "Time difference nanoseconds  = " << std::chrono::duration_cast<std::chrono::nanoseconds> (mEndTimer - mBeginTimer).count() <<std::endl;
}
