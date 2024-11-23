#include "LineDrawerWidget.h"
#include <QPainter>
#include <QMouseEvent>

LineDrawerWidget::LineDrawerWidget(QWidget* parent)
    : QWidget(parent), isDrawing(false)  // ������������� ������� � ��������� ����� isDrawing � false
{
}

// ������� ��� ������� � ��������� ������ ��� �����������
void LineDrawerWidget::clearLines()
{
    lines.clear();  // ������� ������ ��������
    update();       // ����������� ����������� �������
}

// ����� ���������, ���������� ��� ������������� ������������ ������
void LineDrawerWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.fillRect(0, 0, size().width(), size().height(), QColor(205, 205, 205));
    painter.setPen(Qt::black);  // ������������� ������ ���� ��� ��������� �����

    // ������������ ��� ����������� �������
    for (const auto& line : lines)
    {
        painter.drawLine(line.first, line.second);  // ������ ������� �� ��������� �� �������� �����
    }
    if (isDrawing)
    {
        painter.drawLine(startPoint, endPoint);
    }

}




// ������������ ������� ����� ������ ����
void LineDrawerWidget::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)  // ���������, ��� ������ ������ ����� ������
    {
        startPoint = event->pos();  // ������������� ��������� ����� � ������� ������� ����
        endPoint = startPoint;      // �������������� �������� ����� ��� ���������
        isDrawing = true;           // ������������� ����, ��� ���� ���������
    }
}

// ������������ ����������� ���� � ������� �������
void LineDrawerWidget::mouseMoveEvent(QMouseEvent* event)
{
    if (isDrawing)  // ���� ���� ���������
    {
        endPoint = event->pos();  // ��������� �������� ����� � ������� ������� ����
        update();                 // ����������� ����������� �������
    }
}

// ������������ ���������� ����� ������ ����
void LineDrawerWidget::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)  // ���� �������� ����� ������ � ���� ���������
    {
        endPoint = event->pos();  // ��������� �������� �����
        lines.append(qMakePair(startPoint, endPoint));  // ��������� ������� ������� � ������
        isDrawing = false;  // ���������� ���� ���������
        update();           // ����������� ����������� ������� ��� ����������� ������ �������
    }
}
