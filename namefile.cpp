#include "namefile.h"
#include <QFont>
#include <QLayout>
#include <QCloseEvent>
#include <QMessageBox>
#include <QFileDialog>

NameFile::NameFile(QWidget *parent) :
    QWidget(parent)
{
    m_pathLabel = new QLabel(tr("Path: "));
    m_mainNameLabel = new QLabel(tr("MainName: "));
    m_pathLabel->setFont(QFont("Helvetica"));
    m_pathLabel->setAlignment(Qt::AlignRight);
    m_pathLabel->setFixedWidth(100);
    m_mainNameLabel->setFont(QFont("Helvetica"));
    m_mainNameLabel->setAlignment(Qt::AlignRight);
    m_mainNameLabel->setFixedWidth(100);
    m_nameFilterLabel = new QLabel(tr("Name Filter:"));
    m_nameFilterLabel->setFont(QFont("Helvetica"));
    m_nameFilterLabel->setAlignment(Qt::AlignRight);
    m_nameFilterLabel->setFixedWidth(70);

    m_pathInput = new QLineEdit;
    //m_pathInput->setFixedWidth(200);
    m_pathInput->setText("/");
    m_mainnameInput = new QLineEdit;
    //m_mainnameInput->setFixedWidth(200);
    m_nameFilterInput = new QLineEdit;
    //m_nameFilterInput->setFixedWidth(200);

    m_startButton = new QPushButton(tr("Start"));
    m_stopButton = new QPushButton(tr("Stop"));
    m_exitButton = new QPushButton(tr("Exit"));
    m_choosePathButton = new QPushButton(tr("..."));

    connect(m_startButton, SIGNAL(clicked()), this, SLOT(startNameThread()));
    connect(m_stopButton, SIGNAL(clicked()), this, SLOT(stopNameThread()));
    connect(m_exitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(m_choosePathButton, SIGNAL(clicked()), this, SLOT(chooseDir()));

    QHBoxLayout* pathLayout = new QHBoxLayout;
    pathLayout->addWidget(m_pathLabel);
    pathLayout->addWidget(m_pathInput);
    pathLayout->addWidget(m_choosePathButton);

    QHBoxLayout* mainNameLayout = new QHBoxLayout;
    mainNameLayout->addWidget(m_mainNameLabel);
    mainNameLayout->addWidget(m_mainnameInput);

    QHBoxLayout* nameFilterLayout = new QHBoxLayout;
    nameFilterLayout->addWidget(m_nameFilterLabel);
    nameFilterLayout->addWidget(m_nameFilterInput);

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch();
    buttonLayout->addWidget(m_startButton);
    buttonLayout->addStretch();
    buttonLayout->addWidget(m_stopButton);
    buttonLayout->addStretch();
    buttonLayout->addWidget(m_exitButton);
    buttonLayout->addStretch();

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(pathLayout);
    mainLayout->addLayout(mainNameLayout);
    mainLayout->addLayout(nameFilterLayout);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
}

void NameFile::closeEvent(QCloseEvent * event)
{
    m_namethread.stop();
    event->accept();
}

void NameFile::startNameThread()
{
    m_namethread.setMainName(m_mainnameInput->text());
    m_namethread.setPath(m_pathInput->text());
    if (!m_nameFilterInput->text().isEmpty())
    {
        m_namethread.setFilter(m_nameFilterInput->text());
    }

    m_namethread.start();
}

void NameFile::stopNameThread()
{
    m_namethread.stop();
}

void NameFile::chooseDir()
{
    QString dirPath = QFileDialog::getExistingDirectory(this, tr("choose Dir"),
                                                        m_pathInput->text(), QFileDialog::ShowDirsOnly);
    m_pathInput->setText(dirPath);
}
