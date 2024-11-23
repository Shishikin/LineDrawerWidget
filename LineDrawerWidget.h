#ifndef LINEDRAWERWIDGET_H
#define LINEDRAWERWIDGET_H

#include <QWidget>
#include <QPoint>
#include <QVector>

/**
 * @class LineDrawerWidget
 * @brief ������ ��� ��������� �������� � �������������� ����.
 *
 * LineDrawerWidget ��������� ������������ �������� �������, ������� �� ����� ������ ����
 * ��� ��������� ��������� ����� � ��������� ����, ����� ������ �������� �����. �������
 * ������������� ����������� ��� ���������� ������ ����, � ��� ��� �������� � �������.
 * ����� ������������� ����������� ������� ���� �������� �� �������.
 */
class LineDrawerWidget : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief ����������� ������� LineDrawerWidget.
     * @param parent ��������� �� ������������ ������.
     */
    explicit LineDrawerWidget(QWidget* parent = nullptr);

    /**
     * @brief ������� ��� �������, ����������� � �������.
     *
     * ���� ����� ������� ������ ���� �������� � �������� ����������� �������,
     * ������ ��� ������������ �����.
     */
    void clearLines();

protected:
    /**
     * @brief ���������������� ����� ��� ��������� �������.
     *
     * ���� ����� ���������� ������������� ��� ����������� ����������� �������,
     * ��� ��������� ���������� ��� ����� ������������ ������� � ������� �������
     * (���� ���� ��� ���������).
     * @param event ������� ���������.
     */
    void paintEvent(QPaintEvent* event) override;


    /**
     * @brief ������������ ������� ������ ����.
     *
     * ��� ������� ����� ������ ���� ���� ����� ��������� ��������� ����� ������ �������
     * � ������������� ���� ������ ���������.
     * @param event ������� ������� ������ ����.
     */
    void mousePressEvent(QMouseEvent* event) override;

    /**
     * @brief ������������ ����������� ����.
     *
     * ���� ����� ��������� �������� ����� �������� ������� �� ����� ����������� ����,
     * ������� ����������� ��� ����������� ������������� �������.
     * @param event ������� ����������� ����.
     */
    void mouseMoveEvent(QMouseEvent* event) override;

    /**
     * @brief ������������ ���������� ������ ����.
     *
     * ��� ���������� ����� ������ ���� ������� ������� ����������� � ������ �����������
     * ��������, � ������ ����������������.
     * @param event ������� ���������� ������ ����.
     */
    void mouseReleaseEvent(QMouseEvent* event) override;

private:

    QVector<QPair<QPoint, QPoint>> lines;  // ������, �������� ���� ��������� � �������� ����� ���� ��������
    QPoint startPoint;                     // ��������� ����� �������� �������
    QPoint endPoint;                       // �������� ����� �������� �������
    bool isDrawing;                        // ����, �����������, ��� � ������ ������ ���� ���������

};

#endif // LINEDRAWERWIDGET_H