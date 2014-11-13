#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QString>
#include <fstream>
#include <list>
#include <vector>
#include "Solver.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::selectToolchain()
{
    Toolchain tlc;
    QString toolchainFilename = QFileDialog::getOpenFileName();
    std::fstream toolchainFile(toolchainFilename.toStdString(), std::ios::in);
    if(toolchainFile.is_open())
        toolchainFile >> tlc;
    if(tlc.getToolsCount() != 0) {
        ui->problem->setEnabled(true);
        ui->gen->setEnabled(true);
    }
    else {
        ui->problem->setEnabled(false);
        ui->gen->setEnabled(false);
        ui->run->setEnabled(false);
    }
    toolchain = new Toolchain(tlc);
}

void Widget::selectProblem()
{
    Problem pr(*toolchain);
    QString problemFilename = QFileDialog::getOpenFileName();
    std::fstream problemFile(problemFilename.toStdString(), std::ios::in);
    if(problemFile.is_open())
        problemFile >> pr;
    if(pr.getWorkpoints().size() != 0) {
        ui->run->setEnabled(true);
    }
    else {
        ui->run->setEnabled(false);
    }
    problem = new Problem(pr);
}

void Widget::run()
{
    Solver slv(*problem);
    std::list<double> costs;
    double cost = slv.solve(ui->initTemp->value(), ui->endTemp->value(), ui->alpha->value(), ui->beta->value(), ui->gamma->value(), ui->iterations->value(), costs);
    ui->cost->setValue(cost);
    std::vector<double> y{ std::begin(costs), std::end(costs) };
    std::list<double> xl;
    for(int i = 0; i < y.size(); ++i) {
        xl.push_back(i);
    }
    std::vector<double> x{ std::begin(xl), std::end(xl) };
    ui->plot->addGraph();
    ui->plot->graph(0)->setData(QVector<double>::fromStdVector(x), QVector<double>::fromStdVector(y));
    ui->plot->xAxis->setRange(0, x.size());
    ui->plot->yAxis->setRange(0, y[0] + y[0]*0.1);
    ui->plot->replot();
}

void Widget::generate()
{
    //TODO: add generation of random problems
}
