#ifndef ANNOTATORTESTER_H
#define ANNOTATORTESTER_H

#include <QObject>

class AnnotatorTester : public QObject
{
    Q_OBJECT
public:
    explicit AnnotatorTester(QObject *parent = nullptr);

private slots:
    void initTestCase();
    void cleanupTestCase();
    // JavascriptParamBuilder tests
    void test_javascriptparambuilder_one_parameter();
    void test_javascriptparambuilder_string_parameters();
    void test_javascriptparambuilder_exception_on_non_convertable_string();
    void test_javascriptparambuilder_many_params();
    // TextTemplateConstructor tests
    void test_texttemplateconstructor_single_param();
    void test_texttemplateconstructor_multiple_params();
};

#endif // ANNOTATORTESTER_H
