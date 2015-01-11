#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QString>
#include <fstream>
#include <list>
#include <vector>
#include "generateform.h"
#include "Solver.h"
#include "globalvariables.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    gen(this)
{
    ui->setupUi(this);

    this->setWindowTitle("Matematyczne Metody Wspomagania Decyzji");
    ui->tabWidget->setTabText(0, "setup");
    ui->tabWidget->setTabText(1, "stat");
    ui->tabWidget->setTabText(2, "route");

    connect(ui->plot, SIGNAL(mouseDoubleClick(QMouseEvent*)), this, SLOT(mouseDoubleClick()));
    connect(ui->run, SIGNAL(pressed()), this, SLOT(setStatusLabel()));
    ui->label_status->setText("Ready");
    gen.setToolchain(&toolchain);
    gen.setProblem(&problem);
    gen.setRunButton(ui->run);
}

void Widget::setStatusLabel() {
    ui->label_status->setText("Computing...");
}

void Widget::mouseDoubleClick() {
    ui->plot->rescaleAxes();
}

Widget::~Widget()
{
    delete ui;
}

//QString Widget::toolchainFilename = "/home/bszmit/IT/C++/MMWD/wejsciowe/toolchain";
//QString Widget::problemFilename = "/home/bszmit/IT/C++/MMWD/wejsciowe/problem";

void Widget::selectToolchain()
{
    QString toolchainFilename = QFileDialog::getOpenFileName();
    std::fstream toolchainFile(toolchainFilename.toStdString(), std::ios::in);
    if(toolchainFile.is_open()) {
        toolchainFile >> toolchain;
        toolchainFile.close();
    }
    if(toolchain.getToolsCount() != 0) {
        ui->problem->setEnabled(true);
        ui->gen->setEnabled(true);
    }
    else {
        ui->problem->setEnabled(false);
        ui->gen->setEnabled(false);
        ui->run->setEnabled(false);
    }

    GUIDataObject.clear(GUIData::toolchainEnum);
    GUIDataObject.setToolchain(toolchain.getToolChain());
}

void Widget::selectProblem()
{
    problem.setToolchain(toolchain);
    QString problemFilename = QFileDialog::getOpenFileName();
    std::fstream problemFile(problemFilename.toStdString(), std::ios::in);
    if(problemFile.is_open()) {
        problemFile >> problem;
        problemFile.close();
    }
    if(problem.getWorkpoints().size() != 0) {
        ui->run->setEnabled(true);
    }
    else {
        ui->run->setEnabled(false);
    }

    GUIDataObject.clear(GUIData::workointsEnum);
    GUIDataObject.setWorkpoints(problem.getWorkpoints());
}

void Widget::run()
{
    Solver slv(problem);
    std::list<double> costs;
    double cost = slv.solve(ui->initTemp->value(), ui->endTemp->value(), ui->alpha->value(), ui->beta->value(), ui->gamma->value(), ui->iterations->value(), costs);
    ui->cost->setValue(cost);
    std::vector<double> y{ std::begin(costs), std::end(costs) };
    std::list<double> xl;
    for(int i = 0; i < y.size(); ++i) {
        xl.push_back(i);
    }
    std::vector<double> x{ std::begin(xl), std::end(xl) };

    plotGraph(x, y);
    plotStatGraphs(y);

    GUIDataObject.clear(GUIData::solutionEnum);
    GUIDataObject.setSolution(slv.getSolution());
    initCombo_box();

    ui->label_status->setText("Done");
}

void Widget::plotGraph(std::vector<double> & x, std::vector<double> & y) {
    auto customPlot = ui->plot;
    customPlot->plotLayout()->clear();
    customPlot->clearGraphs();

    QColor temperatureColor = Qt::red;
    QColor objectiveFunctionColor = Qt::blue;
    QCPAxisRect *wideAxisRect = new QCPAxisRect(customPlot);
    wideAxisRect->addAxis(QCPAxis::atLeft);

    wideAxisRect->axis(QCPAxis::atLeft, 0)->setTickLabelColor(objectiveFunctionColor);
    wideAxisRect->axis(QCPAxis::atLeft, 1)->setTickLabelColor(temperatureColor);

    customPlot->plotLayout()->addElement(0, 0, wideAxisRect); // insert axis rect in first row

    QCPGraph *objectiveFunctionGraph = customPlot->addGraph(wideAxisRect->axis(QCPAxis::atBottom), wideAxisRect->axis(QCPAxis::atLeft));
    objectiveFunctionGraph->setData(QVector<double>::fromStdVector(x), QVector<double>::fromStdVector(y));
    objectiveFunctionGraph->setPen(QPen(objectiveFunctionColor, 2));
    objectiveFunctionGraph->setBrush(QColor(255, 161, 0, 50));
    objectiveFunctionGraph->setName("objective function");

    QCPGraph *temperatureGraph = customPlot->addGraph(wideAxisRect->axis(QCPAxis::atBottom), wideAxisRect->axis(QCPAxis::atLeft, 1));
    temperatureGraph->setData(QVector<double>::fromStdVector(x), QVector<double>::fromStdVector(GUIDataObject.getTemperature()));
    temperatureGraph->setPen(QPen(temperatureColor, 2));
    temperatureGraph->setName("temperature");

    QCPLegend *myLegend = new QCPLegend;
    wideAxisRect->insetLayout()->addElement(myLegend, Qt::AlignTop | Qt::AlignRight);
    myLegend->setLayer("legend");
    customPlot->setAutoAddPlottableToLegend(false);

    myLegend->addItem(new QCPPlottableLegendItem(myLegend, objectiveFunctionGraph));
    myLegend->addItem(new QCPPlottableLegendItem(myLegend, temperatureGraph));

    objectiveFunctionGraph->rescaleAxes();
    temperatureGraph->rescaleAxes();
    wideAxisRect->axis(QCPAxis::atLeft, 1)->setRangeLower(0);

    wideAxisRect->axis(QCPAxis::atBottom, 0)->setLabel("iteration");

    customPlot->replot();

    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

void Widget::initCombo_box() const {
    ui->comboBox_2->clear();
    auto & v = GUIDataObject.getToolchain();
    for (auto it = v.begin(); it != v.end(); ++it) {
        QString x = QString::fromStdString((*it).getToolName());
        ui->comboBox_2->addItem(x);
    }
}

void Widget::on_comboBox_2_currentIndexChanged(int index) {
    ui->widget->setCurrentTool(index);
    ui->widget->update();
}

std::vector<double> Widget::computeTemperatureAmplitude(const std::vector<double> &y) {
    auto &temperature = GUIDataObject.getTemperature();
    std::vector<double> temperatureAmplitude;

    auto lastTemperature = *(temperature.begin());
    double minVal, maxVal;
    minVal = maxVal = *(y.begin());

    for (int i = 0; i < temperature.size(); i++) {
        double currentVal = y[i];
        if (lastTemperature == temperature[i]) {
            if (currentVal < minVal) minVal = currentVal;
            if (currentVal > maxVal) maxVal = currentVal;
        } else {
            temperatureAmplitude.push_back(maxVal - minVal);
            minVal = maxVal = y[i];
        }
        lastTemperature = temperature[i];
        if (i == temperature.size() - 1)
            temperatureAmplitude.push_back(maxVal - minVal);
    }
    return temperatureAmplitude;
}

std::vector<double> Widget::computeTemperatureProgress(const std::vector<double> &y) {
    auto &temperature = GUIDataObject.getTemperature();
    std::vector<double> temperatureProgress;
    double startVal, stopVal;

    auto lastTemp = temperature[0];
    startVal = y[0];

    for (int i = 1; i < temperature.size(); i++) {
        if ( lastTemp != temperature[i]) {
            stopVal = y[i-1];
            temperatureProgress.push_back(startVal - stopVal);
            startVal = y[i];
        }
        if (i == temperature.size() - 1) {
            stopVal = y[i];
            temperatureProgress.push_back(startVal - stopVal);
        }
        lastTemp = temperature[i];
    }
    return temperatureProgress;
}

void Widget::plotStatGraphs(const std::vector<double> &y) {
    auto temperatureAmplitude = computeTemperatureAmplitude(y);
    auto temperatureProgress = computeTemperatureProgress(y);

    std::vector<double> x;
    for (int i = 1; i <= temperatureAmplitude.size(); i++)
        x.push_back(i);


    auto customPlot = ui->widget_2;

    customPlot->plotLayout()->clear();
    customPlot->clearGraphs();

    QCPLayoutGrid *subLayout = new QCPLayoutGrid;
    customPlot->plotLayout()->addElement(0, 0, subLayout);

    QCPAxisRect *subRectLeft = new QCPAxisRect(customPlot, false);
    QCPAxisRect *subRectRight = new QCPAxisRect(customPlot, false);
    subLayout->addElement(0, 0, subRectLeft);
    subLayout->addElement(0, 1, subRectRight);

    subRectLeft->addAxes(QCPAxis::atBottom | QCPAxis::atLeft);
    subRectRight->addAxes(QCPAxis::atBottom | QCPAxis::atRight);

    subRectLeft->axis(QCPAxis::atLeft)->grid()->setVisible(true);
    subRectRight->axis(QCPAxis::atRight)->grid()->setVisible(true);

    QCPMarginGroup *marginGroup = new QCPMarginGroup(customPlot);
    subRectLeft->setMarginGroup(QCP::msLeft, marginGroup);
    subRectRight->setMarginGroup(QCP::msRight, marginGroup);


    foreach (QCPAxisRect *rect, customPlot->axisRects())
    {
      foreach (QCPAxis *axis, rect->axes())
      {
        axis->setLayer("axes");
        axis->grid()->setLayer("grid");
      }
    }

    QCPBars *bars1 = new QCPBars(subRectLeft->axis(QCPAxis::atBottom), subRectLeft->axis(QCPAxis::atLeft));
    customPlot->addPlottable(bars1);
    bars1->setWidth(3/(double)x.size());
    bars1->setData(QVector<double>::fromStdVector(x), QVector<double>::fromStdVector(temperatureProgress));
    bars1->setPen(QPen(Qt::magenta));
    bars1->setAntialiased(false);
    bars1->setAntialiasedFill(false);
    bars1->setBrush(QBrush(Qt::magenta));

    QCPBars *bars2 = new QCPBars(subRectRight->axis(QCPAxis::atBottom), subRectRight->axis(QCPAxis::atRight));
    customPlot->addPlottable(bars2);
    bars2->setWidth(3/(double)x.size());
    bars2->setData(QVector<double>::fromStdVector(x), QVector<double>::fromStdVector(temperatureAmplitude));
    bars2->setPen(QColor("#705BE8"));
    bars2->setAntialiased(false);
    bars2->setAntialiasedFill(false);
    bars2->setBrush(QColor("#705BE8"));

    subLayout->insertRow(0);
    subLayout->addElement(0, 0, new QCPPlotTitle(customPlot, "Progress for given temperature:"));
    subLayout->addElement(0, 1, new QCPPlotTitle(customPlot, "Amplitude for given temperature:"));

    subRectLeft->axis(QCPAxis::atLeft, 0)->setLabel("objective function progress");
    subRectLeft->axis(QCPAxis::atBottom, 0)->setLabel("succeeding temperature drops");

    subRectRight->axis(QCPAxis::atRight, 0)->setLabel("objective function amplitude");
    subRectRight->axis(QCPAxis::atBottom, 0)->setLabel("succeeding temperature drops");

    bars1->rescaleAxes();
    bars2->rescaleAxes();
    customPlot->replot();
}


void Widget::generate() {
    gen.show();
}
