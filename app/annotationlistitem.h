#ifndef ANNOTATIONLISTITEM_H
#define ANNOTATIONLISTITEM_H

#include <QListWidgetItem>
#include "youtubevideostate.h"

class AnnotationListItem : public QListWidgetItem
{
public:
    AnnotationListItem(const YoutubeVideoState& state, QListWidget* parent);
    const YoutubeVideoState myState;
};

#endif // ANNOTATIONLISTITEM_H
