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
#include "Tool.h"
#include "generateform.h"
#include <qcustomplot.h>

class Widget : public QWidget
{
    Q_OBJECT

    Toolchain toolchain;
    Problem problem;
    QString toolchainFilename;
    QString problemFilename;
    GenerateForm gen;

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    //static QString toolchainFilename;
    //static QString problemFilename;

public slots:
    void selectToolchain();
    void selectProblem();
    void run();
    void generate();

private slots:
    void on_comboBox_2_currentIndexChanged(int index);
    void mouseDoubleClick();
    void setStatusLabel();

private:
    Ui::Widget *ui;
    void initCombo_box() const;
    void plotGraph(std::vector<double> &x, std::vector<double> &y);
    void plotStatGraphs(const std::vector<double> &y);
    std::vector<double> computeTemperatureAmplitude(const std::vector<double> &y);
    std::vector<double> computeTemperatureProgress(const std::vector<double> &y);
};

#endif // WIDGET_H
