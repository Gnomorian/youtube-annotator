#ifndef JAVASCRIPTSOURCEBUILDERTEST_H
#define JAVASCRIPTSOURCEBUILDERTEST_H

#include <QObject>

class TestJavascriptBuilder : public QObject
{
    Q_OBJECT
public:
    explicit TestJavascriptBuilder(QObject *parent = nullptr);
private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_one_parameter();
    void test_string_parameters();
    void test_non_string_param_cause_exception();
    void test_many_params();
};

#endif // JAVASCRIPTSOURCEBUILDERTEST_H
