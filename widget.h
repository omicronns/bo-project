#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

#include "QFileDialog"
#include "Toolchain.h"
#include "Problem.h"
#include "Solver.h"

class Widget : public QWidget
{
    Q_OBJECT

    Toolchain *toolchain;
    Problem *problem;

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void selectToolchain();
    void selectProblem();
    void run();
    void generate();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
