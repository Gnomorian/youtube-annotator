#include "texttemplateconstructor.h"

const QString TextTemplateConstructor::ParamFormat{"{{$%1}}"};

TextTemplateConstructor::TextTemplateConstructor(const QString &templateStr)
    : templateStr{templateStr}
{}

void TextTemplateConstructor::setSubstitution(const QString& paramName, const QString& substitution)
{
    substitutions[paramName] = substitution;
}

QString TextTemplateConstructor::realiseTemplate() const
{
    QString output{templateStr};
    for(const auto& [param, substitution] : substitutions)
    {
        output.replace(serializeParamName(param), substitution);
    }
    return output;
}

QString TextTemplateConstructor::serializeParamName(const QString &paramName) const
{
    return ParamFormat.arg(paramName);
}

