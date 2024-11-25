#ifndef MAINFORM
#define MAINFORM


#include <QWidget>
#include "LineDrawerWidget.h"
class QPushButton;

class MainForm : public QWidget
{
    Q_OBJECT

public:
  
    explicit MainForm(QWidget* parent = nullptr);

    

private:

    QPushButton* pushButtonClear{ nullptr };
    QPushButton* pushButtonSave{ nullptr };
    QPushButton* pushButtonDownload{ nullptr };
    LineDrawerWidget* m_lineDrawerWidget{ nullptr };

    void OpenFile();
    void SaveFile();
};

#endif
