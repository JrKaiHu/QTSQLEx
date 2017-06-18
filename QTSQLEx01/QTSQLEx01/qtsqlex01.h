#ifndef QTSQLEX01_H
#define QTSQLEX01_H

#include <QtWidgets/QMainWindow>
#include <QSqlQueryModel>
#include "ui_qtsqlex01.h"

#include <vector>
#include <list>

using namespace std;

typedef struct ScoreListPara
{
	int nID;
	QString strName;
	int nScore;
}
SCORE_LIST,*PSCORE_LIST;

class QTSQLEx01 : public QMainWindow
{
	Q_OBJECT

public:
	QTSQLEx01(QWidget *parent = 0);
	~QTSQLEx01();

private:
	Ui::QTSQLEx01Class ui;
	bool DBConnection(QStringList &citylist, int &nCol, int &nRow, list <SCORE_LIST> &scoreList, QSqlQueryModel *pModel);
};

#endif // QTSQLEX01_H
