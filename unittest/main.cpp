#include <QTest>
#include "tst_testgraph.cpp"
#include "tst_testlist.cpp"
#include "tst_testqueue.cpp"
#include "tst_teststack.cpp"

int main(int argc, char *argv[])
{
    TestStack test_stack;
    FooTests test2;
    BarTests test3;

    QTest.qExec(&test1);
    QTest.qExec(&test2);
    QTest.qExec(&test3);

    return 0;
}
