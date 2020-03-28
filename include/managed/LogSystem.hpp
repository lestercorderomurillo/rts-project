 #ifndef RTS_LOGGING
 #define RTS_LOGGING

 #include <string>

 namespace RTS{

    class LogSystem{
    private:
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
