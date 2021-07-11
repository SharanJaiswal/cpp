#include <iostream>
class Log
{
    public:
        const int logLevelError = 0;
        const int logLevelWarning = 1;
        const int logLevelInfo = 2;
    
    private:
        int m_logLevel = logLevelInfo;

    public:
        void setLevel(int level)
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

int main() {
    Log log;
    log.setLevel(log.logLevelInfo);
    log.Error("Hello!");
    log.Warning("Hello!");
    log.Info("Hello!");

    return 0;
}