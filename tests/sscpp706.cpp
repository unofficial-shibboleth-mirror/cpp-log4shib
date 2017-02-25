#include <iostream>
#include <exception>
#include <log4shib/Category.hh>
#include <log4shib/PropertyConfigurator.hh>

int main(int argc, char* argv[])
{
    if (argc < 2)
        return 1;

    std::string initFileName = argv[1];
    try {
        log4shib::PropertyConfigurator::configure(initFileName);
        log4shib::Category& root = log4shib::Category::getRoot();
        root.warn("Storm is coming");
        log4shib::Category::shutdown();
    } catch (const std::exception& ex) {
        std::cout << "Caught exception: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}