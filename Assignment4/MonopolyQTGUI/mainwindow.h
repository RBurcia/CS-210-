#pragma once
#include <QMainWindow>
#include <QVector>
#include "game.h"

class QLabel;
class QPushButton;
class QTextEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void onRoll();
    void onBuy();
    void onEndTurn();

private:
    void buildUi();
    void refresh();

    Game game_;
    QVector<QLabel*> tiles_;
    QLabel* status_ = nullptr;
    QPushButton* rollBtn_ = nullptr;
    QPushButton* buyBtn_ = nullptr;
    QPushButton* endBtn_ = nullptr;
    QTextEdit* log_ = nullptr;
};