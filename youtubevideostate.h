#ifndef YOUTUBEVIDEOSTATE_H
#define YOUTUBEVIDEOSTATE_H

#include <QUrl>
#include <QChar>
#include <QMap>

/*!
 * an enum representing the youtube iframe api states
 * https://developers.google.com/youtube/iframe_api_reference#Playback_status
 */
enum IFrameVideoState
{
    Unstarted   = -1,
    Ended       = 0,
    Playing     = 1,
    Paused      = 2,
    Buffering   = 3,
    VideoCued   = 5
};



/*!
 * a structure for the YoutubePlayer to communicate the state of the video
 * that it is currently displaying.
 */
struct YoutubeVideoState
{
    using Seconds = int;
    //! maps property names to 0 based positions in a delimited string
    using StringPropertyMap = QMap<QString, QStringList::size_type>;
    YoutubeVideoState();
    YoutubeVideoState(const IFrameVideoState state, const Seconds duration, const QString& url);
    YoutubeVideoState(const int state, const Seconds duration, const QString& url);
    YoutubeVideoState(const YoutubeVideoState& copyFrom);
    YoutubeVideoState(YoutubeVideoState&& moveFrom);

    QString videoUrlAsString() const;

    //! default delimited string format
    const static StringPropertyMap defaultMapping;

    /*! factory method for making YoutubeVideoState structures from strings such as "property1;property2;property3"
     * the \a format is a mapping for YoutubeVideoState parameter names to numbers that represent positions in the
     * delimited string, e.g. for a delimited string of url;0;1 a map entry of "PlayerState":1 would imply that
     * the property PlayerState should be set to 0 (the second entry in the delimited string)
     */
    static YoutubeVideoState makeFromDelimitedString(const QString& data, const QChar delimiter, const StringPropertyMap& format = defaultMapping);

    const IFrameVideoState PlayerState;
    const Seconds PlayerDuration;
    const QUrl VideoUrl;
};

#endif // YOUTUBEVIDEOSTATE_H
