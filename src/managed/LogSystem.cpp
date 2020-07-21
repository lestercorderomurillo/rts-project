#include "managed/LogSystem.hpp"
#include "managed/ColorUtils.hpp"

using namespace std;

namespace RTS{

    LogSystem::LogSystem(){
      this->logFile.open("logs/output.log");
      out(2, PROJECTNAME);
    }

    LogSystem::~LogSystem(){
      this->logFile.close();
    }

    void LogSystem::out(string message){
      out(0, message);
    }

    void LogSystem::out(int level, string message){
      switch (level) {
        case 0: cout << " * " << message << endl; break;
        case 1: cout << YEL << " * " << message << WHT << endl; break;
        case 2: cout << RED << " * " << message << WHT << endl; break;
      }
      if (logFile.is_open()){
        logFile << " * " << message << endl; 
      }

    }

 }
