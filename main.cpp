#include <QtWidgets>
#include "LineDrawerWidget.h"
#include "MainForm.h"


int main(int argc, char** argv)
{
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