#include <QtTest>
#include <QCoreApplication>

#include "../structs/templates/stack.hpp"

class TestStack : public QObject
{
    Q_OBJECT
    Stack<float> stack;
public:
    TestStack();
    ~TestStack();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testCasePushItem();
    void testCasePopItem();
};

TestStack::TestStack() {}

TestStack::~TestStack() {}

void TestStack::initTestCase() {}

void TestStack::cleanupTestCase() {}

void TestStack::testCasePushItem()
{
    stack.push(9);
    stack.push(5.55454);
    stack.push(1.4);
    stack.push(9.1574);
    stack.push(25.74);
}

void TestStack::testCasePopItem()
{
    auto top = stack.top();
    stack.pop();
    stack.pop();
    top = stack.pop();
    stack.pop();
}

//QTEST_MAIN(TestStack)

#include "tst_teststack.moc"
