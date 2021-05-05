#include "webpagefactory.h"
#include <QFile>

const QString WebpageFactory::ConcreteTestPagePath{":/webpages/youtubeplayer/concrete-youtube-player.html"};
const QString WebpageFactory::TemplatePagePath{":/webpages/youtubeplayer/template-youtube-player.html"};

WebpageFactory::WebpageFactory()
{}

QString WebpageFactory::getTestPage()
{
    QFile page{ConcreteTestPagePath};
    page.open(QFile::OpenModeFlag::ReadOnly);
    return {std::move(page.readAll())};
}

QString WebpageFactory::getYoutubePlayer(const QString &videoId)
{
    const QString VideoIdParamName{"{{$videoId}}"};

    QFile page{TemplatePagePath};
    page.open(QFile::OpenModeFlag::ReadOnly);
    QString pageTemplate{std::move(page.readAll())};
    return std::move(pageTemplate.replace(VideoIdParamName, videoId));
}
