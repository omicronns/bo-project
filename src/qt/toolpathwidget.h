#ifndef TOOLPATHWIDGET_H
#define TOOLPATHWIDGET_H

#include <QWidget>
#include "globalvariables.h"
#include "Tool.h"

class ToolPathWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ToolPathWidget(QWidget *parent = 0);
    void setCurrentTool(int i);

private:
    int currentTool;
    const std::vector<Tool> & toolchain = GUIDataObject.getToolchain();
    const std::vector<int> & solution = GUIDataObject.getSolution();
    std::vector<Point> scaledCoordinates;

    void scaleCoordinates(const std::vector<Workpoint> & workpoint);
    void printPoints(QPainter * painter);
    void printLines(QPainter * painter, std::vector<Workpoint> & workpoint, int toolIndex);

protected:
    void paintEvent(QPaintEvent *event);

};

#endif // TOOLPATHWIDGET_H
