#include "youtubeannotationstore.h"
#include <set>

struct YoutubeVideoStateLess
{
    bool operator()( const YoutubeVideoState& lhs, const YoutubeVideoState& rhs ) const
    {
        return lhs.VideoUrl() < rhs.VideoUrl()
                && lhs.PlayerDuration() < rhs.PlayerDuration();
    }
};

class MemoryAnnotationStore : public YoutubeAnnotationStore
{
    std::set<YoutubeVideoState, YoutubeVideoStateLess> annotations;
    // YoutubeAnnotationStore interface
public:
    void addAnnotation(const YoutubeVideoState &annotation)
    {}
    void removeAnnotation(const YoutubeVideoState &annotation)
    {}
    QList<YoutubeVideoState> collateAnnotationsByVideoId(const QString &videoId) const
    {
        return {};
    }
    QList<QString> collateAnnotatedVideoIds()
    {
        return {};
    }
    QList<QUrl> collateAnnotatedVideoUrls()
    {
        return {};
    }
};

std::unique_ptr<YoutubeAnnotationStore> makeMemoryYoutubeAnnotationStore()
{
    return std::make_unique<MemoryAnnotationStore>();
}
