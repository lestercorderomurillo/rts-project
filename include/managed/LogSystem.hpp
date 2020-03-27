 #ifndef RTS_LOGGING
 #define RTS_LOGGING

 #include <string>

 namespace RTS{

    class LogSystem{
      /*string       logPath;
      list<string> logData;*/

    public:
      LogSystem();

      void out(std::string);
      void out(int, std::string);
      int  reportToFile();

   };

 }

 #endif
