#include "main_widget.h"
#include "qpushbutton.h"
#include "qlayout.h"
#include "qevent.h"
#include "qtimer.h"
#include "qcursor.h"
#include "qscreen.h"
#include "qguiapplication.h"

#pragma execution_character_set("utf-8");

MainWidget::MainWidget()
          : m_step(1)
          , m_direction(1)
{
    this->setFixedSize(QSize(800, 200));
    QHBoxLayout* main_layout = new QHBoxLayout();
    m_apply_button = new QPushButton(tr("动起来！！"));
    main_layout->addWidget(m_apply_button);
    this->setLayout(main_layout);
    m_timer = new QTimer();
    connect(m_apply_button, SIGNAL(clicked()), this, SLOT(ButtonClickedHandler()));
    connect(m_timer, SIGNAL(timeout()), this, SLOT(TimeOutHandler()));
}

MainWidget::~MainWidget()
{
    m_timer->stop();
}

void MainWidget::ButtonClickedHandler()
{
    m_apply_button->setText(tr("停下来呀！鼠标右键！"));
    m_timer->start(100);
}

void MainWidget::TimeOutHandler()
{

    QScreen *screen = QGuiApplication::primaryScreen();
    QCursor *cursor = new QCursor();
    int width = this->geometry().width();
    int move_x = this->pos().x() + m_step;
    m_step += m_direction;
    int move_y = this->pos().y();
    cursor->setPos(screen, move_x, move_y + 100);

    if (move_x < pos().x() - 100) {
        m_direction = 1;
    }

    if (move_x > pos().x() + width + 100) {
        m_direction = -1;
    }
}

void MainWidget::mousePressEvent(QMouseEvent* e)
{
    if (e->button() == Qt::RightButton) {
        m_apply_button->setText(tr("动起来呀！！"));
        m_timer->stop();
    }
}