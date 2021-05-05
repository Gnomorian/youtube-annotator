#include "javascriptparambuilder.h"

JavascriptParamBuilder::JavascriptParamBuilder()
{}

JavascriptParamBuilder &JavascriptParamBuilder::setMethodname(const QString &methodName)
{
    this->methodName = methodName;
    return *this;
}

JavascriptParamBuilder &JavascriptParamBuilder::addParam(const QVariant& param)
{
    if(!param.canConvert<QString>())
        throw std::exception{"parameter must be convertable to string"};
    paramlist.append(param);
    return *this;
}

QString JavascriptParamBuilder::makeScript()
{
    QString script{methodName + "("};
    bool isFirstParam{true};
    for(const auto& param : paramlist)
    {
        QString paramAsString{[&]()
            {
                if(param.type() == QVariant::Type::String)
                {
                    return QString{"\"%1\""}.arg(param.toString());
                }
                else
                {
                    return param.toString();
                }
            }()
        };
        if(isFirstParam)
        {
            script.append(paramAsString);
            isFirstParam = false;
        }
        else
        {
            script.append(", " + paramAsString);
        }
    }
    script.append(");");
    return script;
}
