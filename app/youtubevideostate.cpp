#include "youtubevideostate.h"

YoutubeVideoState::YoutubeVideoState()
    : _PlayerState{IFrameVideoState::Unstarted}
    , _PlayerDuration{-1}
    , _VideoUrl{}
{}
YoutubeVideoState::YoutubeVideoState(const IFrameVideoState state, const Seconds duration, const QString& url)
    : _PlayerState{state}
    , _PlayerDuration{duration}
    , _VideoUrl{QUrl::fromUserInput(url)}
{}
YoutubeVideoState::YoutubeVideoState(const int state, const Seconds duration, const QString& url)
    : _PlayerState{static_cast<IFrameVideoState>(state)}
    , _PlayerDuration{duration}
    , _VideoUrl{QUrl::fromUserInput(url)}
{}
YoutubeVideoState::YoutubeVideoState(const YoutubeVideoState& copyFrom)
    : _PlayerState{copyFrom._PlayerState}
    , _PlayerDuration{copyFrom._PlayerDuration}
    , _VideoUrl{copyFrom._VideoUrl}
{}
YoutubeVideoState::YoutubeVideoState(YoutubeVideoState&& moveFrom)
    : _PlayerState{moveFrom._PlayerState}
    , _PlayerDuration{moveFrom._PlayerDuration}
    , _VideoUrl{std::move(moveFrom._VideoUrl)}
{}

YoutubeVideoState& YoutubeVideoState::operator=(const YoutubeVideoState &copyAssignFrom)
{
    if(this != &copyAssignFrom)
    {
        _PlayerState = copyAssignFrom._PlayerState;
        _PlayerDuration = copyAssignFrom._PlayerDuration;
        _VideoUrl = copyAssignFrom._VideoUrl;
    }
    return *this;
}
QString YoutubeVideoState::videoUrlAsString() const
{
    return _VideoUrl.toString();
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

IFrameVideoState YoutubeVideoState::PlayerState() const
{
    return _PlayerState;
}

YoutubeVideoState::Seconds YoutubeVideoState::PlayerDuration() const
{
    return _PlayerDuration;
}

const QUrl &YoutubeVideoState::VideoUrl() const
{
    return _VideoUrl;
}
