
#include "qtsqlex01.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTSQLEx01 w;
	w.show();
	return a.exec();
}


//#include <QCoreApplication>
//#include <QSqlDatabase>
//#include <QDebug>
//#include <QStringList>
//int main(int argc, char *argv[])
//{
//	QCoreApplication a(argc, argv);
//	qDebug() << "Available drivers:";
//	QStringList drivers = QSqlDatabase::drivers();
//	foreach(QString driver, drivers)
//		qDebug() << driver;
//	return a.exec();
//}

//#include <QCoreApplication>
//#include <QSqlDatabase>
//#include <QDebug>
//#include <QSqlQuery>
//
//int main(int argc, char *argv[])
//{
//	QCoreApplication a(argc, argv);
//
//	//添加数据库驱动
//	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//	//设置数据库名称
//	db.setDatabaseName(":memory:");
//	//打开数据库
//	if (!db.open())
//	{
//		return false;
//	}
//
//	//以下执行相关sql语句
//	QSqlQuery query;
//
//	//新建student表，id设置为主键，还有一个name项
//	query.exec("create table student(id int primary key,name varchar,score int)");
//
//	//向表中插入3条记录
//	query.exec("insert into student values(1,'Wolf',100)");
//	query.exec("insert into student values(2,'Phoebe',95)");
//	query.exec("insert into student values(3,'Ken',88)");
//
//	//查找表中id >=2 的记录的id项和name项的值
//	query.exec("select id,name,score from student where id >= 1");
//
//	//query.next()指向查找到的第一条记录，然后每次后移一条记录
//	while (query.next())
//	{
//		//query.value(0)是id的值，将其转换为int型
//		int value0 = query.value(0).toInt();
//		QString value1 = query.value(1).toString();
//		int value2 = query.value(2).toInt();
//		//输出两个值
//		qDebug() << value0 << value1 << value2;
//	}
//
//	return a.exec();
//}