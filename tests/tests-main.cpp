#include <QtTest>
#include <QCoreApplication>
#include "testjavascriptbuilder.h"
#include "testtexttemplatebuilder.h"

int main(int argc, char** argv)
{
   int status = 0;
   auto ASSERT_TEST = [&status, argc, argv](QObject* obj) {
     status |= QTest::qExec(obj, argc, argv);
     delete obj;
   };

   ASSERT_TEST(new TestJavascriptBuilder());
   ASSERT_TEST(new TestTextTemplateBuilder());

   return status;
}
