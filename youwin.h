#ifndef YOUWIN_H
#define YOUWIN_H

#include <QDialog>

namespace Ui {
class youwin;
}

class youwin : public QDialog
{
    Q_OBJECT

public:
    explicit youwin(QWidget *parent = nullptr);
    ~youwin();

private:
    Ui::youwin *ui;
};

#endif // YOUWIN_H
