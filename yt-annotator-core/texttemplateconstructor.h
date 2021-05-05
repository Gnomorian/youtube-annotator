#ifndef TEXTTEMPLATECONSTRUCTOR_H
#define TEXTTEMPLATECONSTRUCTOR_H

#include "yt-annotator-core_global.h"
#include <QString>
#include <map>

/*!
 * \brief The TextTemplateConstructor class
 * takes a string with parameters like {{$paramName}}
 * user provides a map of params to substitutions via setSubstitution(param, substitution).
 * realiseTemplate() can then be called to create a string with the params replaced.
 */
class YTANNOTATORCORE_EXPORT TextTemplateConstructor
{
public:
    //! \param templateStr will be stored as a reference, so you cant use this class if templateStr has been deleted.
    explicit TextTemplateConstructor(const QString& templateStr);
    TextTemplateConstructor() = delete;
    void setSubstitution(const QString& paramName, const QString& substitution);
    QString realiseTemplate() const;
protected:
    QString serializeParamName(const QString& paramName) const;
private:
    const QString& templateStr{};
    std::map<QString, QString> substitutions{};
    const static QString ParamFormat;
};

#endif // TEXTTEMPLATECONSTRUCTOR_H
