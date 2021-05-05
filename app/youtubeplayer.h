#ifndef YOUTUBEPLAYER_H
#define YOUTUBEPLAYER_H

#include <QWebEngineView>
#include <optional>
#include "youtubevideostate.h"

class YoutubePlayer : public QWebEngineView
{
    Q_OBJECT
public:
    explicit YoutubePlayer(QWidget *parent = nullptr);
    void setVideo(const QString& videoId, std::optional<int> startDuration = std::optional<int>{}, std::optional<int> endDuration = std::optional<int>{});
signals:
    void youtubeDataUpdated(const YoutubeVideoState& data);
};

#endif // YOUTUBEPLAYER_H
