#include "youtubevideostate.h"

YoutubeVideoState::YoutubeVideoState()
    : PlayerState{IFrameVideoState::Unstarted}
    , PlayerDuration{-1}
    , VideoUrl{}
{}
YoutubeVideoState::YoutubeVideoState(const IFrameVideoState state, const Seconds duration, const QString& url)
    : PlayerState{state}
    , PlayerDuration{duration}
    , VideoUrl{QUrl::fromUserInput(url)}
{}
YoutubeVideoState::YoutubeVideoState(const int state, const Seconds duration, const QString& url)
    : PlayerState{static_cast<IFrameVideoState>(state)}
    , PlayerDuration{duration}
    , VideoUrl{QUrl::fromUserInput(url)}
{}
YoutubeVideoState::YoutubeVideoState(const YoutubeVideoState& copyFrom)
    : PlayerState{copyFrom.PlayerState}
    , PlayerDuration{copyFrom.PlayerDuration}
    , VideoUrl{copyFrom.VideoUrl}
{}
YoutubeVideoState::YoutubeVideoState(YoutubeVideoState&& moveFrom)
    : PlayerState{moveFrom.PlayerState}
    , PlayerDuration{moveFrom.PlayerDuration}
    , VideoUrl{std::move(moveFrom.VideoUrl)}
{}
QString YoutubeVideoState::videoUrlAsString() const
{
    return VideoUrl.toString();
}

const YoutubeVideoState::StringPropertyMap YoutubeVideoState::defaultMapping
{
    {"PlayerState", 0},
    {"Duration", 1},
    {"VideoUrl", 2}
};

YoutubeVideoState YoutubeVideoState::makeFromDelimitedString(const QString& data, const QChar delimiter = ';', const StringPropertyMap& format)
{
    constexpr QStringList::size_type NumberOfProperties{3};
    auto splits{data.split(delimiter)};
    auto getPropertyIndex = [format, splits](const QString& propertyName)
    {
        return splits.at(format[propertyName]);
    };


    if(splits.size() != NumberOfProperties)
    {
        return YoutubeVideoState{};
    }

    const int PlayerState{getPropertyIndex("PlayerState").toInt()};
    const int Duration{getPropertyIndex("Duration").toInt()};
    const QString& VideoUrl{getPropertyIndex("VideoUrl")};

    return YoutubeVideoState{PlayerState, Duration, VideoUrl};
}
