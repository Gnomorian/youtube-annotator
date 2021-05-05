#ifndef TESTTEXTTEMPLATEBUILDER_H
#define TESTTEXTTEMPLATEBUILDER_H

#include <QObject>

class TestTextTemplateBuilder : public QObject
{
    Q_OBJECT
public:
    explicit TestTextTemplateBuilder(QObject *parent = nullptr);

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_single_param();
    void test_multiple_params();
};

#endif // TESTTEXTTEMPLATEBUILDER_H
