#include "youtubeplayer.h"
#include <QFile>
#include "webpagefactory.h"
#include "javascriptparambuilder.h"

YoutubePlayer::YoutubePlayer(QWidget *parent) : QWebEngineView(parent)
{
    connect(this, &QWebEngineView::titleChanged, this, [=](const QString& title){emit youtubeDataUpdated(YoutubeVideoState::makeFromDelimitedString(title, ';'));});
    setHtml(WebpageFactory::getYoutubePlayer("zv-3EfC17Rc"), QString{"youtubeplayer.html"});
    show();
}

void YoutubePlayer::setVideo(const QString& videoId, std::optional<int> startDuration, std::optional<int> endDuration)
{
    //TODO: replace with JavascriptParamBuilder class
    JavascriptParamBuilder scriptBuilder;
    scriptBuilder.setMethodname("player.loadVideoById").addParam(videoId);
    if(startDuration.has_value())
        scriptBuilder.addParam(startDuration.value());
    if(startDuration.has_value() && endDuration.has_value())
        scriptBuilder.addParam(endDuration.value());
    const QString script{scriptBuilder.makeScript()};
    qInfo(script.toStdString().data());
    page()->runJavaScript(script);
}
