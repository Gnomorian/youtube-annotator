#ifndef YOUTUBEPLAYER_H
#define YOUTUBEPLAYER_H

#include <QWebEngineView>
#include "youtubevideostate.h"

class YoutubePlayer : public QWebEngineView
{
    Q_OBJECT
public:
    explicit YoutubePlayer(QWidget *parent = nullptr);
signals:
    void youtubeDataUpdated(const YoutubeVideoState& data);
};

#endif // YOUTUBEPLAYER_H
