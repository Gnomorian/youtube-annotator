#include "annotationlistitem.h"

AnnotationListItem::AnnotationListItem(const YoutubeVideoState& state, QListWidget* parent)
    : QListWidgetItem{"", parent}
    , myState{state}
{
    setText(QString{"%1"}.arg(myState.PlayerDuration()));
}
