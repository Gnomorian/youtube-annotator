#ifndef JAVASCRIPTPARAMBUILDER_H
#define JAVASCRIPTPARAMBUILDER_H

#include <QString>
#include <QList>
#include <QVariant>

class JavascriptParamBuilder
{
public:
    JavascriptParamBuilder();
    JavascriptParamBuilder& setMethodname(const QString& methodName);
    JavascriptParamBuilder& addParam(const QVariant& param);
    QString makeScript();
private:
    QString methodName;
    QList<QVariant> paramlist;
};

#endif // JAVASCRIPTPARAMBUILDER_H
