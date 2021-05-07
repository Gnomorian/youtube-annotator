#include "annotatortester.h"
#include "javascriptparambuilder.h"
#include "texttemplateconstructor.h"
#include <QtTest>

AnnotatorTester::AnnotatorTester(QObject *parent) : QObject(parent)
{

}

void AnnotatorTester::initTestCase()
{

}

void AnnotatorTester::cleanupTestCase()
{

}

void AnnotatorTester::test_javascriptparambuilder_one_parameter()
{
    QString script{JavascriptParamBuilder{}
                .setMethodname("methodName")
                .addParam(1)
                .makeScript()
    };
    QVERIFY(script == QString{"methodName(1);"});
}

void AnnotatorTester::test_javascriptparambuilder_string_parameters()
{
    JavascriptParamBuilder builder;
    QString script{builder.addParam("true").setMethodname("hasStringInQuotes").makeScript()};
    QCOMPARE(script, QString{"hasStringInQuotes(\"true\");"});
}

void AnnotatorTester::test_javascriptparambuilder_exception_on_non_convertable_string()
{
    bool exceptionCaused{false};
    try
    {
        JavascriptParamBuilder builder;
        builder.addParam(QModelIndex{});
    }
    catch (std::exception& e)
    {
        QCOMPARE(e.what(), JavascriptParamBuilder::ToStringErrorMessage);
        exceptionCaused = true;
    }
    QVERIFY(exceptionCaused);
}

void AnnotatorTester::test_javascriptparambuilder_many_params()
{
    const QString ActualScript{R"(object.myfunc("param1", 2, 3);)"};
    JavascriptParamBuilder builder;
    builder.setMethodname("object.myfunc").addParam("param1").addParam(2).addParam(3);
    const auto script{builder.makeScript()};
    QVERIFY2(script == ActualScript, qPrintable(script));
}

void AnnotatorTester::test_texttemplateconstructor_single_param()
{
    const QString templateStr{R"(this is a {{$template}})"};
    TextTemplateConstructor constructor{templateStr};
    const QString expected{"this is a real string"};
    constructor.setSubstitution("template", "real string");
    const QString actual{constructor.realiseTemplate()};
    QVERIFY(actual == expected);
}

void AnnotatorTester::test_texttemplateconstructor_multiple_params()
{
    const QString templateStr{R"({{$param1}} in {{$param1}} in {{$param2}} then in {{$param1}})"};
    TextTemplateConstructor constructor{templateStr};
    const QString expected{"box in box in not-box then in box"};
    constructor.setSubstitution("param1", "box");
    constructor.setSubstitution("param2", "not-box");
    const QString actual{constructor.realiseTemplate()};
    QVERIFY(actual == expected);
}
