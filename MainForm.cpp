#include <QtWidgets>
#include "MainForm.h"
#include "LineDrawerWidget.h"

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


}
