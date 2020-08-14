#ifndef MAINWIDGET_H_
#define MAINWIDGET_H_

#include "qwidget.h"
#include "qobject.h"
class QTimer;
class QPushButton;

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    MainWidget();
    ~MainWidget();
private:
    int m_step;
    int m_direction;
    QPushButton* m_apply_button;
    QTimer* m_timer;
private slots:
    void ButtonClickedHandler();
    void TimeOutHandler();
private slots:
    void mousePressEvent(QMouseEvent* e);
};


#endif // !MAINWIDGET_H_
