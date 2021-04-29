#include "youtubeplayer.h"

const char webpage[]{R"(<!DOCTYPE html>
    <html>
      <body>
        <!-- 1. The <iframe> (and video player) will replace this <div> tag. -->
        <div id='player'></div>

        <script>
          // 2. This code loads the IFrame Player API code asynchronously.
          var tag = document.createElement('script');

          tag.src = 'http://www.youtube.com/iframe_api';
          var firstScriptTag = document.getElementsByTagName('script')[0];
          firstScriptTag.parentNode.insertBefore(tag, firstScriptTag);

          // 3. This function creates an <iframe> (and YouTube player)
          //    after the API code downloads.
          var player;
          function onYouTubeIframeAPIReady() {
            player = new YT.Player('player', {
              height: '390',
              width: '640',
              videoId: 'fTFTpvRMIJo',
              playerVars: {
                'playsinline': 1
              },
              events: {
                'onReady': onPlayerReady,
                'onStateChange': onPlayerStateChange
              }
            });
          }

          // The API will call this function when the video player is ready.
          function onPlayerReady(event) {
            setInterval(setTitleToVideoProgress, 500);
            event.target.playVideo();
          }

          function onPlayerStateChange(event) {
            if (event.data == YT.PlayerState.PAUSED) {
              setTitleToVideoProgress();
            }
          }

          function setTitleToVideoProgress() {
            var newTitle = 	player.getPlayerState() + ';' +
                            player.getDuration() + ';' +
                            player.getVideoUrl();
            document.title = newTitle;
          }
        </script>
      </body>
    </html>)"};

YoutubePlayer::YoutubePlayer(QWidget *parent) : QWebEngineView(parent)
{
    connect(this, &QWebEngineView::titleChanged, this, [=](const QString& title){emit youtubeDataUpdated(createFromTitle(title));});
    setHtml(QString{webpage}, QString{"youtubeplayer.html"});
    show();
}

YoutubeVideoState YoutubePlayer::createFromTitle(QString title)
{
    auto splits{title.split(';')};
    if(splits.size() != 3)
        return YoutubeVideoState(IFrameVideoState::Ended, 0, nullptr);
    const int PlayerState{splits.at(0).toInt()};
    const int Duration{splits.at(1).toInt()};
    const QString& VideoUrl{splits.at(2)};

    return YoutubeVideoState{PlayerState, Duration, VideoUrl};
}
