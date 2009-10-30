/*
 * BasicConfigurator.cpp
 *
 * Copyright 2002, Log4cpp Project. All rights reserved.
 *
 * See the COPYING file for the terms of usage and distribution.
 */
#include "PortabilityImpl.hh"

#ifdef LOG4SHIB_HAVE_IO_H
#    include <io.h>
#endif
#ifdef LOG4SHIB_HAVE_UNISTD_H
#    include <unistd.h>
#endif

#include <cstdio>
#include <log4shib/BasicConfigurator.hh>
#include <log4shib/Category.hh>
#include <log4shib/FileAppender.hh>
#include <log4shib/Priority.hh>

namespace log4shib {

    void BasicConfigurator::configure() {
        Category& root = Category::getRoot();
        root.setPriority(Priority::INFO);
        root.removeAllAppenders();
        root.addAppender(new FileAppender("_", ::dup(fileno(stdout))));
    }

}



