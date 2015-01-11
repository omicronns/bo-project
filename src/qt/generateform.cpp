#include "generateform.h"
#include "ui_generateform.h"
#include "Problem.h"
#include <QFileDialog>
#include <fstream>

GenerateForm::GenerateForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GenerateForm),
    generated(false)
{
    ui->setupUi(this);
}

GenerateForm::~GenerateForm()
{
    delete ui;
}

void GenerateForm::setToolchain(Toolchain *tlc)
{
    toolchain = tlc;
}

void GenerateForm::setProblem(Problem *prb)
{
    problem = prb;
}

void GenerateForm::setRunButton(QPushButton *runBut)
{
    runButton = runBut;
}

bool GenerateForm::isGenerated()
{
    return generated;
}

void GenerateForm::generate(QAbstractButton *button)
{
    if(button != (QAbstractButton *)ui->buttons->button(QDialogButtonBox::Cancel)) {
        wp_count = ui->wp_count->value();
        tools_p_wp = ui->tools_p_wp->value();
        area_h = ui->area_h->value();
        area_w = ui->area_w->value();
    }
    if(button == (QAbstractButton *)ui->buttons->button(QDialogButtonBox::Save)) {
        QString problemFilename = QFileDialog::getSaveFileName();
        std::fstream problemFile(problemFilename.toStdString(), std::ios::out);
        problemFile << problem;
        problemFile.close();
        if(problem->getWorkpoints().size() != 0) {
            runButton->setEnabled(true);
        }
        else {
            runButton->setEnabled(false);
        }
    }
    if(button == (QAbstractButton *)ui->buttons->button(QDialogButtonBox::Ok)) {
        *problem = Problem(wp_count, tools_p_wp, *toolchain, area_w, area_h);
        runButton->setEnabled(true);
    }
}

