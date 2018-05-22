/*
 * NTEventLogAppender.hh
 *
 * See the COPYING file for the terms of usage and distribution.
 */

#ifndef _LOG4SHIB_NTEVENTLOGAPPENDER_HH
#define _LOG4SHIB_NTEVENTLOGAPPENDER_HH

#ifdef WIN32	// only available on Win32

// deal with ERROR #define
// N.B. This #includes windows.h with NOGDI and WIN32_LEAN_AND_MEAN #defined.
//      If this is not what the user wants, #include windows.h before this file.
#ifndef _WINDOWS_
#  ifndef NOGDI
#    define NOGDI  // this will circumvent the ERROR #define in windows.h
#    define LOG4SHIB_UNDEFINE_NOGDI
#  endif

#  ifndef WIN32_LEAN_AND_MEAN
#    define WIN32_LEAN_AND_MEAN
#    define LOG4SHIB_UNDEFINE_WIN32_LEAN_AND_MEAN
#  endif

#  include <windows.h>

#  ifdef LOG4SHIB_UNDEFINE_NOGDI
#    undef NOGDI
#  endif

#  ifdef LOG4SHIB_UNDEFINE_WIN32_LEAN_AND_MEAN
#    undef WIN32_LEAN_AND_MEAN
#  endif

#endif // done dealing with ERROR #define

#include <log4shib/Portability.hh>
#include <log4shib/LayoutAppender.hh>

namespace log4shib {

    /**
     * NTEventLogAppender is an Appender that sends LoggingEvents to the 
     * Windows event log.
     * Building log4shib.dsp/log4shibDLL.dsp creates the resource DLL NTEventLogAppender.dll.
     * Do not forget to place this DLL in a directory that is on the PATH 
     * of the Windows system. Otherwise, the category and message will not display 
     * correctly in Event Viewer.<BR>
     * <B>NB:</B> This class is only available on Win32 platforms.
     **/
    class LOG4SHIB_EXPORT NTEventLogAppender : public LayoutAppender {
    public:

        /**
         * Instantiate an NTEventLogAppender with given name and source.
         * @param name The name of the Appender
         * @param sourceName The source name to log
         **/         
        NTEventLogAppender(const std::string& name, const std::string& sourceName);
        virtual ~NTEventLogAppender();

        /**
         * Calls open() and close()
         **/
        virtual bool reopen();

        virtual void close();

    protected:
        
        WORD getCategory(Priority::Value priority);
        WORD getType(Priority::Value priority);
        HKEY regGetKey(TCHAR *subkey, DWORD *disposition);
        void regSetString(HKEY hkey, const TCHAR *name, const TCHAR *value);
        void regSetDword(HKEY hkey, const TCHAR *name, DWORD value);
        void addRegistryInfo(const char *source);

        virtual void open();

        /**
         * Sends a LoggingEvent to NT Event log.
         * @param event the LoggingEvent to log.
         **/
        virtual void _append(const LoggingEvent& event);

    	HANDLE _hEventSource;
        std::string _strSourceName;
    };
}

#else // WIN32
#error NTEventLoggAppender is not available on on Win32 platforms
#endif	// WIN32

#endif // _LOG4SHIB_NTEVENTLOGAPPENDER_HH

