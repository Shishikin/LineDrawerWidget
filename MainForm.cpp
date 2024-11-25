#include <QtWidgets>
#include <QFileDialog>
#include <QFile>

#include <QString>
#include <string>
#include <sstream>

#include "MainForm.h"
#include "LineDrawerWidget.h"

void MainForm::OpenFile()
{
	// this нужен для модальности, но в этом случае окно будет модальным всегда 
	QString fileOpen = QFileDialog::getOpenFileName(this, "выбор файла для загрузки", "", "*.txt");
	QFile file{ fileOpen };
	
	// Проверяем, был ли выбран файл
	if (fileOpen.isEmpty()) {
		return; // Если нет, выходим из функции
	}
	// открытие файла
	file.open(QIODeviceBase::ReadOnly);

	// чтение данных из файла
	QTextStream in(&file);
	QString content = in.readAll();
	file.close();

	std::string contentSTD = content.toStdString();
	std::stringstream bufer(contentSTD);

	m_lineDrawerWidget->clearLines();

	std::string strPoint1X, strPoint1Y, strPoint2X, strPoint2Y;

	while (bufer >> strPoint1X >> strPoint1Y >> strPoint2X >> strPoint2Y)
	{
		QPointF firstPoint(std::stod(strPoint1X), std::stod(strPoint1Y));
		QPointF secondPoint(std::stod(strPoint2X), std::stod(strPoint2Y));
//		QPair<QPointF, QPointF> pair(firstPoint, secondPoint);
		m_lineDrawerWidget->lines.append(qMakePair(firstPoint, secondPoint));
	}
}


void MainForm::SaveFile()
{
	QString fileOpen = QFileDialog::getSaveFileName(this, "выбор файла для сохранения", "", "*.txt");


}

MainForm::MainForm(QWidget* parent) : QWidget(parent)
{
	pushButtonClear = new QPushButton("Очистить");	
	pushButtonSave = new QPushButton("Сохранить");
	pushButtonDownload = new QPushButton("Загрузить");
	m_lineDrawerWidget = new LineDrawerWidget;
	
	QHBoxLayout* buttonLayout = new QHBoxLayout;	
	buttonLayout->addWidget(pushButtonClear);
	buttonLayout->addWidget(pushButtonSave);
	buttonLayout->addWidget(pushButtonDownload);
	QVBoxLayout* mainLayout = new QVBoxLayout;
	mainLayout->addWidget(m_lineDrawerWidget, 1);
	mainLayout->addLayout(buttonLayout);
	setLayout(mainLayout);

	connect(pushButtonClear, &QPushButton::clicked, m_lineDrawerWidget, &LineDrawerWidget::clearLines);


	// используется лямбда так как getOpenFileName использует 7 параметров
	connect(pushButtonDownload, &QPushButton::clicked, this, &MainForm::OpenFile);

	connect(pushButtonSave, &QPushButton::clicked, this, &MainForm::SaveFile);
}
