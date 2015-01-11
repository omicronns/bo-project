#ifndef GENERATEFORM_H
#define GENERATEFORM_H

#include <QDialog>
#include <QAbstractButton>
#include "Toolchain.h"
#include "Problem.h"
#include <QPushButton>


namespace Ui {
class GenerateForm;
}

class GenerateForm : public QDialog
{
    Q_OBJECT
    Toolchain *toolchain;
    Problem *problem;
    int wp_count;
    int tools_p_wp;
    double area_h;
    double area_w;
    bool generated;
    QPushButton *runButton;

public:
    explicit GenerateForm(QWidget *parent = 0);
    ~GenerateForm();
    void setToolchain(Toolchain *tlc);
    void setProblem(Problem *prb);
    void setRunButton(QPushButton *runBut);
    bool isGenerated(void);

private:
    Ui::GenerateForm *ui;

private slots:
    void generate(QAbstractButton *button);
};

#endif // GENERATEFORM_H
