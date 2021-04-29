#include "youtubeplayer.h"
#include <QFile>
#include "webpagefactory.h"

YoutubePlayer::YoutubePlayer(QWidget *parent) : QWebEngineView(parent)
{
    connect(this, &QWebEngineView::titleChanged, this, [=](const QString& title){emit youtubeDataUpdated(YoutubeVideoState::makeFromDelimitedString(title, ';'));});
    setHtml(WebpageFactory::getTestPage(), QString{"youtubeplayer.html"});
    show();
}
