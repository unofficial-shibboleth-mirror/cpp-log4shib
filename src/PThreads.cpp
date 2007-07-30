#include <log4shib/threading/Threading.hh>

#if defined(LOG4SHIB_HAVE_THREADING) && defined(LOG4SHIB_USE_PTHREADS)

namespace log4shib {
    namespace threading {

        std::string getThreadId() {
            char buffer[16];
            ::sprintf(buffer, "%ld", pthread_self());
            return std::string(buffer);     
        }

    }
}

#endif // LOG4SHIB_HAVE_THREADING && LOG4SHIB_USE_PTHREADS
