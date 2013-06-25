#ifndef NAMEFILE_H
#define NAMEFILE_H

#include <QWidget>
#include <QLabel>
#include <QRadioButton>
#include <QLineEdit>
#include <QProgressBar>
#include <QPushButton>
#include "namethread.h"
#include <QEvent>

class NameFile : public QWidget
{
    Q_OBJECT
private:
    QLabel* m_pathLabel;
    QLabel* m_mainNameLabel;
    QLabel* m_nameFilterLabel;
    QLineEdit* m_pathInput;
    QLineEdit* m_mainnameInput;
    QLineEdit* m_nameFilterInput;


    //QProgressBar* m_nameProgressBar;
    QPushButton* m_startButton;
    QPushButton* m_stopButton;
    QPushButton* m_exitButton;
    QPushButton* m_choosePathButton;
    NameThread m_namethread;
protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void startNameThread();
    void stopNameThread();
    void chooseDir();
public:
    NameFile(QWidget* parent = 0);


};

#endif // NAMEFILE_H
