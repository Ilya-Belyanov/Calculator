#include <QtWidgets>
#include <QtTest/QtTest>
#include "../calculator.cpp"

class TestGui: public QObject
{
    Q_OBJECT

private slots:
    void testGui();
    void testSumm();
    void testRound();
    void testDeleteUnnes();

};


void TestGui::testGui()
{
    QLineEdit lineEdit;
    QTest::keyClicks(&lineEdit, "hello world");
    QCOMPARE(lineEdit.text(), QString("hello world"));
}

void TestGui::testSumm()
{
    Calculator c;
    QCOMPARE(c.calcAll(QString("1+1-")), QString("2"));
    QCOMPARE(c.calcAll(QString("1+1-0")), QString("2"));
    QCOMPARE(c.calcAll(QString("1+1x6")), QString("7"));
    QCOMPARE(c.calcAll(QString("1/0")), QString("0"));
    QCOMPARE(c.calcAll(QString("1*0")), QString("0"));
    QCOMPARE(c.calcAll(QString("17-5x6/3-2+4/2")), QString("7"));
}

void TestGui::testRound()
{
    Calculator c;
    QCOMPARE(c.calcAll(QString("0.00000")), QString("0"));
    QCOMPARE(c.calcAll(QString("0.005")), QString("0.01"));
    QCOMPARE(c.calcAll(QString("0.004")), QString("0"));
    QCOMPARE(c.calcAll(QString("2.455")), QString("2.46"));

}

void TestGui::testDeleteUnnes()
{
    Calculator c;
    QCOMPARE(c.calcAll(QString("0.")), QString("0"));
    QCOMPARE(c.calcAll(QString("0.005+")), QString("0.01"));
    QCOMPARE(c.calcAll(QString("0.004-")), QString("0"));
    QCOMPARE(c.calcAll(QString("2.455+0")), QString("2.46"));

}

QTEST_MAIN(TestGui)
#include "test.moc"
