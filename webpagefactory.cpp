#include "webpagefactory.h"
#include <QFile>

const QString WebpageFactory::ConcreteTestPagePath{":/webpages/youtubeplayer/concrete-youtube-player.html"};

WebpageFactory::WebpageFactory()
{}

QString WebpageFactory::getTestPage()
{
    QFile page{ConcreteTestPagePath};
    page.open(QFile::OpenModeFlag::ReadOnly);
    return {std::move(page.readAll())};
}
