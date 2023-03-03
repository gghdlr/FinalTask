#include "finddialog.h"
#include <QtGui>
FindDialog::FindDialog(QWidget *parent) :
    QDialog(parent)
{
    label = new QLabel(tr("Find &what: "));
    lineEdit = new QLineEdit();
    label->setBuddy(lineEdit);

    caseCheckBox  = new QCheckBox(tr("Match &case"));
    backwordCheckBox = new QCheckBox(tr("Search backwards"));

    findButton = new QPushButton(tr("&Find"));
    findButton->setDefault(true);
    findButton->setEnabled(false);

    closeButton = new QPushButton(tr("Close"));

    connect(lineEdit, SIGNAL(textChanged(QString)), this, SLOT(enabledFindButton(const QString &)));
    connect(findButton, SIGNAL(clicked()), this, SLOT(findClicked()));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

    QHBoxLayout *topLeftLayout  = new QHBoxLayout;
    topLeftLayout-> addWidget(label);
    topLeftLayout-> addWidget(lineEdit);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwordCheckBox);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(closeButton);

     QHBoxLayout *mainLayout = new QHBoxLayout;
     mainLayout->addLayout(leftLayout);
     mainLayout->addLayout(rightLayout);
     setLayout(mainLayout);

     setWindowTitle(tr("Find Dialog"));
     setFixedHeight(sizeHint().height());
}
void FindDialog::findClicked(){
    QString text = lineEdit->text();
    Qt::CaseSensitivity cs = caseCheckBox->isChecked() ? Qt::CaseSensitive
                                                        :Qt::CaseInsensitive;
    if(backwordCheckBox->isChecked()){
        emit findPrev(text, cs);
    }else {
        emit findNext(text, cs);
    }
}
void FindDialog::enabledFindButton(const QString &text){
    findButton->setEnabled(!text.isEmpty());
}

