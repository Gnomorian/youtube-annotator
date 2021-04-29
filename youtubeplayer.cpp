#include "youtubeplayer.h"
#include <QFile>

YoutubePlayer::YoutubePlayer(QWidget *parent) : QWebEngineView(parent)
{
    connect(this, &QWebEngineView::titleChanged, this, [=](const QString& title){emit youtubeDataUpdated(YoutubeVideoState::makeFromDelimitedString(title, ';'));});
    QFile page{":/webpages/youtubeplayer/concrete-youtube-player.html"};
    page.open(QFile::OpenModeFlag::ReadOnly);
    setHtml(QString{std::move(page.readAll())}, QString{"youtubeplayer.html"});
    show();
}
