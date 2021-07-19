// Scope rules are applicable on enums. The do have defined lifetime within their scope.
#include<iostream>

// enum Example : unsigned char    // <: unsigned char> is optional. unsigned int32 by default. Also, char is basically integer int8.
// {
//     A, B=5, C
// };
// int main(int argc, char const *argv[])
// {
//     Example value = B;
//     if (value == B)
//     {
//         std::cout << "Positive " << B << std::endl;
//     }
//     return 0;
// }

class Log
{
    public:
        enum Example : unsigned char
        {
            logLevelError,
            logLevelWarning,
            logLevelInfo
        };
    private:
        Example m_logLevel = logLevelInfo;
    public:
        void setLog(Example level)
        {
            m_logLevel = level;
        }
        void Error(const char *message)
        {
            if (m_logLevel >= logLevelError)
            {
                std::cout << "[ERROR] : " << message << std::endl;
            }
        }
        void Warning(const char *message)
        {
            if (m_logLevel >= logLevelWarning)
            {
                std::cout << "[WARNING] : " << message << std::endl;
            }
        }
        void Info(const char *message)
        {
            if (m_logLevel >= logLevelInfo)
            {
                std::cout << "[INFO] : " << message << std::endl;
            }
        }
};

int main(int argc, char const *argv[])
{
    Log log;
    // log.setLog(Log::logLevelError);
    log.Error("Hello!");
    log.Warning("Hello!");
    log.Info("Hello!");
    return 0;
}