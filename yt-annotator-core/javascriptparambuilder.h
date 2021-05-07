#ifndef JAVASCRIPTPARAMBUILDER_H
#define JAVASCRIPTPARAMBUILDER_H

#include "yt-annotator-core_global.h"
#include <QString>
#include <QList>
#include <QVariant>

class YTANNOTATORCORE_EXPORT JavascriptParamBuilder
{
public:
    JavascriptParamBuilder();
    JavascriptParamBuilder& setMethodname(const QString& methodName);
    JavascriptParamBuilder& addParam(const QVariant& param);
    QString makeScript();

    const static std::string ToStringErrorMessage;
private:
    QString methodName;
    QList<QVariant> paramlist;
};

#endif // JAVASCRIPTPARAMBUILDER_H
