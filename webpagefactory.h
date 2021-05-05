#ifndef WEBPAGEFACTORY_H
#define WEBPAGEFACTORY_H

#include <QString>

class WebpageFactory
{
public:
    WebpageFactory();
    static QString getTestPage();
    static QString getYoutubePlayer(const QString& videoId);

    const static QString ConcreteTestPagePath;
    const static QString TemplatePagePath;
};

#endif // WEBPAGEFACTORY_H
