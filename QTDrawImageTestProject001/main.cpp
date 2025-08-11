#include "QTDrawImageTestProject001.h"
#include <QtWidgets/QApplication>
#include <QFile>
#include <QApplication>
#include <QDesktopWidget>


bool LoadStyleFile(QApplication* pApp, const QString& strFile)
{
	QFile file(strFile);
	if (file.open(QFile::ReadOnly))
	{
		pApp->setStyleSheet(file.readAll());
		file.close();
		return true;
	}
	return false;
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	LoadStyleFile(&a, "DarkgreenC602.qss");
	QTDrawImageTestProject001 w;
	w.setFixedWidth(800);
	int nDesktopWidth = QApplication::desktop()->width();
	w.move(((nDesktopWidth > 1920 ? 1920 : nDesktopWidth) - w.width()) / 2, 0);
    w.show();
    return a.exec();
}
