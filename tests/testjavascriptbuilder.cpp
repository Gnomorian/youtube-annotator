#include "testjavascriptbuilder.h"
#include "javascriptparambuilder.h"
#include <QtTest>

TestJavascriptBuilder::TestJavascriptBuilder(QObject *parent) : QObject(parent)
{

}

void TestJavascriptBuilder::initTestCase()
{

}

void TestJavascriptBuilder::cleanupTestCase()
{

}

void TestJavascriptBuilder::test_one_parameter()
{
    QString script{JavascriptParamBuilder{}
                .setMethodname("methodName")
                .addParam(1)
                .makeScript()
    };
    QVERIFY(script == QString{"methodName(1);"});
}

void TestJavascriptBuilder::test_string_parameters()
{
    JavascriptParamBuilder builder;
    QString script{builder.addParam("true").setMethodname("hasStringInQuotes").makeScript()};
    QCOMPARE(script, QString{"hasStringInQuotes(\"true\");"});
}

void TestJavascriptBuilder::test_non_string_param_cause_exception()
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

void TestJavascriptBuilder::test_many_params()
{
    const QString ActualScript{R"(object.myfunc("param1", 2, 3);)"};
    JavascriptParamBuilder builder;
    builder.setMethodname("object.myfunc").addParam("param1").addParam(2).addParam(3);
    const auto script{builder.makeScript()};
    QVERIFY2(script == ActualScript, qPrintable(script));
}
