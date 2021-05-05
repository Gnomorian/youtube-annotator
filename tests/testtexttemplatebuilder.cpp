#include "testtexttemplatebuilder.h"
#include "texttemplateconstructor.h"
#include <QtTest>

TestTextTemplateBuilder::TestTextTemplateBuilder(QObject *parent) : QObject(parent)
{

}

void TestTextTemplateBuilder::initTestCase()
{

}

void TestTextTemplateBuilder::cleanupTestCase()
{

}

void TestTextTemplateBuilder::test_single_param()
{
    TextTemplateConstructor constructor{R"(this is a {{$template}})"};
    const QString expected{"this is a real string"};
    constructor.setSubstitution("template", "real string");
    const QString actual{constructor.realiseTemplate()};
    QCOMPARE(actual, expected);
}

void TestTextTemplateBuilder::test_multiple_params()
{
    TextTemplateConstructor constructor{R"({{$param1}} in {{$param1}} in {{$param2}} then in {{$param1}})"};
    const QString expected{"box in box in not-box then in box"};
    constructor.setSubstitution("param1", "box");
    constructor.setSubstitution("param2", "not-box");
    const QString actual{constructor.realiseTemplate()};
    QCOMPARE(actual, expected);
}
