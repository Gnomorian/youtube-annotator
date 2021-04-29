#ifndef WEBPAGEFACTORY_H
#define WEBPAGEFACTORY_H

#include <QString>

class WebpageFactory
{
public:
    WebpageFactory();
    static QString getTestPage();

    const static QString ConcreteTestPagePath;
};

#endif // WEBPAGEFACTORY_H
