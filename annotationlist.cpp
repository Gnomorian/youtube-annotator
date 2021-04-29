#include "annotationlist.h"
#include "annotationlistitem.h"

AnnotationList::AnnotationList(QWidget *parent) : QListWidget(parent)
{
    connect(
        this,
        &QListWidget::itemActivated,
        this,
        [=](const QListWidgetItem* item)
        {
            emit annotationClicked(dynamic_cast<const AnnotationListItem*>(item)->myState);
        }
    );
}

void AnnotationList::addAnnotation(YoutubeVideoState &data)
{
    auto newItem{std::make_unique<AnnotationListItem>(data, this)};
    addItem(newItem.get());
    newItem.release();
}
