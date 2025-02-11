﻿#ifndef LINEDRAWERWIDGET_H
#define LINEDRAWERWIDGET_H

#include <QWidget>
#include <QPoint>
#include <QVector>

/**
 * @class LineDrawerWidget
 * @brief Виджет для рисования отрезков с использованием мыши.
 *
 * LineDrawerWidget позволяет пользователю рисовать отрезки, нажимая на левую кнопку мыши
 * для установки начальной точки и перемещая мышь, чтобы задать конечную точку. Отрезки
 * автоматически сохраняются при отпускании кнопки мыши, и все они хранятся в виджете.
 * Также предусмотрена возможность очистки всех отрезков по запросу.
 */
class LineDrawerWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор виджета LineDrawerWidget.
     * @param parent Указатель на родительский виджет.
     */
    explicit LineDrawerWidget(QWidget* parent = nullptr);

    /**
     * @brief Очищает все отрезки, сохраненные в виджете.
     *
     * Этот метод очищает вектор всех отрезков и вызывает перерисовку виджета,
     * удаляя все нарисованные линии.
     */
    void clearLines();

//    QVector<QPair<QPointF, QPointF>> lines;
    const int GetminWidth() const;
    const int GetminHeight() const;

    void PushBack(QPair<QPointF, QPointF>);
    const QVector<QPair<QPointF, QPointF>>& GetLines() const;

protected:
    /**
     * @brief Переопределенный метод для отрисовки виджета.
     *
     * Этот метод вызывается автоматически для перерисовки содержимого виджета,
     * что позволяет отображать все ранее нарисованные отрезки и текущий отрезок
     * (если идет его рисование).
     * @param event Событие отрисовки.
     */
    void paintEvent(QPaintEvent* event) override;


    /**
     * @brief Обрабатывает нажатие кнопки мыши.
     *
     * При нажатии левой кнопки мыши этот метод фиксирует начальную точку нового отрезка
     * и устанавливает флаг начала рисования.
     * @param event Событие нажатия кнопки мыши.
     */
    void mousePressEvent(QMouseEvent* event) override;

    /**
     * @brief Обрабатывает перемещение мыши.
     *
     * Этот метод обновляет конечную точку текущего отрезка во время перемещения мыши,
     * вызывая перерисовку для отображения изменяющегося отрезка.
     * @param event Событие перемещения мыши.
     */
    void mouseMoveEvent(QMouseEvent* event) override;

    /**
     * @brief Обрабатывает отпускание кнопки мыши.
     *
     * При отпускании левой кнопки мыши текущий отрезок добавляется в список сохраненных
     * отрезков, и виджет перерисовывается.
     * @param event Событие отпускания кнопки мыши.
     */
    void mouseReleaseEvent(QMouseEvent* event) override;

    
    

private:

    QVector<QPair<QPointF, QPointF>> lines;  // Вектор, хранящий пары начальных и конечных точек всех отрезков
    const int minWidth = 200;
    const int minHeight = 200;
    QPoint startPoint;                     // Начальная точка текущего отрезка
    QPoint endPoint;                       // Конечная точка текущего отрезка
    bool isDrawing;                        // Флаг, указывающий, что в данный момент идет рисование
    void resizeEvent(QResizeEvent* event) override;
};

#endif // LINEDRAWERWIDGET_H