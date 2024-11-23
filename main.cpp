#include <QtWidgets>
#include "LineDrawerWidget.h"
#include "MainForm.h"

#ifdef WIN32
#include <windows.h>
#endif

int main(int argc, char** argv)
{
#ifdef WIN32
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
#endif


	// создать приложение
	QApplication app(argc, argv);


    // выбрать стиль приложение универсальный, чтобы можно было работать на линуксе
	app.setStyle(QStyleFactory::create("Fusion"));
	// задать имя приложению
	app.setApplicationName("приложение для рисования отрезков");


	MainForm* mainForm = new MainForm;
	mainForm->show();

//	QLabel* label = new QLabel(nullptr);
//	label->show();

	return app.exec();
}