#include <iostream>
#include <string>
using namespace std;

enum LogLevel {
    DEBUG = 0,
    INFO = 1,
    WARNING = 2,
    ERROR = 3
};

class Logger {
    // implement your code
public:
    Logger(int level): logLevel(level) { }
    ~Logger(){logLevel=1;}
    static void setLogLevel(int level);
    static void debug(const string&, const string&);
    static void info(const string&, const string&);
    static void warning(const string&, const string&);
    static void error(const string&, const string&);
private:
    static int logLevel;
};
