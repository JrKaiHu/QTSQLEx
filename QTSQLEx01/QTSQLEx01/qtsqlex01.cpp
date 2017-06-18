#include "qtsqlex01.h"
#include <QtSql/QtSql>

#include <QApplication>
#include <QDesktopWidget>


QTSQLEx01::QTSQLEx01(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	list <SCORE_LIST> scoreList;

	QStringList IDList;

	int nCol = 0; 
	int nRow = 0;
	//int nScoreMaxIndex = 0;

	QSqlQueryModel *pModel = new QSqlQueryModel;

	DBConnection(IDList, nCol, nRow, scoreList, pModel);

	//QTableView *view = new QTableView;
	ui.scoreTV->setModel(pModel);
	ui.scoreTV->verticalHeader()->setVisible(false);
	ui.scoreTV->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.scoreTV->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.scoreTV->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.scoreTV->setShowGrid(true);
	ui.scoreTV->setStyleSheet("QTableView {selection-background-color: red;}");
	ui.scoreTV->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.scoreTV->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	//qDebug() << "Number of Rows: " << nRow;
	//qDebug() << "Number of columns: " << nCol;

	ui.scoreTW->setRowCount(nRow);
	ui.scoreTW->setColumnCount(3);

	QStringList m_TableHeader;
	m_TableHeader << "ID" << "Name" << "Score";
	ui.scoreTW->setHorizontalHeaderLabels(m_TableHeader);
	ui.scoreTW->verticalHeader()->setVisible(false);
	ui.scoreTW->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.scoreTW->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.scoreTW->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.scoreTW->setShowGrid(true);
	ui.scoreTW->setStyleSheet("QTableView {selection-background-color: red;}");
	//ui.scoreTW->setGeometry(QApplication::desktop()->screenGeometry());
	//ui.scoreTW->horizontalHeader()->setStretchLastSection(true);
	ui.scoreTW->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.scoreTW->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	int i = 0;

	for (auto scoreListItem:scoreList) {

		QTableWidgetItem *IDItem = new QTableWidgetItem(QString::number(scoreListItem.nID));
		IDItem->setTextAlignment(Qt::AlignCenter);

		QTableWidgetItem *NameItem = new QTableWidgetItem(scoreListItem.strName);
		NameItem->setTextAlignment(Qt::AlignCenter);

		QTableWidgetItem *ScoreItem = new QTableWidgetItem(QString::number(scoreListItem.nScore));
		ScoreItem->setTextAlignment(Qt::AlignCenter);

		ui.scoreTW->setItem(i, 0, IDItem);
		ui.scoreTW->setItem(i, 1, NameItem);
		ui.scoreTW->setItem(i, 2, ScoreItem);
		i++;
	}
}

QTSQLEx01::~QTSQLEx01()
{

}

bool QTSQLEx01::DBConnection(QStringList &IDList, int &nCol, int &nRow, list <SCORE_LIST> &scoreList, QSqlQueryModel *pModel)
{
	// 
	// QSqlQuery::prepare() 函數對這條SQL語句進行預處理
	// QSqlQuery::exec() 執行SQL語句


	QSqlDatabase db;
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("ScoreList");
	if (db.open())
	{
		/*QSqlQuery query("Select ID from Score_List");
		while (query.next())
		{
			QString strID = query.value(0).toString().trimmed();
			qDebug() << strID;
			IDList.append(strID);
		}*/

		//query.exec("insert into Score_List values(5,'Egg',81)");

		QSqlQuery query;				

		// Find the max ID +
		query.exec("SELECT max(ID) FROM Score_List");
		int nID = 0;
		while (query.next())
		{
			nID = query.value(0).toInt();
			qDebug() << QString("max ID:%1").arg(nID);
		}
		// Find the max ID +

		// Batch insert items to Score_List +
		query.prepare("INSERT INTO Score_List (ID, Name, Score) VALUES (?, ?, ?)");
		
		QVariantList IDList;
		IDList << nID + 1 << nID + 2 << nID + 3 << nID + 4;
		query.addBindValue(IDList);

		QVariantList nameList;
		nameList << "God" << "Shit" << "Good" << "Bad";
		query.addBindValue(nameList);

		QVariantList scoreList1;
		scoreList1 << 91 << 80 << 96 << 95;
		query.addBindValue(scoreList1);
		if (!query.execBatch()) {
			qDebug() << "INSERT Failed!";
		}

		QSqlDatabase::database().commit();
		// Batch insert items to Score_List -

		// Get scoreList from Score_List +
		query.exec("SELECT ID,Name,Score FROM Score_List");

		while (query.next())
		{
			int value0 = query.value(0).toInt();
			QString value1 = query.value(1).toString();
			int value2 = query.value(2).toInt();
			qDebug() << value0 << value1 << value2;

			SCORE_LIST tmpScoreList;

			tmpScoreList.nID = value0;
			tmpScoreList.strName = value1;
			tmpScoreList.nScore = value2;

			scoreList.push_back(tmpScoreList);
		}
		// Get scoreList from Score_List +

		// Get column and row number from Score_List +
		query.prepare("SELECT * FROM Score_List");
		query.exec();

		nCol = query.record().count();

		if (query.last())
		{
			nRow = query.at() + 1;
			query.first();
			query.previous();
		}
		// Get column and row number from Score_List -

		query.finish();

		// Get model from Score_List +
		pModel->setQuery("SELECT * FROM Score_List");
		pModel->setHeaderData(0, Qt::Horizontal, tr("ID"));
		pModel->setHeaderData(1, Qt::Horizontal, tr("Name"));
		pModel->setHeaderData(1, Qt::Horizontal, tr("Score"));
		// Get model from Score_List +

		db.close();
		return true;
	}
	else return false;
}