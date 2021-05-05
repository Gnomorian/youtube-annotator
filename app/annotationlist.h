#ifndef ANNOTATIONLIST_H
#define ANNOTATIONLIST_H

#include <QListWidget>
#include "youtubevideostate.h"

/*!
 * \brief The AnnotationList class
 * a QWidget for displaying annotations for the
 * current video. provides signals for updates
 * to the list, actions etc.
 */
class AnnotationList : public QListWidget
{
    Q_OBJECT
public:
    explicit AnnotationList(QWidget *parent = nullptr);
    void addAnnotation(YoutubeVideoState& data);
signals:
    void annotationClicked(const YoutubeVideoState& annotation);
};

#endif // ANNOTATIONLIST_H
