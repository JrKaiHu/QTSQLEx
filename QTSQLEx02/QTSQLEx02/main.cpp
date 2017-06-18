#include <QtWidgets/QApplication>

#include <QtSql/QtSql>
#include <QtDebug>

#include <stdlib.h>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	// Create connection
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); // The second para can set to connection name, this is by default.

	db.setDatabaseName("./testdatabase.db");// Set database name and path
	// Open connection
	if (!db.open())
	{
		qDebug() << db.lastError();
		qFatal("Failed to connect.");
	}

	qDebug("Connected!");

	// Any kind of operation
	QSqlQuery qry;

	// Create table
	qry.prepare("CREATE TABLE IF NOT EXISTS names (id INTEGER UNIQUE PRIMARY KEY, firstname VARCHAR(30), lastname VARCHAR(30))");
	if (!qry.exec())
		qDebug() << qry.lastError();
	else
		qDebug() << "Table created!";

	// Add 
	qry.prepare("INSERT INTO names (id, firstname, lastname) VALUES (1, 'John', 'Doe')");
	if (!qry.exec())
		qDebug() << qry.lastError();
	else
		qDebug("Inserted!");

	qry.prepare("INSERT INTO names (id, firstname, lastname) VALUES (2, 'Jane', 'Doe')");
	if (!qry.exec())
		qDebug() << qry.lastError();
	else
		qDebug("Inserted!");

	qry.prepare("INSERT INTO names (id, firstname, lastname) VALUES (3, 'James', 'Doe')");
	if (!qry.exec())
		qDebug() << qry.lastError();
	else
		qDebug("Inserted!");

	qry.prepare("INSERT INTO names (id, firstname, lastname) VALUES (4, 'Judy', 'Doe')");
	if (!qry.exec())
		qDebug() << qry.lastError();
	else
		qDebug("Inserted!");

	qry.prepare("INSERT INTO names (id, firstname, lastname) VALUES (5, 'Richard', 'Roe')");
	if (!qry.exec())
		qDebug() << qry.lastError();
	else
		qDebug("Inserted!");

	qry.prepare("INSERT INTO names (id, firstname, lastname) VALUES (6, 'Jane', 'Roe')");
	if (!qry.exec())
		qDebug() << qry.lastError();
	else
		qDebug("Inserted!");

	qry.prepare("INSERT INTO names (id, firstname, lastname) VALUES (7, 'John', 'Noakes')");
	if (!qry.exec())
		qDebug() << qry.lastError();
	else
		qDebug("Inserted!");

	qry.prepare("INSERT INTO names (id, firstname, lastname) VALUES (8, 'Donna', 'Doe')");
	if (!qry.exec())
		qDebug() << qry.lastError();
	else
		qDebug("Inserted!");

	qry.prepare("INSERT INTO names (id, firstname, lastname) VALUES (9, 'Ralph', 'Roe')");
	if (!qry.exec())
		qDebug() << qry.lastError();
	else
		qDebug("Inserted!");

	//Query
	qry.prepare("SELECT * FROM names");
	if (!qry.exec())
		qDebug() << qry.lastError();
	else
	{
		qDebug("Selected!");

		QSqlRecord rec = qry.record();

		int cols = rec.count();

		for (int c = 0; c<cols; c++)
			qDebug() << QString("Column %1: %2").arg(c).arg(rec.fieldName(c));

		for (int r = 0; qry.next(); r++)
		for (int c = 0; c<cols; c++)
			qDebug() << QString("Row %1, %2: %3").arg(r).arg(rec.fieldName(c)).arg(qry.value(c).toString());
	}


	qry.prepare("SELECT firstname, lastname FROM names WHERE lastname = 'Roe'");
	if (!qry.exec())
		qDebug() << qry.lastError();
	else
	{
		qDebug("Selected!");

		QSqlRecord rec = qry.record();

		int cols = rec.count();

		for (int c = 0; c<cols; c++)
			qDebug() << QString("Column %1: %2").arg(c).arg(rec.fieldName(c));

		for (int r = 0; qry.next(); r++)
		for (int c = 0; c<cols; c++)
			qDebug() << QString("Row %1, %2: %3").arg(r).arg(rec.fieldName(c)).arg(qry.value(c).toString());
	}


	qry.prepare("SELECT firstname, lastname FROM names WHERE lastname = 'Roe' ORDER BY firstname");
	if (!qry.exec())
		qDebug() << qry.lastError();
	else
	{
		qDebug("Selected!");

		QSqlRecord rec = qry.record();

		int cols = rec.count();

		for (int c = 0; c<cols; c++)
			qDebug() << QString("Column %1: %2").arg(c).arg(rec.fieldName(c));

		for (int r = 0; qry.next(); r++)
		for (int c = 0; c<cols; c++)
			qDebug() << QString("Row %1, %2: %3").arg(r).arg(rec.fieldName(c)).arg(qry.value(c).toString());
	}


	qry.prepare("SELECT lastname, COUNT(*) as 'members' FROM names GROUP BY lastname ORDER BY lastname");
	if (!qry.exec())
		qDebug() << qry.lastError();
	else
	{
		qDebug("Selected!");

		QSqlRecord rec = qry.record();

		int cols = rec.count();

		for (int c = 0; c<cols; c++)
			qDebug() << QString("Column %1: %2").arg(c).arg(rec.fieldName(c));

		for (int r = 0; qry.next(); r++)
		for (int c = 0; c<cols; c++)
			qDebug() << QString("Row %1, %2: %3").arg(r).arg(rec.fieldName(c)).arg(qry.value(c).toString());
	}

	// Update
	qry.prepare("UPDATE names SET firstname = 'Nisse', lastname = 'Svensson' WHERE id = 7");
	if (!qry.exec())
		qDebug() << qry.lastError();
	else
		qDebug("Updated!");

	qry.prepare("UPDATE names SET lastname = 'Johnson' WHERE firstname = 'Jane'");
	if (!qry.exec())
		qDebug() << qry.lastError();
	else
		qDebug("Updated!");

	// Delete
	qry.prepare("DELETE FROM names WHERE id = 7");
	if (!qry.exec())
		qDebug() << qry.lastError();
	else
		qDebug("Deleted!");

	qry.prepare("DELETE FROM names WHERE lastname = 'Johnson'");
	if (!qry.exec())
		qDebug() << qry.lastError();
	else
		qDebug("Deleted!");


	db.close();

	system("Pause");

	return 0;
}