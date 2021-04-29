#include "annotationlist.h"
#include "annotationlistitem.h"

AnnotationList::AnnotationList(QWidget *parent) : QListWidget(parent)
{

}

void AnnotationList::addAnnotation(YoutubeVideoState &data)
{
    auto newItem{std::make_unique<AnnotationListItem>(data, this)};
    addItem(newItem.get());
    newItem.release();
}
