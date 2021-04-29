#ifndef YOUTUBEANNOTATIONSTORE_H
#define YOUTUBEANNOTATIONSTORE_H

#include <QObject>
#include "youtubevideostate.h"

class YoutubeAnnotationStore : public QObject
{
    Q_OBJECT
public:
    explicit YoutubeAnnotationStore()
        : QObject{nullptr}
    {}
    virtual ~YoutubeAnnotationStore() = default;

    virtual void addAnnotation(const YoutubeVideoState& annotation) = 0;
    virtual void removeAnnotation(const YoutubeVideoState& annotation) = 0;
    virtual QList<YoutubeVideoState> collateAnnotationsByVideoId(const QString& videoId) const = 0;
    virtual QList<QString> collateAnnotatedVideoIds() = 0;
    virtual QList<QUrl> collateAnnotatedVideoUrls() = 0;
signals:
    //! emmitted when addAnnotation or removeAnnotation is called somewhere.
    void annotationsUpdated();

};

extern std::unique_ptr<YoutubeAnnotationStore> makeMemoryYoutubeAnnotationStore();

#endif // YOUTUBEANNOTATIONSTORE_H
