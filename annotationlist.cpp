#include "annotationlist.h"

AnnotationList::AnnotationList(QWidget *parent) : QListWidget(parent)
{

}

void AnnotationList::addAnnotation(YoutubeVideoState &data)
{
    auto newItem{std::make_unique<QListWidgetItem>(QString{"%1"}.arg(data.PlayerDuration()), this)};
    addItem(newItem.get());
    newItem.release();
}
