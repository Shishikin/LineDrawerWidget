﻿#include "LineDrawerWidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

const int LineDrawerWidget::GetminWidth() const
{
    return minWidth;
}

const int LineDrawerWidget::GetminHeight() const
{
    return minHeight;
}

LineDrawerWidget::LineDrawerWidget(QWidget* parent)
    : QWidget(parent), isDrawing(false)  // Инициализация виджета и установка флага isDrawing в false
{
    setMinimumSize(minWidth, minHeight); // Устанавливаем минимальный размер
}

// Очищает все отрезки и обновляет виджет для перерисовки
void LineDrawerWidget::clearLines()
{
    lines.clear();  // Очищаем вектор отрезков
    update();       // Запрашиваем перерисовку виджета
}

void LineDrawerWidget::PushBack(QPair<QPointF, QPointF> pair)
{
    lines.push_back(pair);
}

const QVector<QPair<QPointF, QPointF>>& LineDrawerWidget::GetLines() const
{
    return lines;
}

// Метод отрисовки, вызываемый при необходимости перерисовать виджет
void LineDrawerWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.fillRect(0, 0, size().width(), size().height(), QColor(205, 205, 205));
    painter.setPen(Qt::black);  // Устанавливаем черный цвет для рисования линий

    // Отрисовываем все сохраненные отрезки
    for (const auto& line : lines)
    {
        painter.drawLine(line.first, line.second);  // Рисуем отрезок от начальной до конечной точки
    }
    if (isDrawing)
    {
        painter.drawLine(startPoint, endPoint);
    }

}

// Обрабатывает нажатие левой кнопки мыши
void LineDrawerWidget::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)  // Проверяем, что нажата именно левая кнопка
    {
        startPoint = event->pos();  // Устанавливаем начальную точку в текущую позицию мыши
        endPoint = startPoint;      // Инициализируем конечную точку как начальную
        isDrawing = true;           // Устанавливаем флаг, что идет рисование
    }
}

// Обрабатывает перемещение мыши с зажатой кнопкой
void LineDrawerWidget::mouseMoveEvent(QMouseEvent* event)
{
    if (isDrawing)  // Если идет рисование
    {
        endPoint = event->pos();  // Обновляем конечную точку в текущую позицию мыши
        update();                 // Запрашиваем перерисовку виджета
    }
}

// Обрабатывает отпускание левой кнопки мыши
void LineDrawerWidget::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)  // Если отпущена левая кнопка и идет рисование
    {
        endPoint = event->pos();  // Фиксируем конечную точку
        lines.append(qMakePair(startPoint, endPoint));  // Сохраняем текущий отрезок в список
        isDrawing = false;  // Сбрасываем флаг рисования
        update();           // Запрашиваем перерисовку виджета для отображения нового отрезка
    }
}

// метод вызываемый при изменении объекта размера
void LineDrawerWidget::resizeEvent(QResizeEvent* event) 
{
    QSize oldSize = event->oldSize();
    QSize newSize = event->size();

    if (oldSize.isValid()) 
    {
        float scaleX = float(newSize.width()) / oldSize.width();
        float scaleY = float(newSize.height()) / oldSize.height();

        // Масштабируем все линии
        for (auto& line : lines) 
        {
            qDebug() << QString::fromUtf8("Старая точка:") << line.first << " scaleX:" << scaleX << " scaleY:" << scaleY;
            line.first.setX(line.first.x() * scaleX);
            line.first.setY(line.first.y() * scaleY);
            qDebug() << QString::fromUtf8("Новая точка:") << line.first;
            qDebug() << QString::fromUtf8("Старая точка:") << line.second << " scaleX:" << scaleX << " scaleY:" << scaleY;
            line.second.setX(line.second.x() * scaleX);
            line.second.setY(line.second.y() * scaleY);
            qDebug() << QString::fromUtf8("Новая точка:") << line.second;
        }
    }
    update(); // Перерисовка после изменения размеров
}
